#pragma once
#include "Monster.h"
#include "Powers.h"

#include <ctime>
#include <stdlib.h>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class DynaGame
{
public:
	DynaGame();
	~DynaGame();

	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
	
private:
	void InitWindow();

private:
	sf::RenderWindow* m_window;
	sf::Event m_sfEvent;

private:
	void ReadMapsDimensions();

private:
	static const uint16_t noOfStagesAndLevels = 8;
	std::array<std::array<std::string, noOfStagesAndLevels>, noOfStagesAndLevels> mapsDimensions;
};

