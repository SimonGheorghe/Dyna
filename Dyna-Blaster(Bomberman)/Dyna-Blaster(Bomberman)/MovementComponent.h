#pragma once
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <map>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

enum movement_states { IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };
class MovementComponent
{
public:
	MovementComponent(sf::Sprite& sprite, 
		float maxVelocity, float acceleration, float deceleration);
	~MovementComponent();

public:
	const float& getMaxVelocity() const;
	const sf::Vector2f& GetVelocity() const;

	const bool getState(const short unsigned state) const;

	void move(const float dir_x, const float dir_y, const float& deltaTime);
	void update(const float& deltaTime);

private:
	sf::Sprite& m_sprite;

	float m_maxVelocity;
	float m_acceleration;
	float m_deceleration;

	sf::Vector2f m_velocity;
};