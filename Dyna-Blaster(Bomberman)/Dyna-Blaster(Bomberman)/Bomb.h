#pragma once
#include <iostream>
#include <cstdint>
#include"Entity.h"


class Bomb: public Entity
{
public:
	bool isBlock();
public:
	//this constructor is for blast, these are for the blast that travels  up down left and right of where it had detonated
	  //these are to be created and destroyed and to kill the player on contact
	Bomb(int, int);
	Bomb();

	~Bomb();

	//getters for returning ticks time and flame size
	uint16_t GetBombTicks() const;
	uint16_t GetFlame() const;

	//sets timer on newbombs
	void SetBombTicks(uint16_t _T);

	//sets flame size on new bombs
	void SetFlame(uint16_t _F);



	//sets the sprites position when it is created
	void SetMonsterPos();

	//Setter and getter for bomb if it has been used
	void SetUsed(bool u);
	bool GetUsed() const;

	//Setter and getter for bomb ignition flag
	void SetIgnite(bool i);
	bool GetIgnite() const;

	//Get if blast or not
	bool GetBlast() const;
	void SetBlast(bool i);

	private:

		//Ticks is the original bombs timer flame is for how many blastlets to create after bomb has detonated
		uint16_t m_bombTicks, m_flame;

		//This is for if the bomb is a bomb or a blast second is if the bombs living time
		//Is over and has to be removed from the array after it has gone off, ignition is the
		//State
		bool IsBlast, IsUsed, Ignition;
};