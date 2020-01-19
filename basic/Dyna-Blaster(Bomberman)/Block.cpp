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

Block& Block::operator=(const Block& other)
{
	m_type = other.m_type;
	std::cout << "Copy constr.\n";
	return *this;
}

Block& Block::operator=(Block&& other)
{
	m_type = other.m_type;
	other.m_type = Block::Type::NoneBlock;
	std::cout << "Move constr.\n";
	return *this;
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
		out << ch << ch;
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
	case Block::Type::HiddenExit:
		ch = 176;
		out << ch << ch;
		break;
	case Block::Type::Exit:
		out << char(185) << char(204);
		break;
	default:
		break;
	}
	return out;
}
