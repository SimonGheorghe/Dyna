
#include<iostream>
#include<cstdint>
#include<vector>
#include<array>
#include "Block.h"
#include "Powers.h"
#include "Bomb.h"

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
		None = 0,
		Narrow = 15,
		Wide = 31
	};

	enum class Length
	{
		None = 0,
		Short = 13,
		Long = 29
	};

	using Position = std::pair<uint16_t, uint16_t>;

public:
	Map(Stage Stage, uint16_t Level);
	friend std::ostream& operator<<(std::ostream& out, const Map& map);

	Map(const Map& other);
	Map(Map&& other);
	Map& operator=(const Map& other);
	Map& operator=(Map&& other);

	const Entity* operator[](const Position& position) const;
	Entity* operator[](const Position& position);

	uint16_t GetWidth() const;
	uint16_t GetLength() const;
	Stage GetStage() const;
	uint16_t GetLevel() const;
	uint16_t GetPowerX() const;
	uint16_t GetPowerY() const;
	Powers::Type GetPowerType() const;

	void SetWidth(Width width);
	void SetLength(Length length);
	void SetBlock(Block::Type type, uint16_t coordX, uint16_t coordY);
	void SetBomb(Bomb* bomb);
	
	void Create();
	void ClearMap(uint16_t index1, uint16_t index2);
	void GeneratePower();
	void DeletePower();

private:
	void GenerateBlocks();

private:
	Stage m_stage;
	uint16_t m_level;
	Width m_width;
	Length m_length;
	std::vector<std::vector<Entity*>> m_map;
	Powers::Type m_power;
	uint16_t m_powerX;
	uint16_t m_powerY;
};

