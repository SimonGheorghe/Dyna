#include<iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <chrono>
#include <thread>

#include "DynaGame.h"
#include "Block.h"
#include "Player.h"

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
		std::this_thread::sleep_for(std::chrono::seconds(3));
		bool playerIsHit = 0;

		while (true)
		{
			system("cls");
			for (int index1 = 0; index1 < map.GetLength(); ++index1)
			{
				for (int index2 = 0; index2 < map.GetWidth(); ++index2)
				{
					if (index1 == player.GetCoordX() && index2 == player.GetCoordY())
						std::cout << player;
					else
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
