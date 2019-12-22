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

class Entity2
{
private:
	void initVariables();

protected:
	sf::Texture* texture;
	sf::Sprite* sprite;
	float m_movemedSpeed;

public : 
	Entity2();
	virtual ~Entity2();

	void createSPrite(sf::Texture* texture);

	virtual void move(const float& dt,const float dir_x, const float dir_y);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
};


