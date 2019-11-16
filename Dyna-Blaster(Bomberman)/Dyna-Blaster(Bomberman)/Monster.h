#pragma once
#include<iostream>
#include<cstdint>
#include "Map.h"

class Monster
{
public:
	enum class Type
	{
		Ballom,
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
		Pontan
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

	friend std::ostream& operator<<(std::ostream& out, const Monster& monster);

	void Place(const Map& map);

private:
	uint16_t m_coordX;
	uint16_t m_coordY;
	uint16_t m_lastX;
	uint16_t m_lastY;

	Type m_type;
	Speed m_speed;
	uint16_t m_hitPoints;
	uint16_t m_score;
	bool m_passingAbility;
};

