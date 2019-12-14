#pragma once
#include "Monster.h"
#include "Powers.h"
#include "GameState.h"

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
	void endAplication();

	
private:
	void InitWindow();
	void initStates();
	sf::Clock m_dtClock;
	float m_deltaTime;

private:
	sf::RenderWindow* m_window;
	sf::Event m_sfEvent;

	std::stack<State*> states;

private:
	void ReadMapsDimensions();

private:
	static const uint16_t noOfStagesAndLevels = 8;
	std::array<std::array<std::string, noOfStagesAndLevels>, noOfStagesAndLevels> mapsDimensions;
};

