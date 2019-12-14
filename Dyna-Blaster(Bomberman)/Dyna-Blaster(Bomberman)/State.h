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

class State
{
public:
	State(sf::RenderWindow* window);
	virtual ~State();
	virtual void endStates() = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;

private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> m_textures;
};

