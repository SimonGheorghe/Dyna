#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, 
	float maxVelocity, float acceleration, float deceleration):
	m_sprite(sprite), m_maxVelocity(maxVelocity), m_acceleration(acceleration), m_deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
	
}

const sf::Vector2f& MovementComponent::GetVelocity() const
{
	return m_velocity;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& deltaTime)
{
	m_velocity.x += m_acceleration * dir_x;

	if (m_velocity.x > 0.f)
	{
		if (m_velocity.x > m_maxVelocity)
			m_velocity.x = m_maxVelocity;
	}
	else if (m_velocity.x < 0.f)
	{
		if (m_velocity.x < m_maxVelocity)
			m_velocity.x = m_maxVelocity;
	}
	m_velocity.y += m_acceleration * dir_y;

}

void MovementComponent::update(const float& deltaTime)
{
	if (m_velocity.x > 0.f)
	{
		m_velocity.x -= m_deceleration;
		if (m_velocity.x < 0.f)
			m_velocity.x = 0;
	}
	else if(m_velocity.x < 0.f)
	{
		m_velocity.x += m_deceleration;
		if (m_velocity.x > 0.f)
			m_velocity.x = 0;
	}

	m_sprite.move(m_velocity * deltaTime);
}