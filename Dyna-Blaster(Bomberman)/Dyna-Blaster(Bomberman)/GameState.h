#pragma once
#include"State.h"

class GameState :
	public State
{
private:
	Player* m_player;
	void InitKeyBinds();
	void InitTextures();
	void InitPlayers();
public :
	GameState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states);
	virtual ~GameState();
	//void endStates();

	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
};

