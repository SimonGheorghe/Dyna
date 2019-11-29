#include "Map.h"
#include <time.h>
#include <random>
#include <fstream>

Map::Map(Stage Stage, uint16_t Level)
{
	m_stage = Stage;
	m_level = Level;
	GenerateMapDimensions();
	GenerateBlocks();
	
}

Map::Map()
{
	m_width = Width::Narrow;
	m_length = Length::Short;

	m_map.resize((uint16_t)m_length);
	for (int index = 0; index < m_map.size(); ++index)
		m_map[index].resize((uint16_t)m_width);
	GenerateBlocks();
}

void Map::GenerateMapDimensions()
{
	std::ifstream file("levels'Size.txt");//get map size for all levels
	for (int index1 = 0; index1 < noOfStagesAndLevels; ++index1)
		for (int index2 = 0; index2 < noOfStagesAndLevels; ++index2)
			file >> mapSize[index1][index2];

	std::string mapDimensions = mapSize[(uint16_t)m_stage][m_level];
	if (mapDimensions[0] == 'N')
		m_width = Width::Narrow;
	else m_width = Width::Wide;
	if (mapDimensions[1] == 'S')
		m_length = Length::Short;
	else m_length = Length::Long;

	m_map.resize((uint16_t)m_length);
	for (int index = 0; index < m_map.size(); ++index)
		m_map[index].resize((uint16_t)m_width);
}

void Map::GenerateBlocks()
{
	for (int index1 = 0; index1 < (uint16_t)m_length; ++index1)
		for (int index2 = 0; index2 < (uint16_t)m_width; ++index2)
			if (index1 == 0 || index2 == 0 || index1 == (uint16_t)m_length - 1 || index2 == (uint16_t)m_width - 1|| (index1 % 2 == 0 && index2 % 2 == 0))
				m_map[index1][index2] = new Block(Block::Type::HardBlock); 
	//37% of the map is covered by hard blocks
	if (m_level != 7)
	{
		uint16_t coordX;
		uint16_t coordY;
		uint16_t noOfSoftBlocks = (uint16_t)m_length * (uint16_t)m_width / 5; // 20% of the hole map is covered by soft blocks
																			//so 43% of the map is free
		for (int index = 0; index < noOfSoftBlocks; ++index)
		{
			do {
				coordX = rand() % (uint16_t)m_length;
				coordY = rand() % (uint16_t)m_width;
			} while (m_map[coordX][coordY] != nullptr);
			m_map[coordX][coordY] = new Block(Block::Type::SoftBlock);
		}
		do {
			coordX = rand() % (uint16_t)m_length;
			coordY = rand() % (uint16_t)m_width;
		} while (m_map[coordX][coordY] != nullptr || (coordX == 1 || coordX == 2) && (coordY == 1 || coordY == 2));//we dont want to place the exit in player's zone
		m_map[coordX][coordY] = new Block(Block::Type::Exit);
		do {
			coordX = rand() % (uint16_t)m_length;
			coordY = rand() % (uint16_t)m_width;
		} while (m_map[coordX][coordY] != nullptr || (coordX == 1 || coordX == 2) && (coordY == 1 || coordY == 2));//we dont want to place the power in player's zone

		m_map[coordX][coordY] = new Powers(GeneratePower());
	}

	for (int index1 = 0; index1 < (uint16_t)m_length; ++index1)
		for (int index2 = 0; index2 < (uint16_t)m_width; ++index2)
		{
			if (!dynamic_cast<Block*>(m_map[index1][index2]) && !dynamic_cast<Powers*>(m_map[index1][index2]))
			{
				m_map[index1][index2] = new Block(Block::Type::NoneBlock);
			}
		}

}

Powers::Power Map::GeneratePower()
{
	Powers* powers;
	switch (m_stage)
	{
	case Map::Stage::TheWall:
		switch (m_level)
		{
		case 0:
			return Powers::Power::FireUp;
			break;
		case 1:
			return Powers::Power::BombUp;
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
}

const Entity* Map::operator[](const Position& position) const
{
	//const auto& [line, column] = position;  ???
	return m_map[position.first][position.second];
}

Entity* Map::operator[](const Position& position)
{
	//const auto& [line, column] = position;  ???
	return m_map[position.first][position.second];
}

uint16_t Map::GetWidth() const
{
	return uint16_t(m_width);
}

uint16_t Map::GetLength() const
{
	return uint16_t(m_length);
}

Map::Stage Map::GetStage() const
{
	return m_stage;
}

uint16_t Map::GetLevel() const
{
	return m_level;
}

void Map::SetBlock(Block::Type type, uint16_t coordX, uint16_t coordY)
{
	delete m_map[coordX][coordY];
	m_map[coordX][coordY] = new Block(type);
}

std::ostream& operator<<(std::ostream& out, const Map& map)
{
	switch (map.m_stage)
	{
	case Map::Stage::TheWall:
		out << "The Wall --- ";
		break;
	case Map::Stage::RockyMountains:
		out << "Rocky Mountains --- ";
		break;
	case Map::Stage::River:
		out << "River --- ";
		break;
	case Map::Stage::Forest:
		out << "Forest --- ";
		break;
	case Map::Stage::LavaCave:
		out << "Lava Cave --- ";
		break;
	case Map::Stage::InsideOfTheCastlePartI:
		out << "Inside Of The Castle Part I --- ";
		break;
	case Map::Stage::InsideOfTheCastlePartII:
		out << "Inside Of The Castle Part II --- ";
		break;
	case Map::Stage::InsideOfTheCastlePartIII:
		out << "Inside Of The Castle Part III --- ";
		break;
	default:
		break;
	}
	out << "Round " << map.m_level;
	return out;
}
