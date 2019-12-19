#pragma once
#include"State.h"

class GameState :
	public State
{
private:
	Entity2 m_player;

	void InitKeyBinds();
public :
	GameState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states);
	virtual ~GameState();
	void endState();
	//void endStates();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
};

