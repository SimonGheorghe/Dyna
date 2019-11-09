#include "Map.h"
#include <time.h>
#include <random>
Map::Map(Stage Stage, uint16_t Level)
{
	srand((int)time(NULL));
	m_stage = Stage;
	m_level = Level;
	GenerateMapDimensions();
	GenerateBlocks();
}

void Map::GenerateMapDimensions()
{
	std::string mapDimensions = mapSize[(uint16_t)m_stage][m_level];
	if (mapDimensions[0] == 'N')
		m_width = Width::Narrow;
	else m_width = Width::Wide;
	if (mapDimensions[0] == 'S')
		m_length = Length::Short;
	else m_length = Length::Long;

	m_map.resize((uint16_t)m_width);
	for (int index = 0; index < m_map.size(); ++index)
		m_map[index].resize((uint16_t)m_length);
}

void Map::GenerateBlocks()
{
	for (int index1 = 0; index1 < (uint16_t)m_width; ++index1)
		for (int index2 = 0; index2 < (uint16_t)m_length; ++index2)
			if (index1 == 0 || index2 == 0 || index1 == (uint16_t)m_width - 1 || index2 == (uint16_t)m_length - 1|| (index1 % 2 == 0 && index2 % 2 == 0))
				m_map[index1][index2] = Entity(Block::Type::HardBlock);

	uint16_t noOfSoftBlocks = noOfStagesAndLevels * noOfStagesAndLevels / 3;
	for (int index = 0; index < noOfSoftBlocks; ++index)
	{
		uint16_t coordX;
		uint16_t coordY;
		do {
			coordX = rand() % (uint16_t)m_width;
			coordY = rand() % (uint16_t)m_length;
		} while (coordX % 2 == 0 && coordY % 2 == 0);
		m_map[coordX][coordY] = Entity(Block::Type::SoftBlock);
	}
}

const Entity& Map::operator[](const Position& position) const
{
	//const auto& [line, column] = position;  ???
	return m_map[position.first][position.second];
}

Entity& Map::operator[](const Position& position)
{
	//const auto& [line, column] = position;  ???
	return m_map[position.first][position.second];
}


std::istream& operator>>(std::istream& in, Map& map)
{
	for (int index1 = 0; index1 < map.noOfStagesAndLevels; ++index1)
		for (int index2 = 0; index2 < map.noOfStagesAndLevels; ++index2)
			in >> map.mapSize[index1][index2];
	return in;
}
