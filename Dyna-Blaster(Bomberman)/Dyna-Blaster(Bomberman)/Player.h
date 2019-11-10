#pragma once
#include <cstdint>
#include<string>

using pair = std::pair<uint8_t, uint8_t>;
class Player
{
public:
	enum class Speed
	{
		None = 0,
		Slow,
		Normal,
		Fast,
		VeryFast
	};
public:
	Player(uint8_t numberBombs, uint8_t numberLifes, uint32_t score, Speed speed);
	uint8_t GetNumberBombs();
	uint8_t GetNumberLifes();
	uint32_t GetScore();
	Speed GetSpeed();
	//~Player();

private:
	uint8_t m_numberBombs : 4;
	uint8_t m_numberLifes : 4;
	uint32_t m_score;
	Speed m_speed;
};

