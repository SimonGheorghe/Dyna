#include<iostream>
#include <fstream>
#include <time.h>

#include "Block.h"
#include "Player.h"

void main()
{
	srand((int)time(NULL));
	Map map(Map::Stage::TheWall, 1);
	Player player(1, 3, 0, 2, 1, 1);
	player.Place(map);
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
					Block* block = dynamic_cast<Block*>(map[{index1, index2}]);
					std::cout << *block;
				}
			}
			std::cout << std::endl;
		}
		player.Move(map);
	}
	//std::cout << map;
}