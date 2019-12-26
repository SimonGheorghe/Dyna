#include "Entity2.h"

void Entity2::initVariables()
{
	m_movementComponent = NULL;
}

Entity2::Entity2()
{
	initVariables();
}

Entity2::~Entity2()
{
	delete m_movementComponent;
	delete m_animationComponent;
} 

void Entity2::SetTexture(sf::Texture& texture)
{
	m_sprite.setTexture(texture);
}

void Entity2::CreateMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	m_movementComponent = new MovementComponent(m_sprite, maxVelocity, acceleration, deceleration);
}

void Entity2::CreateAnimationComponent(sf::Texture& textureSheet)
{
	m_animationComponent = new AnimationComponent(m_sprite, textureSheet);
}

void Entity2::SetPosition(const float x, const float y)
{
	m_sprite.setPosition(x, y);
}

void Entity2::move(const float dir_x, const float dir_y, const float& dt)
{
	if (m_movementComponent)
	{
		m_movementComponent->move(dir_x, dir_y, dt);
	}
}

void Entity2::Update(const float& dt)
{

}

void Entity2::Render(sf::RenderTarget* target)
{
	target->draw(m_sprite);
}
