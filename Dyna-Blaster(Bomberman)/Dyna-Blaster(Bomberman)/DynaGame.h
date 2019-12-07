#pragma once
#include "Monster.h"
#include "Powers.h"

class DynaGame
{
public:
	void Run();

private:
	void ReadMapsDimensions();
	void SetMapDimensions(Map& map, Map::Stage stage, uint16_t level);

private:
	static const uint16_t noOfStagesAndLevels = 8;
	std::array<std::array<std::string, noOfStagesAndLevels>, noOfStagesAndLevels> mapsDimensions;
};

