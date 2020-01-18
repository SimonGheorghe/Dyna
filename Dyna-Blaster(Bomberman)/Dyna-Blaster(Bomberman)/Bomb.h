#pragma once
#include <iostream>
#include <cstdint>
#include "Entity.h"

class Bomb: public Entity
{
public:
	//this constructor is for blast, these are for the blast that travels  up down left and right of where it had detonated
	  //these are to be created and destroyed and to kill the player on contact
	Bomb(uint16_t coordX, uint16_t coordY, uint16_t id);

	//~Bomb();

	uint16_t GetCoordX() const;
	uint16_t GetCoordY() const;
	uint16_t GetID() const;

	//getters for returning ticks time and flame size
	uint16_t GetFlame() const;

	//sets m_timer on newbombs
	uint16_t GetTicks() const;
	void SetTicks(uint16_t ticks);

	//sets flame size on new bombs
	void SetFlame(uint16_t _F);

	//Setter and getter for bomb ignition flag
	void SetIgnite(bool i);
	bool GetIgnite() const;

	//Get if blast or not
	bool GetBlast() const;
	void SetBlast(bool i);

	void render(sf::RenderTarget& target);
		
	friend std::ostream& operator<<(std::ostream& out, const Bomb& bomb);

private:

	//Ticks is the original bombs m_timer flame is for how many blastlets to create after bomb has detonated
	uint16_t m_coordX;
	uint16_t m_coordY;
	uint16_t m_ticks;
	uint16_t m_flame;
	uint16_t m_id;

	//This is for if the bomb is a bomb or a blast second is if the bombs living time
	//Is over and has to be removed from the array after it has gone off, ignition is the
	//State
	bool IsBlast, Ignition;
};