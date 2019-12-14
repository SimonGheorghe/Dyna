#pragma once
#include "Monster.h"
#include "Powers.h"
#include "State.h"

class DynaGame
{
public:
	DynaGame();
	~DynaGame();

	void UpdateDt();
	void UpdateSFMLEvents();
	void Update();
	void Render();
	void Run();
	
private:
	void InitWindow();
	sf::Clock m_dtClock;
	float m_deltaTime;

private:
	sf::RenderWindow* m_window;
	sf::Event m_sfEvent;

private:
	void ReadMapsDimensions();

private:
	static const uint16_t noOfStagesAndLevels = 8;
	std::array<std::array<std::string, noOfStagesAndLevels>, noOfStagesAndLevels> mapsDimensions;
};

