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
} 

void Entity2::SetTexture(sf::Texture& texture)
{
	m_sprite.setTexture(texture);
}

void Entity2::CreateMovementComponent(const float maxVelocity)
{
	m_movementComponent = new MovementComponent(m_sprite, maxVelocity);
}

void Entity2::SetPosition(const float x, const float y)
{
	m_sprite.setPosition(x, y);
}

void Entity2::move(const float& dt,const float dir_x, const float dir_y)
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
