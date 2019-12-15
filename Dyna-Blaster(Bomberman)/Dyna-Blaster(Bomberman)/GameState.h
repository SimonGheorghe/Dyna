#pragma once
#include"State.h"

class GameState :
	public State
{
private:
	Entity2 player;

	void InitKeyBinds();
public :
	GameState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys);
	virtual ~GameState();
	void endState();
	//void endStates();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
};

