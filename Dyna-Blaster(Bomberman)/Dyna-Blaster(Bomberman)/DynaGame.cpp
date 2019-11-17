#include<iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <chrono>
#include <thread>

#include "DynaGame.h"
#include "Monster.h"
std::vector<Monster*> GenerateMonster(const Map& map)
{
	std::vector<Monster*> enemies;
	switch (map.GetStage())
	{
	case Map::Stage::TheWall:
		switch (map.GetLevel())
		{
		case 0:
			enemies.resize(3);
			enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Ballom);
			break;
		case 1:
			enemies.resize(3);
			enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Ekutopu);
			break;
		case 2:
			enemies.resize(3);
			enemies[0] = new Monster(Monster::Type::Ballom);
			enemies[1] = new Monster(Monster::Type::Ballom);
			enemies[2] = new Monster(Monster::Type::Boyon);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:

			break;
		}
		break;
	case Map::Stage::RockyMountains:
		break;
	case Map::Stage::River:
		break;
	case Map::Stage::Forest:
		break;
	case Map::Stage::LavaCave:
		break;
	case Map::Stage::InsideOfTheCastlePartI:
		break;
	case Map::Stage::InsideOfTheCastlePartII:
		break;
	case Map::Stage::InsideOfTheCastlePartIII:
		break;
	default:
		break;
	}
	return enemies;
}
void DynaGame::Run()
{
	srand((int)time(NULL));
	uint16_t playerFire = 3;
	uint16_t playerNoOfBombs = 1;
	uint16_t playerHealth = 6;
	uint32_t playerScore = 0;
	uint16_t playerSpeed = 2;
	Player player(playerFire, playerNoOfBombs, playerHealth, playerScore, playerSpeed);
	while (player.GetHealth() != 0)
	{
		Map map(Map::Stage::TheWall, 1);
		uint16_t playerCoordX = 1;
		uint16_t playerCoordY = 1;
		player.Place(map, playerCoordX, playerCoordY);
		std::cout << "The Wall, round 2";
		std::this_thread::sleep_for(std::chrono::seconds(0));
		bool playerIsHit = 0;
		std::vector<Monster*> enemies;
		enemies=GenerateMonster(map);
		for (int index = 0; index < enemies.size(); ++index)
		{
			enemies[index]->Place(map);
		}

		while (true)
		{
			system("cls");
			static uint16_t chrono=0;
			for (int index1 = 0; index1 < map.GetLength(); ++index1)
			{
				for (int index2 = 0; index2 < map.GetWidth(); ++index2)
				{
					if (index1 == player.GetCoordX() && index2 == player.GetCoordY())
						std::cout << player;

					else
					{
						bool ok = 1;
						for (int index = 0; index < enemies.size(); ++index)
							if (index1 == enemies[index]->GetCoordX() && index2 == enemies[index]->GetCoordY())
							{
								std::cout << *enemies[index];
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
									ok = 0;
								}
							if (ok)
							{
								Block* block = dynamic_cast<Block*>(map[{index1, index2}]);
								std::cout << *block;
								if (block->GetType() == Block::Type::ExplodedBlock ||
									block->GetType() == Block::Type::ExplodedBomb ||
									block->GetType() == Block::Type::HorizontalFire ||
									block->GetType() == Block::Type::VerticalFire)
									map.SetBlock(Block::Type::NoneBlock, index1, index2);
							}
						}
					}
				}
				std::cout << std::endl;
			}
			if (playerIsHit)
			{
				player.SetHealth(player.GetHealth() - 1);
				std::cout << "You are dead. You have " << player.GetHealth() << " lifes left!\n\n";
				break;
			}
			char ch = _getch();
			if (ch == ' ')
			{
				if (player.GetNoOfBombs() != 0)
					player.PlaceBomb(map, player.GetCoordX(), player.GetCoordY());
			}
			else
				player.Move(map, ch);
			for (int index = 0; index < enemies.size(); ++index)
				enemies[index]->Move(map, player);
			for (int index = 0; index < player.GetNoOfPlacedBombs(); ++index)
			{
				player[index]->SetTicks(player[index]->GetTicks() - 1);
				if (player[index]->GetTicks() == 0)
				{
					playerIsHit = player[index]->Explode(map, player.GetFire(), player.GetCoordX(), player.GetCoordY());
					player.DeleteBomb(index);
				}
			}
		}
	}
}
