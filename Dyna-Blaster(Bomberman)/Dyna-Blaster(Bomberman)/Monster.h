#pragma once
#include<iostream>
#include<cstdint>
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
	Type GetType();
	Speed GetSpeed();
	uint16_t GetHitPoints();
	uint16_t GetScore();
	bool GetPassingAbility();


private:
	Type m_type;
	Speed m_speed;
	uint16_t m_hitPoints;
	uint16_t m_score;
	bool m_passingAbility;
};

