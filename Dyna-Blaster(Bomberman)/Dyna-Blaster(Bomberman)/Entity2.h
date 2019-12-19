#pragma once
#include <ctime>
#include <stdlib.h>
#include<stack>
#include<map>
#include<iostream>


#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
class Entity2
{
private:

protected:
	sf::RectangleShape m_shape;
	float m_movemedSpeed;

public : 
	Entity2();
	virtual ~Entity2();

	virtual void move(const float& dt,const float dir_x, const float dir_y);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
};


