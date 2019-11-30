#pragma once
#include<iostream>
#include<cstdint>
#include "Player.h"

class Monster
{
public:
	enum class Type
	{
		Ballom = 0, 
		Ekutopu,
		Boyon,
		Pass,
		Telpio,
		Pomori,
		Onil,
		Gacha,
		Minvo,
		Buffer,
		Peggi,
		Flapper,
		BakeBake,
		Korisuke,
		Maron,
		Ojin,
		Pontan,
		Frog,
		BlueJelly,
		SnakeHead,
		SnakeBody,
		SnakeTail,
		Bubbles,
		BabyBubbles,
		WarpMan,
		YoungWarpMan,
		Spidfire
	};
	enum class Speed
	{
		None = 0,
		Slow,
		Normal,
		Fast,
		VeryFast
	};

public:
	Monster(Type type);

	Type GetType() const;
	Speed GetSpeed() const;
	uint16_t GetHitPoints() const;
	uint16_t GetScore() const;
	bool GetPassingAbility() const;
	uint16_t GetCoordX() const;
	uint16_t GetCoordY() const;
	uint16_t GetLastY() const;
	uint16_t GetLastX() const;

	void DropHitPoints();

	friend std::ostream& operator<<(std::ostream& out, const Monster& monster);
	
	//void GenerateMonster(std::vector<Monster*>& enemies, const Map& map);
	void Place(Map& map);
	void Move(Map map, const Player& player);

private:

	void Alg1(Map map, const Player& player);
	void Alg2(Map map, const Player& player);
	bool MoveVerif(uint16_t step, Map map, const Player& player);
	void Alg3(Map map, const Player& player);
	void Alg4(Map map, const Player& player);

private:
	uint16_t m_coordX = -1;
	uint16_t m_coordY = -1;
	uint16_t m_lastX = -1;
	uint16_t m_lastY = -1;

	Type m_type;
	Speed m_speed;
	uint16_t m_hitPoints;
	uint16_t m_score;
	bool m_passingAbility;
};

