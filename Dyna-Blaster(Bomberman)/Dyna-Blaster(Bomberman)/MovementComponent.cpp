#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, 
	float maxVelocity, float acceleration, float deceleration):
	m_sprite(sprite), m_maxVelocity(maxVelocity), m_acceleration(acceleration), m_deceleration(deceleration)
{

}

MovementComponent::~MovementComponent()
{
	
}

const float& MovementComponent::getMaxVelocity() const
{
	return m_maxVelocity;
}

const sf::Vector2f& MovementComponent::GetVelocity() const
{
	return m_velocity;
}

const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:
		if (m_velocity.x == 0.f && m_velocity.y == 0.f)
			return true;
		break;

	case MOVING:
		if (m_velocity.x != 0.f || m_velocity.y != 0.f)
			return true;
		break;

	case MOVING_LEFT:
		if (m_velocity.x < 0)
			return true;
		break;

	case MOVING_RIGHT:
		if (m_velocity.x > 0)
			return true;
		break;

	case MOVING_UP:
		if (m_velocity.y < 0)
			return true;
		break;

	case MOVING_DOWN:
		if (m_velocity.y > 0)
			return true;
		break;
	}
	return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& deltaTime)
{
	m_velocity.x += m_acceleration * dir_x;
	m_velocity.y += m_acceleration * dir_y;
}

void MovementComponent::update(const float& deltaTime)
{
	/*
	Decelerates the m_sprite and controls the maximum velocity.
	Moves the m_sprite.
	*/

	if (m_velocity.x > 0.f) // Check for positive x
	{
		// Max velocity check
		if (m_velocity.x > m_maxVelocity)
			m_velocity.x = m_maxVelocity;

		// Deceleration
		m_velocity.x -= m_deceleration;
		if (m_velocity.x < 0.f)
			m_velocity.x = 0.f;
	}
	else if(m_velocity.x < 0.f) // Check for negative x
	{
		// Max velocity check
		if (m_velocity.x < -m_maxVelocity)
			m_velocity.x = -m_maxVelocity;

		// Deceleration
		m_velocity.x += m_deceleration;
		if (m_velocity.x > 0.f)
			m_velocity.x = 0.f;
	}

	if (m_velocity.y > 0.f) // Check for positive y
	{
		// Max velocity check
		if (m_velocity.y > m_maxVelocity)
			m_velocity.y = m_maxVelocity;

		// Deceleration
		m_velocity.y -= m_deceleration;
		if (m_velocity.y < 0.f)
			m_velocity.y = 0;
	}
	else if (m_velocity.y < 0.f) // Check for negative x
	{
		// Max velocity check
		if (m_velocity.y < -m_maxVelocity)
			m_velocity.y = -m_maxVelocity;

		// Deceleration
		m_velocity.y += m_deceleration;
		if (m_velocity.y > 0.f)
			m_velocity.y = 0;
	}

	m_sprite.move(m_velocity * deltaTime);
}