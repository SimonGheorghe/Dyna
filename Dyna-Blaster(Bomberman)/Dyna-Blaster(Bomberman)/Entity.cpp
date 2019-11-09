#include "Entity.h"

Entity::Entity(Block::Type type)
{
	if (type == Block::Type::HardBlock)
		m_type = Entity::Type::HardBlock;
	else
		m_type = Entity::Type::SoftBlock;
	m_block = new Block(type);
}

Entity::Entity(Bomb bomb)
{
	m_type = Entity::Type::Bomb;
	m_bomb = new Bomb;
}

Entity::Entity(Monster::Type type)
{
	m_type = Entity::Type::Monster;
	m_monster = new Monster(type);
}

Entity::Entity()
{
	//empty
}
