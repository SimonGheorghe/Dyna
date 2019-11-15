#include"Map.h"
#include<iostream>
#include"Block.h"
#include <fstream>
void main()
{
	Map map(Map::Stage::InsideOfTheCastlePartI, 2);
	std::ifstream file("levels'Size.txt");
	file >> map;
	std::cout << map;
}