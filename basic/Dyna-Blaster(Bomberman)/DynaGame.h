#pragma once
#include "Monster.h"

class DynaGame
{
public:
	void Run();

	

private:
	float m_deltaTime;

private:
	void ReadMapsDimensions();

private:
	static const uint16_t noOfStagesAndLevels = 8;
	std::array<std::array<std::string, noOfStagesAndLevels>, noOfStagesAndLevels> mapsDimensions;
};

