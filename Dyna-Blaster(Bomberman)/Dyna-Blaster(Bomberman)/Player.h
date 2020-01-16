#pragma once
#include <cstdint>
#include<string>
#include "Powers.h"
#include "Map.h"
#include "Entity2.h"

using pair = std::pair<uint8_t, uint8_t>;

class Player:
	public Entity2
{
public:

	Player(uint16_t fire, uint16_t numberBombs, uint16_t health, uint32_t score, uint16_t speed);
	Player(uint16_t fire, uint16_t numberBombs, uint16_t health, uint32_t score, uint16_t speed, const float x, const float y, sf::Texture& textureSheet);


	void updateAnimation(const float& dt);
	virtual void Update(const float& dt);

	uint16_t GetFire() const;
	uint16_t GetNoOfBombs() const;
	uint16_t GetSpeed() const;
	uint16_t GetHealth() const;
	uint16_t GetCoordX() const;
	uint16_t GetCoordY() const;
	uint16_t GetNoOfPlacedBombs() const;
	uint16_t GetLastX() const;
	uint16_t GetLastY() const ;
	uint16_t GetScore() const ;
	bool GetHasVest() const;
	bool GetHasRemoteControl() const;
	bool GetHasSoftBlockPass() const;
	bool GetHasBombPass() const;

	void SetFire(uint16_t up);
	void SetNoOfBombs(uint16_t up);
	void SetSpeed(uint16_t up);
	void SetHealth(uint16_t up);
	void SetSoftBlockPass(bool up);
	void SetBombPass(bool up);
	void SetVest(bool up);
	void SetRemoteControl(bool up);
	
	void Place(Map& map, uint16_t coordX, uint16_t coordY);
	void Move(Map& map, char ch);
	void PlaceBomb(Map& map);
	void DeleteBomb(int index);
	void UpdatePlayerPower(Powers::Type power);
	bool IsOnBomb();
	void AddScore(uint16_t value);
	void ExplodeBomb(Map& map, uint16_t bomb);


	Bomb* operator[](int index);
	const Bomb* operator[](int index) const;
	friend std::ostream& operator<<(std::ostream& out, const Player& player);

private:
	void playerIsHitt(Map& map, uint16_t index1, uint16_t index2, uint16_t flame, uint16_t op);
	void InitVariables();
	void InitComponents();

private:
	uint16_t m_coordX;
	uint16_t m_coordY;
	uint32_t m_score;
	uint16_t m_fire;
	uint16_t m_noOfBombs;
	uint16_t m_speed;
	uint16_t m_health;
	uint16_t m_lastX;
	uint16_t m_lastY;

	std::vector<Bomb*> m_placedBombs;

	bool m_softBlockPass;
	bool m_bombPass;
	bool m_vest;
	bool m_remoteControl;
};