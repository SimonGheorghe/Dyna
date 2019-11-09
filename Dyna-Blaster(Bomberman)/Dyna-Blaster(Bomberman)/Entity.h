#pragma once
#include "Block.h"
#include "Bomb.h"
#include "Monster.h"

class Entity
{
public:
	enum class Type
	{
		HardBlock,
		SoftBlock,
		Bomb,
		Monster
	};

public:
	Entity(Block block, Block::Type type);
	Entity(Bomb bomb);
	Entity(Monster monster, Monster::Type type);

private:
	Type m_type;
	Block* m_block;
	Bomb* m_bomb;
	Monster* m_monster;
};

