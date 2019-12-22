#include "Entity2.h"

void Entity2::initVariables()
{
	texture = NULL;
	sprite = NULL;
	m_movementComponent = NULL;
}

Entity2::Entity2()
{
	initVariables();

}

Entity2::~Entity2()
{
	delete sprite;
}

void Entity2::createSprite(sf::Texture* texture)
{
	texture = texture;
	sprite = new sf::Sprite(*this->texture);
}

void Entity2::CreateMovementComponent(const float maxVelocity)
{
	m_movementComponent = new MovementComponent(maxVelocity);
}

void Entity2::SetPosition(const float x, const float y)
{
	if (sprite)
		sprite->setPosition(x, y);
}

void Entity2::move(const float& dt,const float dir_x, const float dir_y)
{
	if (sprite && m_movementComponent)
	{
		m_movementComponent->move(dir_x, dir_y);
		sprite->move(m_movementComponent->GetVelocity() * dt);
	}
}

void Entity2::Update(const float& dt)
{
	
}

void Entity2::Render(sf::RenderTarget* target)
{
	if(sprite)
	 target->draw(*sprite);
}
