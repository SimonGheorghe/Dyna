#pragma once
#include"State.h"

class GameState :
	public State
{
private:

public :
	GameState(sf::RenderWindow* window);
	virtual ~GameState();
	void endState();
	//void endStates();
	void UpdateKeybinds(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
};

