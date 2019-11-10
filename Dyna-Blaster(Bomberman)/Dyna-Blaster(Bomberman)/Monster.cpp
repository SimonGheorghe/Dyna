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

Monster::Type Monster::GetType()
{
	return m_type;
}

Monster::Speed Monster::GetSpeed()
{
	return m_speed;
}

uint16_t Monster::GetHitPoints()
{
	return m_hitPoints;
}

uint16_t Monster::GetScore()
{
	return m_score;
}

bool Monster::GetPassingAbility()
{
	return m_passingAbility;
}

void Monster::MoveUp()
{
	--m_coordY;
}

void Monster::MoveDown()
{
	++m_coordY;
}

void Monster::MoveRight()
{
	++m_coordX;
}

void Monster::MoveLeft()
{
	--m_coordX;
}


