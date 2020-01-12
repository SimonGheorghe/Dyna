#include "HitboxComponent.h"

HitboxComponent::HitboxComponent(sf::Sprite& sprite,
	float offset_x, float offset_y,
	float width, float height)
	: m_sprite(sprite), m_offsetX(offset_x), m_offsetY(offset_y)
{
	m_hitbox.setPosition(m_sprite.getPosition().x + offset_x, m_sprite.getPosition().y + offset_y);
	m_hitbox.setSize(sf::Vector2f(width, height));
	m_hitbox.setFillColor(sf::Color::Transparent);
	m_hitbox.setOutlineThickness(1.f);
	m_hitbox.setOutlineColor(sf::Color::Green);
}

HitboxComponent::~HitboxComponent()
{
}

bool HitboxComponent::CheckIntersect(const sf::FloatRect& frect)
{
	return m_hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::Update()
{
	m_hitbox.setPosition(m_sprite.getPosition().x + m_offsetX, m_sprite.getPosition().y + m_offsetY);
}

void HitboxComponent::Render(sf::RenderTarget& target)
{
	target.draw(m_hitbox);
}
