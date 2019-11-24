#include<iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <chrono>
#include <thread>

#include "DynaGame.h"
#include "Monster.h"
#include "Powers.h"
void RandomEnemiesGenerator(std::vector<Monster*>& enemies, std::vector<uint16_t> possibleEnemies, uint16_t noOfEnemies)
{
	enemies.resize(noOfEnemies);
	for (int index = 0; index < noOfEnemies; ++index)
	{
		bool ok;
		uint16_t random;
		random = rand() % possibleEnemies.size();
		enemies[index] = new Monster(Monster::Type(possibleEnemies[random]));
	}
}
void GenerateMonster(std::vector<Monster*>& enemies, const Map& map)
{
	uint16_t noOfEnemies;
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
			enemies.resize(3);
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
		if (map.GetLevel()!= 7) 
		{
			uint16_t noOfEnemies = 10;
			std::vector<uint16_t> possibleEnemies = { 0,2,3,4,5,6,7 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else

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
			uint16_t noOfEnemies = 10;
			std::vector<uint16_t> possibleEnemies = { 0,1,2,3,4,17,18 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
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
			uint16_t noOfEnemies = 10;
			std::vector<uint16_t> possibleEnemies = { 2,3,4,5,8,9 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
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
			uint16_t noOfEnemies = 10;
			std::vector<uint16_t> possibleEnemies = { 2,3,4,5,10,11 };
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
			uint16_t noOfEnemies = 10;
			std::vector<uint16_t> possibleEnemies = { 2,3,4,5,12,13 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
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
			uint16_t noOfEnemies = 10;
			std::vector<uint16_t> possibleEnemies = { 2,3,4,5,14,15 };
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
			uint16_t noOfEnemies = 10;
			std::vector<uint16_t> possibleEnemies = { 0,2,3,4,5,6,16 };
			RandomEnemiesGenerator(enemies, possibleEnemies, noOfEnemies);
		}
		else
		break;
	default:
		break;
	}
}

void DynaGame::Run()
{
	srand((int)time(NULL));
	uint16_t playerFire = 1;
	uint16_t playerNoOfBombs = 1;
	uint16_t playerHealth = 6;
	uint32_t playerScore = 0;
	uint16_t playerSpeed = 2;
	Player player(playerFire, playerNoOfBombs, playerHealth, playerScore, playerSpeed);
	bool endRound = 0;
	uint16_t stage = 0;
	bool exit;
	while (stage < 8)
	{
		uint16_t round = 0;
		while (round < 8)
		{

			if (round == 7)
				exit = 0;
			endRound = 0;
			while (player.GetHealth() != 0 && endRound == 0)
			{
				system("cls");
				Map map(Map::Stage(stage), round);
				std::cout << map;
				uint16_t playerCoordX = 1;
				uint16_t playerCoordY = 1;
				player.Place(map, playerCoordX, playerCoordY);
				std::this_thread::sleep_for(std::chrono::seconds(3));
				bool playerIsHit = 0;
				std::vector<Monster*> enemies;
				GenerateMonster(enemies, map);

				for (int index = 0; index < enemies.size(); ++index)
				{
					enemies[index]->Place(map);
				}

				while (true)
				{
					system("cls");
					static uint16_t chrono = 0;
					for (int index = 0; index < enemies.size(); ++index)
					{
						int x = enemies[index]->GetCoordX();
						int y = enemies[index]->GetCoordY();
						if(dynamic_cast<Block*>(map[{x, y}]))
						if (dynamic_cast<Block*>(map[{x, y}])->GetType() == Block::Type::HorizontalFire ||
							dynamic_cast<Block*>(map[{x, y}])->GetType() == Block::Type::ExplodedBomb ||
							dynamic_cast<Block*>(map[{x, y}])->GetType() == Block::Type::VerticalFire)
							enemies[index]->DropHitPoints();
					}
					std::cout << "Score: " << player.GetScore() << std::endl;
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
										if (dynamic_cast<Block*>(map[{index1, index2}]))
										{
											Block* block = dynamic_cast<Block*>(map[{index1, index2}]);
											std::cout << *block;
											if (block->GetType() == Block::Type::ExplodedBlock ||
												block->GetType() == Block::Type::ExplodedBomb ||
												block->GetType() == Block::Type::HorizontalFire ||
												block->GetType() == Block::Type::VerticalFire)
												map.SetBlock(Block::Type::NoneBlock, index1, index2);
										}
										if (dynamic_cast<Powers*>(map[{index1, index2}]))
											std::cout << *dynamic_cast<Powers*>(map[{index1, index2}]);
									}
								}
							}
						}
						std::cout << std::endl;
					}

					for (int index = 0; index < enemies.size(); ++index)
						if (enemies[index]->GetHitPoints() == 0)
						{
							int x = enemies[index]->GetCoordX();
							int y = enemies[index]->GetCoordY();
							map.SetBlock(Block::Type::NoneBlock, x, y);
							player.AddScore(enemies[index]->GetScore());
							enemies.erase(enemies.begin() + index);
						}
					uint16_t coordX;
					uint16_t coordY;
					if (round == 7 && enemies.empty() && !exit)
					{
						do {
							coordX = rand() % map.GetLength();
							coordY = rand() % map.GetWidth();
						} while (dynamic_cast<Block*>(map[{coordX, coordY}])->GetType() != Block::Type::NoneBlock);
						map.SetBlock(Block::Type::Exit, coordX, coordY);
						dynamic_cast<Block*>(map[{coordX, coordY}])->SetExitStatus(0);
						exit = 1;
					}
					if (playerIsHit && !player.GetHasVest())
					{
						player.SetHealth(player.GetHealth() - 1);
						std::cout << "You are dead. You have " << player.GetHealth() << " lifes left!\n\n";
						std::this_thread::sleep_for(std::chrono::seconds(1));

						break;
					}
					if (enemies.size() == 0 && 
						dynamic_cast<Block*>(map[{player.GetCoordX(), player.GetCoordY()}]) &&
						dynamic_cast<Block*>(map[{player.GetCoordX(), player.GetCoordY()}])->GetType() == Block::Type::Exit && 
						dynamic_cast<Block*>(map[{player.GetCoordX(), player.GetCoordY()}])->GetExitStatus() == 0)
					{
						endRound = 1;
						break;
					}
					char ch = _getch();
					if (ch == ' ')
					{
						if (player.GetNoOfBombs() != 0 &&
							dynamic_cast<Block*>(map[{player.GetCoordX(), player.GetCoordY()}]) &&
							dynamic_cast<Block*>(map[{player.GetCoordX(), player.GetCoordY()}])->GetType() == Block::Type::NoneBlock &&
							!player.IsOnBomb())
							player.PlaceBomb(map);
					}
					else
						if (ch == 'k')
							enemies.clear();
						else
							if (ch == 'r')
							{
								if (player.GetRemoteControl() && player.GetNoOfPlacedBombs()!=0)
								{
									player[0]->Explode(map, player.GetFire(), player.GetCoordX(), player.GetCoordY());
									player.DeleteBomb(0);
								}

							}
						else
							player.Move(map, ch);
					for (int index = 0; index < enemies.size(); ++index)
						enemies[index]->Move(map, player);
					if(!player.GetRemoteControl())
						for (int index = 0; index < player.GetNoOfPlacedBombs(); ++index)
						{
							player[index]->SetTicks(player[index]->GetTicks() - 1);
							if (player[index]->GetTicks() == 0)
							{
								playerIsHit = player[index]->Explode(map, player.GetFire(), player.GetCoordX(), player.GetCoordY());
								player.DeleteBomb(index);
							}
						}
					for (int index = 0; index < enemies.size(); index++)
					{
						if ((enemies[index]->GetCoordX() == player.GetCoordX() && enemies[index]->GetCoordY() == player.GetCoordY()) ||
							(enemies[index]->GetCoordX() == player.GetLastX() && enemies[index]->GetCoordY() == player.GetLastY() &&
								enemies[index]->GetLastX() == player.GetCoordX() && enemies[index]->GetLastY() == player.GetCoordY()))
						{
							playerIsHit = 1;
							player.SetVest(0);
							player.SetBombPass(0);
							player.SetRemoteControl(0);
						}
					}
				}

				if (endRound)
				{
					std::cout << "\nYou finished the round! Now prepare yourself for more!\n";
					std::this_thread::sleep_for(std::chrono::seconds(3));
					round++;
					break;
				}
				else
					std::cout << "You are out of lives! :(\nGood luck next time!";
			}
		}
			stage++;
	}
}
