#pragma once
#include <ctime>
#include <stdlib.h>
#include<stack>
#include<map>
#include<iostream>
#include<sstream>
#include<string>


#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class MovementComponent
{
public:
	MovementComponent(float maxVelocity);
	~MovementComponent();

public:
	const sf::Vector2f& GetVelocity() const;

	void move(const float dir_x, const float dir_y);
	void update(const float& deltaTime);

private:
	float m_maxVelocity;
	sf::Vector2f m_velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;
};

