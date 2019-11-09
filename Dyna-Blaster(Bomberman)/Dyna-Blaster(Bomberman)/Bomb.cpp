#include "Bomb.h"

Bomb::Bomb(int X, int Y)
{
	//this is a blastlet
	SetBlast(true);

}

//destructor is important for destroying old bomb objects after they have detonated!
Bomb::~Bomb() {

	delete this;
}

void Bomb::SetUsed(bool u) {

	IsUsed = u;
}

bool Bomb::GetBlast() {

	return IsBlast;
}

void Bomb::SetBlast(bool i) {

	IsBlast = i;
}

bool Bomb::GetIgnite() {

	return Ignition;
}

void Bomb::SetIgnite(bool i) {

	Ignition = i;
}

bool Bomb::GetUsed() {

	return IsUsed;
}


uint16_t Bomb::GetBombTicks() {

	return m_bombTicks;
}

//returns length of blast
uint16_t Bomb::GetFlame() {

	return m_flame;
}

//sets timer on newbombs
void Bomb::SetBombTicks(uint16_t T)
{

	m_bombTicks = T;
}

//sets flame size on new bombs
void Bomb::SetFlame(uint16_t F) 
{

	m_flame = F;
}
