#include "Block.h"

Block::Block(Type type):
m_type(type)
{
}

bool Block::isBlock()
{
	return true;
}

Block::Type Block::GetType()
{
	return m_type;
}


