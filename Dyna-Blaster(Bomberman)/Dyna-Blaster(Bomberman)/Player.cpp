#include "Player.h"
#include <conio.h>

Player::Player(uint16_t numberBombs, uint16_t health, uint32_t score, uint16_t speed, uint16_t coordX, uint16_t coordY) :m_noOfBombs(numberBombs), m_health(health), m_score(score), m_speed(speed), m_coordX(coordX), m_coordY(coordY)
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

void Player::SetVest(bool up)
{
	m_vest = up;
}

void Player::SetRemoteControl(bool up)
{
	m_remoteControl = up;
}

void Player::Place(Map& map)
{
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

void Player::Move(Map& map)
{
	char ch = _getch();
	switch (ch)
	{
	case 'W':
	case 'w':
	{
		if (dynamic_cast<Block*>(map[{m_coordX - 1, m_coordY}])->GetType() == Block::Type::NoneBlock)
			--m_coordX;
	}
	break;
	case 'A':
	case 'a':
	{
		if (dynamic_cast<Block*>(map[{m_coordX, m_coordY - 1}])->GetType() == Block::Type::NoneBlock)
			--m_coordY;
	}
	break;
	case 's':
	case 'S':
	{
		if (dynamic_cast<Block*>(map[{m_coordX + 1, m_coordY}])->GetType() == Block::Type::NoneBlock)
			++m_coordX;
	}
	break;
	case 'D':
	case 'd':
	{
		if (dynamic_cast<Block*>(map[{m_coordX, m_coordY + 1}])->GetType() == Block::Type::NoneBlock)
			++m_coordY;
	}
	break;

	}
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	return out << "[]";
}
