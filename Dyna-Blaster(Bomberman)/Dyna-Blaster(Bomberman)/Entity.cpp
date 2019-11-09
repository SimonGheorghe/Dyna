#include "Entity.h"

Entity::Entity(Block block, Block::Type type)
{
	m_block = new Block(type);
}

Entity::Entity(Bomb bomb)
{
	m_bomb = new Bomb;
}

Entity::Entity(Monster monster, Monster::Type type)
{
	m_monster = new Monster(type);
}
