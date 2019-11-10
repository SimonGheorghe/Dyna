#include "Player.h"

Player::Player(uint8_t nrBombs, uint8_t nrLifes, uint32_t score, Speed speed) :
	m_numberBombs(nrBombs), m_numberLifes(nrLifes), m_score(score), m_speed(speed)
{
}

uint8_t Player::GetNumberBombs()
{
	return m_numberBombs;
}

uint8_t Player::GetNumberLifes()
{
	return m_numberLifes;
}

uint32_t Player::GetScore()
{
	return m_score;
}

Player::Speed Player::GetSpeed()
{
	return m_speed;
}

Player::~Player()
{
	delete this;
}
