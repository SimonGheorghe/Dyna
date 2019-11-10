#include "Player.h"
#include <conio.h>

Player::Player(uint16_t numberBombs, uint16_t health, uint32_t score, uint16_t speed, uint16_t coordX, uint16_t coordY) :m_noOfBombs(numberBombs), m_health(health), m_score(score), m_speed(speed), m_coordX(coordX), m_coordY(coordY)
{
}

void Player::SetFire(uint16_t up)
{
	m_fire = up;
}

uint16_t Player::GetFire()
{
	return m_fire;
}

void Player::SetNoOfBombs(uint16_t up)
{
	m_noOfBombs = up;
}

uint16_t Player::GetNoOfBombs()
{
	return m_noOfBombs;
}

uint16_t Player::GetSpeed()
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

uint16_t Player::GetHealth()
{
	return m_health;
}

void Player::SetVest(bool up)
{
	m_vest = up;
}

void Player::SetRemoteControl(bool up)
{
	m_remoteControl = up;
}

void Player::Move()
{
	char ch = 0;
	std::cout << "Press Q to quit\n";
	do
	{
		ch = _getch();

		switch (ch)
		{
		case 'W':
		case 'w':
		{
			--m_coordY;
		}
			break;
		case 'A':
		case 'a':
		{
			--m_coordX;
		}
			break;
		case 's':
		case 'S':
		{
			++m_coordY;
		}
			break;
		case 'D':
		case 'd':
		{
			++m_coordX;
		}
			break;

		}

	} while (ch != 'Q' && ch != 'q');
}
