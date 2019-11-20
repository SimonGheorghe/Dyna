#include "Player.h"

Player::Player(uint16_t fire, uint16_t numberBombs, uint16_t health, uint32_t score, uint16_t speed) :
	m_fire(fire), m_noOfBombs(numberBombs), m_health(health), m_score(score), m_speed(speed)
{
}

void Player::SetFire(uint16_t up)
{
	m_fire = up;
}

uint16_t Player::GetFire() const
{
	return m_fire;
}

void Player::SetNoOfBombs(uint16_t up)
{
	m_noOfBombs = up;
}

uint16_t Player::GetNoOfBombs() const
{
	return m_noOfBombs;
}

uint16_t Player::GetSpeed() const
{
	return m_speed;
}

void Player::SetSpeed(uint16_t up)
{
	m_speed = up;
}

void Player::SetSoftBlockPass(bool up)
{
	m_softBlockPass = up;
}

void Player::SetBombPass(bool up)
{
	m_bombPass = up;
}

void Player::SetHealth(uint16_t up)
{
	m_health = up;
}

uint16_t Player::GetHealth() const
{
	return m_health;
}

uint16_t Player::GetCoordX() const
{
	return m_coordX;
}

uint16_t Player::GetCoordY() const
{
	return m_coordY;
}

uint16_t Player::GetNoOfPlacedBombs() const
{
	return m_placedBombs.size();
}

void Player::SetVest(bool up)
{
	m_vest = up;
}

void Player::SetRemoteControl(bool up)
{
	m_remoteControl = up;
}

void Player::Place(Map& map, uint16_t coordX, uint16_t coordY)
{
	m_coordX = coordX;
	m_coordY = coordY;
	map.SetBlock(Block::Type::NoneBlock, m_coordX, m_coordY);
	if (dynamic_cast<Block*>(map[{m_coordX - 1, m_coordY}])->GetType() == Block::Type::SoftBlock)
		map.SetBlock(Block::Type::NoneBlock, m_coordX - 1, m_coordY);
	if (dynamic_cast<Block*>(map[{m_coordX + 1, m_coordY}])->GetType() == Block::Type::SoftBlock)
		map.SetBlock(Block::Type::NoneBlock, m_coordX + 1, m_coordY);
	if (dynamic_cast<Block*>(map[{m_coordX, m_coordY - 1}])->GetType() == Block::Type::SoftBlock)
		map.SetBlock(Block::Type::NoneBlock, m_coordX, m_coordY - 1);
	if (dynamic_cast<Block*>(map[{m_coordX, m_coordY + 1}])->GetType() == Block::Type::SoftBlock)
		map.SetBlock(Block::Type::NoneBlock, m_coordX, m_coordY + 1);
}

void Player::Move(Map& map, char ch)
{
	switch (ch)
	{
	case 'W':
	case 'w':
	{
		if (dynamic_cast<Block*>(map[{m_coordX - 1, m_coordY}])->GetType() == Block::Type::NoneBlock || 
			dynamic_cast<Block*>(map[{m_coordX - 1, m_coordY}])->GetType() == Block::Type::Exit &&
			dynamic_cast<Block*>(map[{m_coordX - 1, m_coordY}])->GetExitStatus() == 0)
		{
			bool ok = 1;
			if (!m_bombPass)
				for (int index = 0; index < m_placedBombs.size(); ++index)
					if (m_placedBombs[index]->GetCoordX() == m_coordX - 1 && m_placedBombs[index]->GetCoordY() == m_coordY)
						ok = 0;
			if (ok)
				--m_coordX;
		}
	}
	break;
	case 'A':
	case 'a':
	{
		if (dynamic_cast<Block*>(map[{m_coordX, m_coordY - 1}])->GetType() == Block::Type::NoneBlock ||
			dynamic_cast<Block*>(map[{m_coordX, m_coordY - 1}])->GetType() == Block::Type::Exit &&
			dynamic_cast<Block*>(map[{m_coordX, m_coordY - 1}])->GetExitStatus() == 0)

		{
			bool ok = 1;
			if (!m_bombPass)
				for (int index = 0; index < m_placedBombs.size(); ++index)
					if (m_placedBombs[index]->GetCoordX() == m_coordX && m_placedBombs[index]->GetCoordY() == m_coordY - 1)
						ok = 0;
			if (ok)
				--m_coordY;
		}
	}
	break;
	case 's':
	case 'S':
	{
		if (dynamic_cast<Block*>(map[{m_coordX + 1, m_coordY}])->GetType() == Block::Type::NoneBlock ||
			dynamic_cast<Block*>(map[{m_coordX + 1, m_coordY}])->GetType() == Block::Type::Exit &&
			dynamic_cast<Block*>(map[{m_coordX + 1, m_coordY}])->GetExitStatus() == 0)

		{
			bool ok = 1;
			if (!m_bombPass)
				for (int index = 0; index < m_placedBombs.size(); ++index)
					if (m_placedBombs[index]->GetCoordX() == m_coordX + 1 && m_placedBombs[index]->GetCoordY() == m_coordY)
						ok = 0;
			if (ok)
				++m_coordX;
		}
	}
	break;
	case 'D':
	case 'd':
	{
		if (dynamic_cast<Block*>(map[{m_coordX, m_coordY + 1}])->GetType() == Block::Type::NoneBlock ||
			dynamic_cast<Block*>(map[{m_coordX, m_coordY + 1}])->GetType() == Block::Type::Exit &&
			dynamic_cast<Block*>(map[{m_coordX, m_coordY + 1}])->GetExitStatus() == 0)
		{
			bool ok = 1;
			if (!m_bombPass)
				for (int index = 0; index < m_placedBombs.size(); ++index)
					if (m_placedBombs[index]->GetCoordX() == m_coordX && m_placedBombs[index]->GetCoordY() == m_coordY + 1)
						ok = 0;
			if (ok)
				++m_coordY;
		}
	}
	break;
	case 'E':
	case 'e':
	{
		// no movement
	}
	break;

	}
}

void Player::PlaceBomb(Map& map)
{
	bool ok = 1;
	for (int index = 0; index < m_placedBombs.size(); ++index)
		if (m_placedBombs[index]->GetCoordX() == m_coordX && m_placedBombs[index]->GetCoordY() == m_coordY)
			ok = 0;
	if (dynamic_cast<Block*>(map[{m_coordX, m_coordY}])->GetType() == Block::Type::Exit)
		ok = 0;
	if (ok) 
	{
		Bomb* bomb= new Bomb(m_coordX, m_coordY, m_placedBombs.size());
		m_placedBombs.push_back(bomb);
		m_noOfBombs--;
	}
}

void Player::DeleteBomb(int bombId)
{
	//m_placedBombs.erase(m_placedBombs.begin() + bombId -1);
	delete m_placedBombs[bombId];
	for (int index = bombId; index < m_placedBombs.size() - 1; ++index)
		m_placedBombs[index] = m_placedBombs[(uint16_t)1 + index];
	m_placedBombs.resize(m_placedBombs.size() - 1);
	m_noOfBombs++;
}

Bomb* Player::operator[](int index)
{
	return m_placedBombs[index];
}

const Bomb* Player::operator[](int index) const
{
	return m_placedBombs[index];
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	return out << "[]";
}
