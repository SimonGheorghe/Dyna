#pragma once
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
class Entity
{
public:
	virtual void SetPosition(const float x, const float y);
	virtual void Render(sf::RenderTarget& target, uint16_t state);

protected:
	std::vector<sf::Sprite> m_sprites;
};

