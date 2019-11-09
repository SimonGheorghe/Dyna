
#include<iostream>
#include<cstdint>
#include<vector>
#include"Block.h"
#include<array>

class Map
{
public:
	enum class Stage
	{
		TheWall = 0, 
		RockyMountains,
		River,
		Forest,
		LavaCave,
		InsideOfTheCastlePartI,
		InsideOfTheCastlePartII,
		InsideOfTheCastlePartIII	
	};
	enum class Width
	{
		Narrow = 15,
		Wide = 31
	};
	enum class Length
	{
		Short = 13,
		Long = 29
	};

public:
	Map(Stage Stage, uint16_t Level);
	void GenerateMapDimensions();
	friend std::istream& operator>>(std::istream& in, Map& map);

private:
	static const uint16_t noOfStagesAndLevels = 8;
	std::array<std::array<std::string, noOfStagesAndLevels>, noOfStagesAndLevels> mapSize;

private:
	Stage m_stage;
	uint16_t m_level;
	Width m_width;
	Length m_length;
	std::vector<std::vector<Block>> m_map;
};

