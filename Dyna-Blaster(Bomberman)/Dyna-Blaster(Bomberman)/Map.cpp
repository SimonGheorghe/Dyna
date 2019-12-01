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
		m_map[coordX][coordY] = new Block(Block::Type::HiddenExit);
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

Powers::Type RandomPower()
{
	uint16_t noOfPowerTypes = 8;
	return Powers::Type(rand() % noOfPowerTypes);
}

void Map::GeneratePower()
{
	do {
		m_powerX = rand() % (uint16_t)m_length;
		m_powerY = rand() % (uint16_t)m_width;
	} while (dynamic_cast<Block*>(m_map[m_powerX][m_powerY])->GetType() != Block::Type::NoneBlock ||
		(m_powerX == 1 || m_powerX == 2) && (m_powerY == 1 || m_powerY == 2));
	//we dont want to place the power in player's zone

	if (m_level == 7)
		return;
	if (m_stage == Map::Stage::TheWall)
		switch (m_level)
		{
		case 0:
			m_power = Powers::Type::FireUp;
			break;
		case 1:
			m_power = Powers::Type::BombUp;
			break;
		case 2:
			m_power = Powers::Type::SkateUp;
			break;
		case 3:
			m_power = Powers::Type::RemoteControl;
			break;
		case 4:
			m_power = Powers::Type::BombPass;
			break;
		case 5:
			m_power = Powers::Type::Heart;
			break;
		case 6:
			m_power = Powers::Type::SoftBlockPass;
			break;
		default:
			break;
		}
	else
		m_power = RandomPower();

	delete m_map[m_powerX][m_powerY];
	m_map[m_powerX][m_powerY] = new Powers(m_power);
}

void Map::DeletePower()
{
	delete m_map[m_powerX][m_powerY];
	m_map[m_powerX][m_powerY] = new Block(Block::Type::NoneBlock);
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

uint16_t Map::GetPowerX() const
{
	return m_powerX;
}

uint16_t Map::GetPowerY() const
{
	return m_powerY;
}

Powers::Type Map::GetPowerType() const
{
	return m_power;
}

void Map::SetBlock(Block::Type type, uint16_t coordX, uint16_t coordY)
{
	if (m_map[coordX][coordY] != nullptr)
		delete m_map[coordX][coordY];
	m_map[coordX][coordY] = new Block(type);
}

void Map::SetBomb(Bomb* bomb)
{
	m_map[bomb->GetCoordX()][bomb->GetCoordY()] = bomb;
}

void Map::ClearMap(uint16_t index1, uint16_t index2)
{
	if (dynamic_cast<Block*>(m_map[index1][index2]))
	{
		Block* block = dynamic_cast<Block*>(m_map[index1][index2]);
		if (block->GetType() == Block::Type::ExplodedBlock ||
			block->GetType() == Block::Type::ExplodedBomb ||
			block->GetType() == Block::Type::HorizontalFire ||
			block->GetType() == Block::Type::VerticalFire)
		{
			delete m_map[index1][index2];
			m_map[index1][index2] = new Block(Block::Type::NoneBlock);
		}
	}
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
