#include<iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <chrono>
#include <thread>

#include "DynaGame.h"

void DynaGame::InitWindow()
{
	m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Dyna Blaster");
}
DynaGame::DynaGame()
{
	InitWindow();
}
DynaGame::~DynaGame()
{
	delete m_window;
}
void DynaGame::UpdateSFMLEvents()
{
	while (m_window->pollEvent(m_sfEvent))
	{
		if (m_sfEvent.type == sf::Event::Closed)
			m_window->close();
	}
}
void DynaGame::Update()
{
	UpdateSFMLEvents();
}
void DynaGame::Render()
{
	m_window->clear();
	m_window->display();
}
void DynaGame::ReadMapsDimensions()
{
	std::ifstream file("levels'Size.txt");//get map size for all levels
	for (int index1 = 0; index1 < noOfStagesAndLevels; ++index1)
		for (int index2 = 0; index2 < noOfStagesAndLevels; ++index2)
			file >> mapsDimensions[index1][index2];
}
void RandomEnemiesGenerator(std::vector<Monster*>& enemies, std::vector<uint16_t> possibleEnemies, uint16_t noOfEnemies)
{
	enemies.resize(noOfEnemies);
	for (int index = 0; index < noOfEnemies; ++index)
	{
		uint16_t random;
		random = rand() % possibleEnemies.size();
		enemies[index] = new Monster(Monster::Type(possibleEnemies[random]));
	}
}
void GenerateMonster(std::vector<Monster*>& enemies, const Map& map)
{
	uint16_t noOfEnemies=5;
	switch (map.GetStage())
	{
	case Map::Stage::TheWall:
		switch (map.GetLevel())
		{
		case 0:
			enemies.resize(1);
			/*enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Ballom);*/
			enemies[0] = new Monster(Monster::Type::Bubbles);
			break;
		case 1:
			enemies.resize(4);
			enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Ballom);
			enemies[3] = new Monster(Monster::Type::Ekutopu);
			break;
		case 2:
			enemies.resize(3);
			enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Ekutopu);
			break;
		case 3:
			enemies.resize(5);
			enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Ekutopu);
			enemies[3] = new Monster(Monster::Type::Ekutopu);
			enemies[4] = new Monster(Monster::Type::Boyon);
			break;
		case 4:
			enemies.resize(6);
			enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Ekutopu);
			enemies[3] = new Monster(Monster::Type::Ekutopu);
			enemies[4] = new Monster(Monster::Type::Boyon);
			enemies[5] = new Monster(Monster::Type::Boyon);
			break;
		case 5:
			enemies.resize(5);
			enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Ekutopu);
			enemies[3] = new Monster(Monster::Type::Boyon);
			enemies[4] = new Monster(Monster::Type::Pass);
			break;
		case 6:
			enemies.resize(5);
			enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Boyon);
			enemies[3] = new Monster(Monster::Type::Pass);
			enemies[4] = new Monster(Monster::Type::Telpio);
			break;
		case 7:
			enemies.resize(8);
			enemies[0] = new Monster(Monster::Type::Telpio);
			enemies[1] = new Monster(Monster::Type::Telpio);
			enemies[2] = new Monster(Monster::Type::SnakeHead);
			enemies[3] = new Monster(Monster::Type::SnakeBody);
			enemies[4] = new Monster(Monster::Type::SnakeBody);
			enemies[5] = new Monster(Monster::Type::SnakeBody);
			enemies[6] = new Monster(Monster::Type::SnakeBody);
			enemies[7] = new Monster(Monster::Type::SnakeTail);
			break;
		}
		break;
	case Map::Stage::RockyMountains:
		
		switch (map.GetLevel())
		{
		case 0:
			noOfEnemies = 5;
			break;
		case 1:
			noOfEnemies = 5;
			break;
		case 2:
			noOfEnemies = 5;
			break;
		case 3:
			noOfEnemies = 5;
			break;
		case 4:
			noOfEnemies = 5;
			break;
		case 5:
			noOfEnemies = 5;
			break;
		case 6:
			noOfEnemies = 5;
			break;
		default:
			break;
		}
		if (map.GetLevel() != 7)
		{
			std::vector<uint16_t> possibleEnemies = { 0,2,3,4,5,6,7 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
		{
			enemies.resize(1);
			enemies[0] = new Monster(Monster::Type::Bubbles);
		}
		break;
	case Map::Stage::River:
		
		switch (map.GetLevel())
		{
		case 0:
			noOfEnemies = 5;
			break;
		case 1:
			noOfEnemies = 5;
			break;
		case 2:
			noOfEnemies = 5;
			break;
		case 3:
			noOfEnemies = 5;
			break;
		case 4:
			noOfEnemies = 5;
			break;
		case 5:
			noOfEnemies = 5;
			break;
		case 6:
			noOfEnemies = 5;
			break;
		default:
			break;
		}
		if (map.GetLevel() != 7)
		{
			std::vector<uint16_t> possibleEnemies = { 0,1,2,3,4,17,18 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
		{
			enemies.resize(12);
			enemies[0] = new Monster(Monster::Type::SnakeHead);
			enemies[1] = new Monster(Monster::Type::SnakeBody);
			enemies[2] = new Monster(Monster::Type::SnakeBody);
			enemies[3] = new Monster(Monster::Type::SnakeBody);
			enemies[4] = new Monster(Monster::Type::SnakeBody);
			enemies[5] = new Monster(Monster::Type::SnakeTail);
			enemies[6] = new Monster(Monster::Type::SnakeHead);
			enemies[7] = new Monster(Monster::Type::SnakeBody);
			enemies[8] = new Monster(Monster::Type::SnakeBody);
			enemies[9] = new Monster(Monster::Type::SnakeBody);
			enemies[10] = new Monster(Monster::Type::SnakeBody);
			enemies[11] = new Monster(Monster::Type::SnakeTail);
		}
			break;
	case Map::Stage::Forest:
		
		switch (map.GetLevel())
		{
		case 0:
			noOfEnemies = 5;
			break;
		case 1:
			noOfEnemies = 5;
			break;
		case 2:
			noOfEnemies = 5;
			break;
		case 3:
			noOfEnemies = 5;
			break;
		case 4:
			noOfEnemies = 5;
			break;
		case 5:
			noOfEnemies = 5;
			break;
		case 6:
			noOfEnemies = 5;
			break;
		default:
			break;
		}
		if (map.GetLevel() != 7)
		{
			std::vector<uint16_t> possibleEnemies = { 2,3,4,5,8,9 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
		{
			enemies.resize(5);
			enemies[0] = new Monster(Monster::Type::WarpMan);
			enemies[1] = new Monster(Monster::Type::YoungWarpMan);
			enemies[2] = new Monster(Monster::Type::YoungWarpMan);
			enemies[3] = new Monster(Monster::Type::YoungWarpMan);
			enemies[4] = new Monster(Monster::Type::YoungWarpMan);
		}
			break;
	case Map::Stage::LavaCave:
		
		switch (map.GetLevel())
		{
		case 0:
			noOfEnemies = 5;
			break;
		case 1:
			noOfEnemies = 5;
			break;
		case 2:
			noOfEnemies = 5;
			break;
		case 3:
			noOfEnemies = 5;
			break;
		case 4:
			noOfEnemies = 5;
			break;
		case 5:
			noOfEnemies = 5;
			break;
		case 6:
			noOfEnemies = 5;
			break;
		default:
			break;
		}
		if (map.GetLevel() != 7)
		{
			std::vector<uint16_t> possibleEnemies = { 2,3,4,5,10,11 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
		{
			enemies.resize(3);
			enemies[0] = new Monster(Monster::Type::Bubbles);
			enemies[1] = new Monster(Monster::Type::Bubbles);
			enemies[2] = new Monster(Monster::Type::Bubbles);
		}
			break;
	case Map::Stage::InsideOfTheCastlePartI:
		
		switch (map.GetLevel())
		{
		case 0:
			noOfEnemies = 5;
			break;
		case 1:
			noOfEnemies = 5;
			break;
		case 2:
			noOfEnemies = 5;
			break;
		case 3:
			noOfEnemies = 5;
			break;
		case 4:
			noOfEnemies = 5;
			break;
		case 5:
			noOfEnemies = 5;
			break;
		case 6:
			noOfEnemies = 5;
			break;
		default:
			break;
		}
		if (map.GetLevel() != 7)
		{
			std::vector<uint16_t> possibleEnemies = { 2,3,4,5,12,13 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
		{
			enemies.resize(10);
			enemies[0] = new Monster(Monster::Type::WarpMan);
			enemies[1] = new Monster(Monster::Type::YoungWarpMan);
			enemies[2] = new Monster(Monster::Type::YoungWarpMan);
			enemies[3] = new Monster(Monster::Type::YoungWarpMan);
			enemies[4] = new Monster(Monster::Type::YoungWarpMan);
			enemies[5] = new Monster(Monster::Type::WarpMan);
			enemies[6] = new Monster(Monster::Type::YoungWarpMan);
			enemies[7] = new Monster(Monster::Type::YoungWarpMan);
			enemies[8] = new Monster(Monster::Type::YoungWarpMan);
			enemies[9] = new Monster(Monster::Type::YoungWarpMan);
		}
			break;
	case Map::Stage::InsideOfTheCastlePartII:
		
		switch (map.GetLevel())
		{
		case 0:
			noOfEnemies = 5;
			break;
		case 1:
			noOfEnemies = 5;
			break;
		case 2:
			noOfEnemies = 5;
			break;
		case 3:
			noOfEnemies = 5;
			break;
		case 4:
			noOfEnemies = 5;
			break;
		case 5:
			noOfEnemies = 5;
			break;
		case 6:
			noOfEnemies = 5;
			break;
		default:
			break;
		}
		if (map.GetLevel() != 7)
		{
			std::vector<uint16_t> possibleEnemies = { 2,3,4,5,14,15 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
		{
			enemies.resize(4);
			enemies[0] = new Monster(Monster::Type::Spidfire);
			enemies[1] = new Monster(Monster::Type::Spidfire);
			enemies[2] = new Monster(Monster::Type::Spidfire);
			enemies[3] = new Monster(Monster::Type::Spidfire);
		}
			break;
	case Map::Stage::InsideOfTheCastlePartIII:
		
		switch (map.GetLevel())
		{
		case 0:
			noOfEnemies = 5;
			break;
		case 1:
			noOfEnemies = 5;
			break;
		case 2:
			noOfEnemies = 5;
			break;
		case 3:
			noOfEnemies = 5;
			break;
		case 4:
			noOfEnemies = 5;
			break;
		case 5:
			noOfEnemies = 5;
			break;
		case 6:
			noOfEnemies = 5;
			break;
		default:
			break;
		}
		if (map.GetLevel() != 7)
		{
			std::vector<uint16_t> possibleEnemies = { 0,2,3,4,5,6,16 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
		break;
	default:
		break;
	}
}
void SetMapDimensions(Map& map, std::string mapDimensions)
{
	if (mapDimensions[0] == 'N')
		map.SetWidth(Map::Width::Narrow);
	else map.SetWidth(Map::Width::Wide);
	if (mapDimensions[1] == 'S')
		map.SetLength(Map::Length::Short);
	else map.SetLength(Map::Length::Long);
}
void PlayerMove(Player& player, Map& map, std::vector<Monster*>& enemies, uint16_t time)
{
	uint16_t noOfMoves = 0;
	if (player.GetSpeed() == 1 && time % 2 == 0 ||
		player.GetSpeed() == 2)
		noOfMoves = 1;
	if (player.GetSpeed() == 4)
		noOfMoves = 2;
	if (player.GetSpeed() == 3)
		if (time % 2 == 0)
			noOfMoves = 2;
		else
			noOfMoves = 1;

	for (int index = 0; index < noOfMoves; ++index)
	{
		char ch = _getch();
		if (ch == ' ')
		{
			if (player.GetNoOfBombs() != 0 &&
				dynamic_cast<Block*>(map[{player.GetCoordX(), player.GetCoordY()}]) &&
				dynamic_cast<Block*>(map[{player.GetCoordX(), player.GetCoordY()}])->GetType() == Block::Type::NoneBlock)
				player.PlaceBomb(map);
		}
		else
			if (ch == 'k')
				enemies.clear();
			else
				if (ch == 'r')
				{
					if (player.GetHasRemoteControl() && player.GetNoOfPlacedBombs() != 0)
						player.ExplodeBomb(map, 0);
				}
				else
					player.Move(map, ch);
	}
}
void PrintMap(Map& map, const Player& player, std::vector<Monster*>& enemies)
{
	std::cout << "Score: " << player.GetScore() << std::endl;

	for (int index1 = 0; index1 < map.GetLength(); ++index1)
	{
		for (int index2 = 0; index2 < map.GetWidth(); ++index2)
		{
			if (index1 == player.GetCoordX() && index2 == player.GetCoordY())
			{
				std::cout << player;
				map.ClearMap(index1, index2);
			}
			else
			{
				bool ok = 1;
				for (int index = 0; index < enemies.size(); ++index)
					if (index1 == enemies[index]->GetCoordX() && index2 == enemies[index]->GetCoordY())
					{
						std::cout << *enemies[index];
						map.ClearMap(index1, index2);
						ok = 0;
						break;
					}
				if (ok)
				{
					bool ok = 1;
					for (int index = 0; index < player.GetNoOfPlacedBombs(); ++index)
						if (index1 == player[index]->GetCoordX() && index2 == player[index]->GetCoordY())
						{
							std::cout << *player[index];
							map.ClearMap(index1, index2);
							ok = 0;
						}
					if (ok)
					{
						if (dynamic_cast<Block*>(map[{index1, index2}]))
						{
							std::cout << *dynamic_cast<Block*>(map[{index1, index2}]);
							map.ClearMap(index1, index2);
						}
						if (dynamic_cast<Powers*>(map[{index1, index2}]))
							std::cout << *dynamic_cast<Powers*>(map[{index1, index2}]);
					}
				}
			}
		}
		std::cout << std::endl;
	}
}
void DeleteDeadMonsters(std::vector<Monster*>& enemies, Map& map, Player& player)
{
	for (int index = 0; index < enemies.size(); ++index)
		if (enemies[index]->GetHitPoints() == 0)
		{
			int x = enemies[index]->GetCoordX();
			int y = enemies[index]->GetCoordY();
			map.SetBlock(Block::Type::NoneBlock, x, y);
			player.AddScore(enemies[index]->GetScore());
			enemies.erase(enemies.begin() + index--);
		}
}
void MonsterMove(std::vector<Monster*>& enemies, Map& map, Player& player, uint16_t time)
{
	for (int index = 0; index < enemies.size(); ++index)
	{
		if (enemies[index]->GetType() == Monster::Type::Bubbles && time % 1 == 0)
			enemies.push_back(new Monster(Monster::Type::BabyBubbles, enemies[index]->GetCoordX(), enemies[index]->GetCoordY()));
		if (enemies[index]->GetHitPoints() != 0)
			switch (enemies[index]->GetSpeed())
			{
			case Monster::Speed::Slow:
				if (time % 2 == 0)
					enemies[index]->Move(map, player);
				break;
			case Monster::Speed::Normal:
				enemies[index]->Move(map, player);
				break;
			case Monster::Speed::Fast:
				if (time % 2 == 0)
					enemies[index]->Move(map, player);
				else
				{
					enemies[index]->Move(map, player);
					enemies[index]->Move(map, player);
				}
				break;
			case Monster::Speed::VeryFast:
				enemies[index]->Move(map, player);
				enemies[index]->Move(map, player);
				break;
			default:
				break;
			}
	}
}
void CreateMap(Map& map, uint16_t stage, const Player& player, std::string mapDimensions)
{

	SetMapDimensions(map, mapDimensions);
	map.Create();
	map.GeneratePower();

	if (stage != 0)
		while (map.GetPowerType() == Powers::Type::BombPass && player.GetHasBombPass() ||
			map.GetPowerType() == Powers::Type::RemoteControl && player.GetHasRemoteControl() ||
			map.GetPowerType() == Powers::Type::SoftBlockPass && player.GetHasSoftBlockPass() ||
			map.GetPowerType() == Powers::Type::Vest && player.GetHasVest())
		{
			map.DeletePower();
			map.GeneratePower();
		}
}
bool PlaceExit(Map& map)
{
	uint16_t coordX;
	uint16_t coordY;
	do {
		coordX = rand() % map.GetLength();
		coordY = rand() % map.GetWidth();
	} while (dynamic_cast<Block*>(map[{coordX, coordY}])->GetType() != Block::Type::NoneBlock);
	map.SetBlock(Block::Type::Exit, coordX, coordY);
	return 1;
}
bool BombsTicksDown(Player& player, Map& map)
{
	if (!player.GetHasRemoteControl())
		for (int index = 0; index < player.GetNoOfPlacedBombs(); ++index)
		{
			player[index]->SetTicks(player[index]->GetTicks() - 1);
			if (player[index]->GetTicks() == 0)
				return player.ExplodeBomb(map, index);
		}
	return 0;
}
void DropMontsersHitPoints(std::vector<Monster*>& enemies, Map& map)
{
	for (int index = 0; index < enemies.size(); ++index)
	{
		int x = enemies[index]->GetCoordX();
		int y = enemies[index]->GetCoordY();
		if (dynamic_cast<Block*>(map[{x, y}]))
			if (dynamic_cast<Block*>(map[{x, y}])->GetType() == Block::Type::HorizontalFire ||
				dynamic_cast<Block*>(map[{x, y}])->GetType() == Block::Type::ExplodedBomb ||
				dynamic_cast<Block*>(map[{x, y}])->GetType() == Block::Type::VerticalFire)
				enemies[index]->DropHitPoints();
	}
}
void DynaGame::Run()
{
	srand((int)time(NULL));

	ReadMapsDimensions();

	uint16_t playerFire = 2;
	uint16_t playerNoOfBombs = 3;
	uint16_t playerHealth = 6;
	uint32_t playerScore = 0;
	uint16_t playerSpeed = 2;
	Player player(playerFire, playerNoOfBombs, playerHealth, playerScore, playerSpeed);

	bool endRound = 0;
	uint16_t stage = 0;
	bool exit;

	while (m_window->isOpen())
	{
		Update();
		Render();
	}

	while (stage < 8)
	{
		uint16_t round = 5;
		while (round < 8)
		{
			if (round == 7)
				exit = 0;
			endRound = 0;
			while (endRound == 0)
			{
				system("cls");

				Map map(Map::Stage(stage), round);
				std::string mapDimensions = mapsDimensions[(uint16_t)stage][round];
				CreateMap(map, stage, player, mapDimensions);

				std::cout << map; // shows current stage and level

				uint16_t playerCoordX = 1;
				uint16_t playerCoordY = 1;
				player.Place(map, playerCoordX, playerCoordY);

				std::this_thread::sleep_for(std::chrono::seconds(3));

				bool playerIsHit = 0;
				std::vector<Monster*> enemies;
				GenerateMonster(enemies, map);

				uint16_t noOfMonsters = enemies.size();
				for (int index = 0; index < noOfMonsters; ++index)
				{
					enemies[index]->Place(map,enemies);
				}
				uint16_t time = 0;

				while (true)
				{
					system("cls");
					static uint16_t chrono = 0;
					
					PrintMap(map, player, enemies);

					DeleteDeadMonsters(enemies, map, player);

					if (round == 7 && enemies.empty() && !exit)
						exit = PlaceExit(map);

					//kills player if bomb hit him
					if (playerIsHit && !player.GetHasVest())
					{
						player.SetHealth(player.GetHealth() - 1);
						player.SetVest(0);
						player.SetBombPass(0);
						player.SetRemoteControl(0);
						std::cout << "You are dead. You have " << player.GetHealth() << " lifes left!\n\n";
						std::this_thread::sleep_for(std::chrono::seconds(1));

						break;
					}

					//ends round if all requirements are met
					if (enemies.size() == 0 && 
						dynamic_cast<Block*>(map[{player.GetCoordX(), player.GetCoordY()}]) &&
						dynamic_cast<Block*>(map[{player.GetCoordX(), player.GetCoordY()}])->GetType() == Block::Type::Exit)
					{
						endRound = 1;
						break;
					}

					PlayerMove(player, map, enemies, time);

					playerIsHit = BombsTicksDown(player, map);

					//if monsters are hit
					DropMontsersHitPoints(enemies, map);

					MonsterMove(enemies, map, player, time);

					//verify if player collides with enemies
					for (int index = 0; index < enemies.size(); index++)
					{
						if ((enemies[index]->GetCoordX() == player.GetCoordX() && enemies[index]->GetCoordY() == player.GetCoordY()) ||
							(enemies[index]->GetCoordX() == player.GetLastX() && enemies[index]->GetCoordY() == player.GetLastY() &&
								enemies[index]->GetLastX() == player.GetCoordX() && enemies[index]->GetLastY() == player.GetCoordY()))
							playerIsHit = 1;
					}

					time++;
				}

				if (endRound)
				{
					std::cout << "\nYou finished the round! Now prepare yourself for more!\n";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					round++;
					break;
				}

				if (player.GetHealth() == 0)
				{
					std::cout << "You are out of lives! :(\nGood luck next time!";
					return;
				}
			}
		}
			stage++;
	}
}


