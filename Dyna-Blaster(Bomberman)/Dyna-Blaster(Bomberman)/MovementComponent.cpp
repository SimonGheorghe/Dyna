#include "MovementComponent.h"

MovementComponent::MovementComponent(float maxVelocity):
	m_maxVelocity(maxVelocity)
{
}

MovementComponent::~MovementComponent()
{
	
}

const sf::Vector2f& MovementComponent::GetVelocity() const
{
	return m_velocity;
}

void MovementComponent::move(const float dir_x, const float dir_y)
{
	m_velocity.x = m_maxVelocity * dir_x;
	m_velocity.y = m_maxVelocity * dir_y;
}

void MovementComponent::update(const float& deltaTime)
{
}
