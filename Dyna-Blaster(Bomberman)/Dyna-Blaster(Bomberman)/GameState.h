#pragma once
#include"State.h"
#include "Monster.h"
#include "Powers.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <chrono>
#include <thread>

class GameState :
	public State
{
public :
	GameState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states);
	virtual ~GameState();
	//void endStates();

	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);

private:
	Player* m_player;
	Map* m_map;

	void InitKeyBinds();
	void InitTextures();
	void InitPlayers();

private:
	void ReadMapsDimensions();
	void CreateMap(Map& map, uint16_t stage, const Player& player, std::string mapDimensions);

private:
	static const uint16_t noOfStagesAndLevels = 8;
	std::array<std::array<std::string, noOfStagesAndLevels>, noOfStagesAndLevels> mapsDimensions;
	uint16_t m_stage, m_round;
};

