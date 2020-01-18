#include "Block.h"

Block::Block(Type type, const float x, const float y, sf::Texture& texture):
m_type(type)
{
	m_sprite.setSize(sf::Vector2f(32,32));
	m_sprite.setTexture(&texture);
	m_sprite.setPosition(x, y);
}

Block::Type Block::GetType() const
{
	return m_type;
}

void Block::Render(sf::RenderTarget& target)
{
	target.draw(m_sprite);
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
