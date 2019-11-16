#include "Monster.h"

Monster::Monster(Type type) :
	m_type(type)
{
	switch (type)
	{
	case Monster::Type::Ballom:
	{
		m_speed = Speed::Slow;
		m_hitPoints = 1;
		m_score = 100;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Ekutopu:
	{
		m_speed = Speed::Slow;
		m_hitPoints = 1;
		m_score = 200;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Boyon:
	{
		m_speed = Speed::Slow;
		m_hitPoints = 1;
		m_score = 200;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Pass:
	{
		m_speed = Speed::VeryFast;
		m_hitPoints = 1;
		m_score = 500;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Telpio:
	{
		m_speed = Speed::Fast;
		m_hitPoints = 1;
		m_score = 400;
		m_passingAbility = true;
	}
		break;
	case Monster::Type::Pomori:
	{
		m_speed = Speed::VeryFast;
		m_hitPoints = 1;
		m_score = 600;
		m_passingAbility = true;
	}
		break;
	case Monster::Type::Onil:
	{
		m_speed = Speed::Slow;
		m_hitPoints = 1;
		m_score = 200;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Gacha:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 1;
		m_score = 300;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Minvo:
	{
		m_speed = Speed::Slow;//?
		m_hitPoints = 1;
		m_score = 700;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Buffer:
	{
		m_speed = Speed::Slow;
		m_hitPoints = 1;
		m_score = 300;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Peggi:
	{
		m_speed = Speed::Slow;
		m_hitPoints = 1;
		m_score = 200;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Flapper:
	{
		m_speed = Speed::Fast;
		m_hitPoints = 1;
		m_score = 400;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::BakeBake:
	{
		m_speed = Speed::Normal;//?
		m_hitPoints = 1;
		m_score = 200;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Korisuke:
	{
		m_speed = Speed::Slow;//?
		m_hitPoints = 1;
		m_score = 200;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Maron:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 1;
		m_score = 300;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Ojin://?
	{
		m_speed = Speed::Normal;
		m_hitPoints = 1;
		m_score = 400;
		m_passingAbility = false;
	}
		break;
	case Monster::Type::Pontan:
	{
		m_speed = Speed::VeryFast;
		m_hitPoints = 1;
		m_score = 1000;
		m_passingAbility = false;
	}
		break;
	default:
	{
		m_speed = Speed::None;
		m_hitPoints = 0;
		m_score = 0;
		m_passingAbility = false;
	}
		break;
	}
}

Monster::Type Monster::GetType() const
{
	return m_type;
}

Monster::Speed Monster::GetSpeed() const
{
	return m_speed;
}

uint16_t Monster::GetHitPoints() const
{
	return m_hitPoints;
}

uint16_t Monster::GetScore() const
{
	return m_score;
}

bool Monster::GetPassingAbility() const
{
	return m_passingAbility;
}

void Monster::Place(const Map& map)
{
	do {
		m_coordX = rand() % (map.GetLength() - 2) + 1;
		m_coordY = rand() % (map.GetWidth() - 2) + 1;
	} while (map[{m_coordX, m_coordY}] != nullptr);
	m_lastX = m_coordX;
	m_lastY = m_coordY;
}

std::ostream& operator<<(std::ostream& out, const Monster& monster)
{
	switch (monster.GetType())
	{
	case Monster::Type::Ballom:
		out << "Ba";
		break;
	case Monster::Type::Ekutopu:
		out << "Ek";
		break;
	case Monster::Type::Boyon:
		out << "Bo";
		break;
	case Monster::Type::Pass:
		out << "Pa";
		break;
	case Monster::Type::Telpio:
		out << "Te";
		break;
	case Monster::Type::Pomori:
		out << "Po";
		break;
	case Monster::Type::Onil:
		out << "On";
		break;
	case Monster::Type::Gacha:
		out << "Ga";
		break;
	case Monster::Type::Minvo:
		out << "Mi";
		break;
	case Monster::Type::Buffer:
		out << "Bu";
		break;
	case Monster::Type::Peggi:
		out << "Pe";
		break;
	case Monster::Type::Flapper:
		out << "Fl";
		break;
	case Monster::Type::BakeBake:
		out << "Bk";
		break;
	case Monster::Type::Korisuke:
		out << "Ko";
		break;
	case Monster::Type::Maron:
		out << "Ma";
		break;
	case Monster::Type::Ojin:
		out << "Oj";
		break;
	case Monster::Type::Pontan:
		out << "Po";
		break;
	default:
		out << "??";
		break;
	}
	return out;
}
