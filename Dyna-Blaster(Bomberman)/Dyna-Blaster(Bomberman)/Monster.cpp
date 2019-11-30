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
	case Monster::Type::Frog:
	{
		m_speed = Speed::Slow;
		m_hitPoints = 1;
		m_score = 500;
		m_passingAbility = false;
	}
	break;
	case Monster::Type::BlueJelly:
	{
		m_speed = Speed::Slow;
		m_hitPoints = 1;
		m_score = 500;
		m_passingAbility = false;
	}
	break;
	case Monster::Type::SnakeHead:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 6;
		m_score = 1000;
		m_passingAbility = false;
	}
	break;
	case Monster::Type::SnakeBody:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 6;
		m_score = 1000;
		m_passingAbility = false;
	}
	break;
	case Monster::Type::SnakeTail:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 6;
		m_score = 1000;
		m_passingAbility = false;
	}
	break;
	case Monster::Type::Bubbles:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 3;
		m_score = 1000;
		m_passingAbility = false;
	}
	break;
	case Monster::Type::BabyBubbles:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 1;
		m_score = 1000;
		m_passingAbility = false;
	}
	break;
	case Monster::Type::WarpMan:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 3;
		m_score = 1000;
		m_passingAbility = false;
	}
	break;
	case Monster::Type::YoungWarpMan:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 3;
		m_score = 1000;
		m_passingAbility = false;
	}
	break;
	case Monster::Type::Spidfire:
	{
		m_speed = Speed::Normal;
		m_hitPoints = 3;
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

uint16_t Monster::GetCoordX() const
{
	return m_coordX;
}

uint16_t Monster::GetCoordY() const
{
	return m_coordY;
}

uint16_t Monster::GetLastY() const
{
	return m_lastY;
}

uint16_t Monster::GetLastX() const
{
	return m_lastX;

}

void Monster::DropHitPoints()
{
	--m_hitPoints;
}

void Monster::Place(Map& map)
{
	do {
		m_coordX = rand() % (map.GetLength() - 2) + 1;
		m_coordY = rand() % (map.GetWidth() - 2) + 1;
	} while (!dynamic_cast<Block*>(map[{m_coordX, m_coordY}]) ||
		dynamic_cast<Block*>(map[{m_coordX, m_coordY}])->GetType() != Block::Type::NoneBlock ||
		(m_coordX == 1 || m_coordX == 2) && (m_coordY == 1 || m_coordY == 2));//we don't want monsters to spawn near player
	m_lastX = m_coordX;
	m_lastY = m_coordY;
}

void Monster::Move(Map map, const Player& player)
{
	switch (m_type)
	{
	case Monster::Type::Ballom:
		Alg1(map, player);
		break;
	case Monster::Type::Ekutopu:
		Alg2(map, player);
		break;
	case Monster::Type::Boyon:
		Alg3(map, player);
		break;
	case Monster::Type::Pass:
		Alg3(map, player);
		break;
	case Monster::Type::Telpio:
		Alg3(map, player);
		break;
	case Monster::Type::Pomori:
		Alg3(map, player);
		break;
	case Monster::Type::Onil:
		Alg3(map, player);
		break;
	case Monster::Type::Gacha:
		Alg3(map, player);
		break;
	case Monster::Type::Minvo:
		Alg3(map, player);
		break;
	case Monster::Type::Buffer:
		Alg3(map, player);
		break;
	case Monster::Type::Peggi:
		Alg3(map, player);
		break;
	case Monster::Type::Flapper:
		Alg3(map, player);
		break;
	case Monster::Type::BakeBake:
		Alg3(map, player);
		break;
	case Monster::Type::Korisuke:
		Alg3(map, player);
		break;
	case Monster::Type::Maron:
		Alg3(map, player);
		break;
	case Monster::Type::Ojin:
		Alg3(map, player);
		break;
	case Monster::Type::Pontan:
		Alg3(map, player);
		break;
	default:
		break;
	}
}



void Monster::Alg1(Map map, const Player& player)
{
	bool moved[4] = { 1, 1, 1, 1 };
	bool ok = 0;
	uint16_t step = 0;
	do {
		if (m_coordX == m_lastX && m_coordY == m_lastY) // start position
			step = rand() % 4;

		//do the same move or a random one if the same is not possible
		if (m_lastY == m_coordY + 1)
			if (moved[0] == 1)
				step = 0;
			else
				step = rand() % 3 + 1;

		if (m_lastY == m_coordY - 1)
			if (moved[1] == 1)
				step = 1;
			else
				do {
					step = rand() % 4;
				} while (step == 1);

		if (m_lastX == m_coordX + 1)
			if (moved[2] == 1)
				step = 2;
			else
				do {
					step = rand() % 4;
				} while (step == 2);

		if (m_lastX == m_coordX - 1)
			if (moved[3] == 1)
				step = 3;
			else
				step = rand() % 3;

		moved[step] = MoveVerif(step, map, player);

		//monster has moved or he can't move
		if (moved[step] == 1 || (moved[0] == 0 && moved[1] == 0 && moved[2] == 0 && moved[3] == 0))
			ok = 1;
	} while (!ok);
}

void Monster::Alg2(Map map, const Player& player)
{
	bool moved[4] = { 1, 1, 1, 1 };
	bool ok = 0;
	do {
		uint16_t step = rand() % 4;
		moved[step]=MoveVerif(step, map, player);

		//monster has moved or he can't move
		if (moved[step] == 1 || (moved[0] == 0 && moved[1] == 0 && moved[2] == 0 && moved[3] == 0))
			ok = 1;
	} while (!ok);
}

void Monster::Alg3(Map map, const Player& player)
{
	bool moved[4] = { 1, 1, 1, 1 };
	bool ok = 0;
	do {
		uint16_t step = rand() % 4;

		//monster can't go the same block it came only if it has to
		if ((!(step == 0 && m_lastY == m_coordY - 1) || moved[0] == 1 && moved[1] == 0 && moved[2] == 0 && moved[3] == 0) &&
			(!(step == 1 && m_lastY == m_coordY + 1) || moved[0] == 0 && moved[1] == 1 && moved[2] == 0 && moved[3] == 0) &&
			(!(step == 2 && m_lastX == m_coordX - 1) || moved[0] == 0 && moved[1] == 0 && moved[2] == 1 && moved[3] == 0) &&
			(!(step == 3 && m_lastX == m_coordX + 1) || moved[0] == 0 && moved[1] == 0 && moved[2] == 0 && moved[3] == 1))
		{
			moved[step] = MoveVerif(step, map, player);

			//monster has moved or he can't move
			if (moved[step] == 1 || (moved[0] == 0 && moved[1] == 0 && moved[2] == 0 && moved[3] == 0))
				ok = 1;
		}
	} while (!ok);
}

bool Monster::MoveVerif(uint16_t step, Map map, const Player& player)
{
	bool moved = false;
	//step=0 -> left
	//step=1 -> right
	//step=2 -> up
	//step=3 -> down
	switch (step)
	{
	case 0:
		if (dynamic_cast<Powers*>(map[{m_coordX, m_coordY - 1}]) &&
			(dynamic_cast<Powers*>(map[{m_coordX, m_coordY - 1}])->GetPowerStatus() == 0 ||
				dynamic_cast<Powers*>(map[{m_coordX, m_coordY - 1}])->GetPowerStatus() == 1 && m_passingAbility) ||
			dynamic_cast<Block*>(map[{m_coordX, m_coordY - 1}]) &&
			(dynamic_cast<Block*>(map[{m_coordX, m_coordY - 1}])->GetType() != Block::Type::SoftBlock &&
				dynamic_cast<Block*>(map[{m_coordX, m_coordY - 1}])->GetType() != Block::Type::HiddenExit
				|| m_passingAbility) &&
			dynamic_cast<Block*>(map[{m_coordX, m_coordY - 1}])->GetType() != Block::Type::HardBlock)
		{
			bool ok = 1;
			for (int index = 0; index < player.GetNoOfPlacedBombs(); ++index)
				if (player[index]->GetCoordX() == m_coordX && player[index]->GetCoordY() == m_coordY - 1)
					ok = 0;
			if (ok)
			{
				m_lastY = m_coordY;
				m_lastX = m_coordX;
				--m_coordY;
				moved = true;
			}
		}
		break;
	case 1:
		if (dynamic_cast<Powers*>(map[{m_coordX, m_coordY + 1}]) &&
			(dynamic_cast<Powers*>(map[{m_coordX, m_coordY + 1}])->GetPowerStatus() == 0 ||
				dynamic_cast<Powers*>(map[{m_coordX, m_coordY + 1}])->GetPowerStatus() == 1 && m_passingAbility) ||
			dynamic_cast<Block*>(map[{m_coordX, m_coordY + 1}]) &&
			(dynamic_cast<Block*>(map[{m_coordX, m_coordY + 1}])->GetType() != Block::Type::SoftBlock &&
				dynamic_cast<Block*>(map[{m_coordX, m_coordY + 1}])->GetType() != Block::Type::HiddenExit
				|| m_passingAbility) &&
			dynamic_cast<Block*>(map[{m_coordX, m_coordY + 1}])->GetType() != Block::Type::HardBlock)
		{
			bool ok = 1;
			for (int index = 0; index < player.GetNoOfPlacedBombs(); ++index)
				if (player[index]->GetCoordX() == m_coordX && player[index]->GetCoordY() == m_coordY + 1)
					ok = 0;
			if (ok)
			{
				m_lastY = m_coordY;
				m_lastX = m_coordX;
				++m_coordY;
				moved = true;
			}
		}
		break;
	case 2:
		if (dynamic_cast<Powers*>(map[{m_coordX - 1, m_coordY}]) &&
			(dynamic_cast<Powers*>(map[{m_coordX - 1, m_coordY}])->GetPowerStatus() == 0 ||
				dynamic_cast<Powers*>(map[{m_coordX - 1, m_coordY}])->GetPowerStatus() == 1 && m_passingAbility) ||
			dynamic_cast<Block*>(map[{m_coordX - 1, m_coordY}]) &&
			(dynamic_cast<Block*>(map[{m_coordX - 1, m_coordY}])->GetType() != Block::Type::SoftBlock &&
				dynamic_cast<Block*>(map[{m_coordX - 1, m_coordY}])->GetType() != Block::Type::HiddenExit
				|| m_passingAbility) &&
			dynamic_cast<Block*>(map[{m_coordX - 1, m_coordY}])->GetType() != Block::Type::HardBlock)
		{
			bool ok = 1;
			for (int index = 0; index < player.GetNoOfPlacedBombs(); ++index)
				if (player[index]->GetCoordX() == m_coordX - 1 && player[index]->GetCoordY() == m_coordY)
					ok = 0;
			if (ok)
			{
				m_lastX = m_coordX;
				m_lastY = m_coordY;
				--m_coordX;
				moved = true;
			}
		}
		break;
	case 3:
		if (dynamic_cast<Powers*>(map[{m_coordX + 1, m_coordY}]) &&
			(dynamic_cast<Powers*>(map[{m_coordX + 1, m_coordY}])->GetPowerStatus() == 0 ||
				dynamic_cast<Powers*>(map[{m_coordX + 1, m_coordY}])->GetPowerStatus() == 1 && m_passingAbility) ||
			dynamic_cast<Block*>(map[{m_coordX + 1, m_coordY}]) &&
			(dynamic_cast<Block*>(map[{m_coordX + 1, m_coordY}])->GetType() != Block::Type::SoftBlock &&
				dynamic_cast<Block*>(map[{m_coordX + 1, m_coordY}])->GetType() != Block::Type::HiddenExit
				|| m_passingAbility) &&
			dynamic_cast<Block*>(map[{m_coordX + 1, m_coordY}])->GetType() != Block::Type::HardBlock)
		{
			bool ok = 1;
			for (int index = 0; index < player.GetNoOfPlacedBombs(); ++index)
				if (player[index]->GetCoordX() == m_coordX + 1 && player[index]->GetCoordY() == m_coordY)
					ok = 0;
			if (ok)
			{
				m_lastX = m_coordX;
				m_lastY = m_coordY;
				++m_coordX;
				moved = true;
			}
		}
		break;
	}
	return moved;
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
	case Monster::Type::Frog:
		out << "Fr";
		break;
	case Monster::Type::BlueJelly:
		out << "Bj";
		break;
	case Monster::Type::SnakeHead:
		out << "SH";
		break;
	case Monster::Type::SnakeBody:
		out << "SB";
		break;
	case Monster::Type::SnakeTail:
		out << "ST";
		break;
	case Monster::Type::Bubbles:
		out << "BB";
		break;
	case Monster::Type::BabyBubbles:
		out << "Bb";
		break;
	case Monster::Type::WarpMan:
		out << "WM";
		break;
	case Monster::Type::YoungWarpMan:
		out << "YM";
		break;
	case Monster::Type::Spidfire:
		out << "SF";
		break;

	default:
		out << "??";
		break;
	}
	return out;
}
