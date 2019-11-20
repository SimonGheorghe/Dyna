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

uint16_t Block::GetExitX() const
{
	return m_exitX;
}

uint16_t Block::GetExitY() const
{
	return m_exitY;
}

bool Block::GetExitStatus() const
{
	return m_exitIsHidden;
}

void Block::SetExitX(uint16_t coordX)
{
	m_exitX = coordX;
}

void Block::SetExitY(uint16_t coordY)
{
	m_exitY = coordY;
}

void Block::SetExitStatus(bool value)
{
	m_exitIsHidden = value;
}

std::ostream& operator<<(std::ostream& out, const Block& block)
{
	char ch;
	switch (block.m_type)
	{
	case Block::Type::HardBlock:
		ch = 178;
		out << ch << ch;
		break;
	case Block::Type::SoftBlock:
		ch = 177;
		out << ch << ch;
		break;
	case Block::Type::NoneBlock:
		out << "  ";
		break;
	case Block::Type::ExplodedBlock:
		ch = 176;
		out << ch << ch;
		break;
	case Block::Type::HorizontalFire:
		ch = 205;
		out << ch<<ch;
		break;
	case Block::Type::VerticalFire:
		ch = 179;
		out << ch << ch;
		/*
		ch=186;
		out<<ch<<" ";
		*/
		break;
	case Block::Type::ExplodedBomb:
		out << "{}";
		break;
	case Block::Type::Exit:
		if (block.m_exitIsHidden)
		{
			ch = 176;
			out << ch << ch;
		}
		else
		{
			out << char(185) << char(204);
		}
		break;
	default:
		break;
	}
	return out;
}
