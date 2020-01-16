#pragma once

#include "MainMenuState.h"

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
	void InitVariables();
	void InitWindow();
	void InitKeys();
	void InitStates();

private:
	sf::Clock m_dtClock;
	float m_deltaTime;

	sf::RenderWindow* m_window;
	sf::Event m_sfEvent;
	std::vector<sf::VideoMode> m_videoModes;
	sf::ContextSettings m_windowsSettings;

	std::stack<State*> states;
	std::map<std::string, int> suportedKeys;



};

