#pragma once
#include <cstdint>
#include<string>
#include "Bomb.h"

using pair = std::pair<uint8_t, uint8_t>;
class Player
{
public:

	Player(uint16_t fire, uint16_t numberBombs, uint16_t health, uint32_t score, uint16_t speed);
	
	uint16_t GetFire() const;
	uint16_t GetNoOfBombs() const;
	uint16_t GetSpeed() const;
	uint16_t GetHealth() const;
	uint16_t GetCoordX() const;
	uint16_t GetCoordY() const;
	uint16_t GetNoOfPlacedBombs() const;

	void SetFire(uint16_t up);
	void SetNoOfBombs(uint16_t up);
	void SetSpeed(uint16_t up);
	void SetSoftBlockPass(bool up);
	void SetBombPass(bool up);
	void SetHealth(uint16_t up);
	void SetVest(bool up);
	void SetRemoteControl(bool up);
	
	void Place(Map& map, uint16_t coordX, uint16_t coordY);
	void Move(Map& map, char ch);
	void PlaceBomb(Map& map, uint16_t coordX, uint16_t coordY);
	void DeleteBomb(int index);

	Bomb* operator[](int index);
	friend std::ostream& operator<<(std::ostream& out, const Player& player);

private:
	uint16_t m_coordX;
	uint16_t m_coordY;
	uint32_t m_score;
	uint16_t m_fire;
	uint16_t m_noOfBombs;
	uint16_t m_speed;
	uint16_t m_health;

	std::vector<Bomb*> m_placedBombs;

	bool m_softBlockPass=false;
	bool m_bombPass=false;
	bool m_vest=false;
	bool m_remoteControl=false;
};

