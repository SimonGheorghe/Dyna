#include "Block.h"

Block::Block(Type type):
m_type(type)
{
}

bool Block::isBlock()
{
	return true;
}

Block::Type Block::GetType() const
{
	return m_type;
}

std::ostream& operator<<(std::ostream& out, const Block& block)
{
	char ch;
	
	if (block.m_type == Block::Type::HardBlock)
	{
		ch = 178;
		out << ch << ch;
	}
	if (block.m_type == Block::Type::SoftBlock)
	{
		ch = 177;
		out << ch << ch;
	}
	if (block.m_type == Block::Type::NoneBlock)
	{
		ch = 176;
		out << "  ";
	}
	return out;
}
