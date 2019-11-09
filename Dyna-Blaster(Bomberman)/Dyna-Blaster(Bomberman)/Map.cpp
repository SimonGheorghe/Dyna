#include "Map.h"

Map::Map(Stage Stage, uint16_t Level)
{
	m_stage = Stage;
	m_level = Level;
	GenerateMapDimensions();
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


std::istream& operator>>(std::istream& in, Map& map)
{
	for (int index1 = 0; index1 < map.noOfStagesAndLevels; ++index1)
		for (int index2 = 0; index2 < map.noOfStagesAndLevels; ++index2)
			in >> map.mapSize[index1][index2];
	return in;
}
