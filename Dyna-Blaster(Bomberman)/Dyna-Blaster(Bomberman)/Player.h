#pragma once
#include <cstdint>
#include<string>
#include"Map.h"

using pair = std::pair<uint8_t, uint8_t>;
class Player
{
public:

	Player(uint16_t numberBombs, uint16_t health, uint32_t score, uint16_t speed, uint16_t coordX, uint16_t coordY);
	void SetFire(uint16_t up);
	uint16_t GetFire();
	void SetNoOfBombs(uint16_t up);
	uint16_t GetNoOfBombs();
	uint16_t GetSpeed();
	void SetSpeed(uint16_t up);
	void SetSoftBlockPass(bool up);
	void SetBombPass(bool up);
	void SetHealth(uint16_t up);
	uint16_t GetHealth();
	void SetVest(bool up);
	void SetRemoteControl(bool up);
	void Move();

private:
	uint16_t m_coordX;
	uint16_t m_coordY;
	uint32_t m_score;
	uint16_t m_fire;
	uint16_t m_noOfBombs;
	uint16_t m_speed;
	bool m_softBlockPass=false;
	bool m_bombPass=false;
	uint16_t m_health;
	bool m_vest=false;
	bool m_remoteControl=false;
};

