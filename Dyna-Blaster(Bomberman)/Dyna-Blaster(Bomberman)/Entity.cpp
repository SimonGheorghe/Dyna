#include "Entity.h"

void Entity::SetPosition(const float x, const float y)
{
	m_sprite.setPosition(x, y);
}

void Entity::Render(sf::RenderTarget& target)
{
	target.draw(m_sprite);
}
