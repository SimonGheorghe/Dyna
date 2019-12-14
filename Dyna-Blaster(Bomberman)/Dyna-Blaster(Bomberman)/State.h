#pragma once

#include <ctime>
#include <stdlib.h>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class State
{
public:
	State();
	~State();

	virtual void Update() = 0;
	virtual void Render() = 0;

private:
	std::vector<sf::Texture> m_textures;
};

