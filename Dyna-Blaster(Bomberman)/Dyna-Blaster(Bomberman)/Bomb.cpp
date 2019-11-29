#include "Bomb.h"

bool Bomb::isBlock()
{
	return false;
}

Bomb::Bomb(uint16_t coordX, uint16_t coordY, uint16_t id) :
	m_coordX(coordX), m_coordY(coordY), m_id(id)
{
	m_ticks = 8;
}

//destructor is important for destroying old bomb objects after they have detonated!
//Bomb::~Bomb() {
//
//	delete this;
//}

uint16_t Bomb::GetCoordX() const
{
	return m_coordX;
}

uint16_t Bomb::GetCoordY() const
{
	return m_coordY;
}

bool Bomb::GetBlast() const {

	return IsBlast;
}

void Bomb::SetBlast(bool i) {

	IsBlast = i;
}

void playerIsHitt(Map& map, uint16_t index1, uint16_t index2, uint16_t playerCoordX, uint16_t
	playerCoordY, uint16_t flame, bool& playerIsHit,uint16_t op)
{
	while (!dynamic_cast<Powers*>(map[{index1, index2}]) &&
		dynamic_cast<Block*>(map[{index1, index2}])->GetType() == Block::Type::NoneBlock &&
		flame != 0)
{
		switch (op)
		{
		case 0: map.SetBlock(Block::Type::VerticalFire, index1--, index2);
			break;
		case 1: map.SetBlock(Block::Type::VerticalFire, index1++, index2);
			break;
		case 2: map.SetBlock(Block::Type::HorizontalFire, index1, index2--);
			break;
		case 3: map.SetBlock(Block::Type::HorizontalFire, index1, index2++);
			break;
		default:
			break;
		}
		flame--;
		if (playerCoordX == index1 && playerCoordY == index2)
			playerIsHit = 1;
	}
	if (dynamic_cast<Powers*>(map[{index1, index2}]))
	{
		if (flame != 0)
			if (dynamic_cast<Powers*>(map[{index1, index2}])->GetPowerStatus() == 1)
				dynamic_cast<Powers*>(map[{index1, index2}])->SetPowerStatus(0);
			else
			{
				switch (op)
				{
				case 0: map.SetBlock(Block::Type::NoneBlock, index1--, index2);
					break;
				case 1: map.SetBlock(Block::Type::NoneBlock, index1++, index2);
					break;
				case 2: map.SetBlock(Block::Type::NoneBlock, index1, index2--);
					break;
				case 3: map.SetBlock(Block::Type::NoneBlock, index1, index2++);
					break;
				default:
					break;
				}
			}

	}
	else
		if (dynamic_cast<Block*>(map[{index1, index2}])->GetType() == Block::Type::SoftBlock && flame != 0)
		{
			switch (op)
			{
			case 0: map.SetBlock(Block::Type::ExplodedBlock, index1--, index2);
				break;
			case 1: map.SetBlock(Block::Type::ExplodedBlock,index1++, index2);
				break;
			case 2: map.SetBlock(Block::Type::ExplodedBlock, index1, index2--);
				break;
			case 3: map.SetBlock(Block::Type::ExplodedBlock, index1,index2++);
				break;
			default:
				break;
			}
		}

		else
			if (dynamic_cast<Block*>(map[{index1, index2}])->GetType() == Block::Type::Exit && flame != 0)
				dynamic_cast<Block*>(map[{index1, index2}])->SetExitStatus(false);

}
bool Bomb::Explode(Map& map, uint16_t fire, uint16_t playerCoordX, uint16_t playerCoordY)
{
	map.SetBlock(Block::Type::ExplodedBomb, m_coordX, m_coordY);
	uint16_t index1 = m_coordX;
	uint16_t index2 = m_coordY;
	uint16_t flame = fire;
	bool playerIsHit = 0;

	if (playerCoordX == index1 && playerCoordY == index2)
		playerIsHit = 1;
	playerIsHitt(map, index1 - 1, index2, playerCoordX, playerCoordY, flame, playerIsHit,0);
	playerIsHitt(map, index1 + 1, index2, playerCoordX, playerCoordY, flame, playerIsHit, 1);
	playerIsHitt(map, index1, index2 - 1, playerCoordX, playerCoordY, flame, playerIsHit, 2);
	playerIsHitt(map, index1, index2 + 1, playerCoordX, playerCoordY, flame, playerIsHit, 3);

	/*while (!dynamic_cast<Powers*>(map[{index1 + 1, index2}]) && dynamic_cast<Block*>(map[{index1 + 1, index2}])->GetType() == Block::Type::NoneBlock && flame != 0)
	{
		map.SetBlock(Block::Type::VerticalFire, ++index1, index2);
		flame--;
		if (playerCoordX == index1 && playerCoordY == index2)
			playerIsHit = 1;
	}
	if (dynamic_cast<Powers*>(map[{index1 + 1, index2}]))
	{
		if (flame != 0)
			if (dynamic_cast<Powers*>(map[{index1 + 1, index2}])->GetPowerStatus() == 1)
				dynamic_cast<Powers*>(map[{index1 + 1, index2}])->SetPowerStatus(0);
			else
				map.SetBlock(Block::Type::NoneBlock, ++index1, index2);
	}
	else
		if (dynamic_cast<Block*>(map[{index1 + 1, index2}])->GetType() == Block::Type::SoftBlock && flame != 0)
			map.SetBlock(Block::Type::ExplodedBlock, ++index1, index2);
		else
			if (dynamic_cast<Block*>(map[{index1 + 1, index2}])->GetType() == Block::Type::Exit && flame != 0)
				dynamic_cast<Block*>(map[{index1 + 1, index2}])->SetExitStatus(false);

	while (!dynamic_cast<Powers*>(map[{index1, index2 - 1}]) && dynamic_cast<Block*>(map[{index1, index2 - 1}])->GetType() == Block::Type::NoneBlock && flame != 0)
	{
		map.SetBlock(Block::Type::HorizontalFire, index1, --index2);
		flame--;
		if (playerCoordX == index1 && playerCoordY == index2)
			playerIsHit = 1;
	}
	if (dynamic_cast<Powers*>(map[{index1, index2 - 1}]))
	{
		if (flame != 0)
			if (dynamic_cast<Powers*>(map[{index1, index2 - 1}])->GetPowerStatus() == 1)
				dynamic_cast<Powers*>(map[{index1, index2 - 1}])->SetPowerStatus(0);
			else
				map.SetBlock(Block::Type::NoneBlock, index1, --index2);
	}
	else
		if (dynamic_cast<Block*>(map[{index1, index2 - 1}])->GetType() == Block::Type::SoftBlock && flame != 0)
			map.SetBlock(Block::Type::ExplodedBlock, index1, --index2);
		else
			if (dynamic_cast<Block*>(map[{index1, index2 - 1}])->GetType() == Block::Type::Exit && flame != 0)
				dynamic_cast<Block*>(map[{index1, index2 - 1}])->SetExitStatus(false);

	while (!dynamic_cast<Powers*>(map[{index1, index2 + 1}]) && dynamic_cast<Block*>(map[{index1, index2 + 1}])->GetType() == Block::Type::NoneBlock && flame != 0)
	{
		map.SetBlock(Block::Type::HorizontalFire, index1, ++index2);
		flame--;
		if (playerCoordX == index1 && playerCoordY == index2)
			playerIsHit = 1;
	}
	if (dynamic_cast<Powers*>(map[{index1, index2 + 1}]))
	{
		if (flame != 0)
			if (dynamic_cast<Powers*>(map[{index1, index2 + 1}])->GetPowerStatus() == 1)
				dynamic_cast<Powers*>(map[{index1, index2 + 1}])->SetPowerStatus(0);
			else
				map.SetBlock(Block::Type::NoneBlock, index1, ++index2);
	}
	else
		if (dynamic_cast<Block*>(map[{index1, index2 + 1}])->GetType() == Block::Type::SoftBlock && flame != 0)
			map.SetBlock(Block::Type::ExplodedBlock, index1, ++index2);
		else
			if (dynamic_cast<Block*>(map[{index1, index2 + 1}])->GetType() == Block::Type::Exit && flame != 0)
				dynamic_cast<Block*>(map[{index1, index2 + 1}])->SetExitStatus(false);*/
	return playerIsHit;
}

bool Bomb::GetIgnite() const {

	return Ignition;
}

void Bomb::SetIgnite(bool i) {

	Ignition = i;
}

uint16_t Bomb::GetTicks() const
{

	return m_ticks;
}

void Bomb::SetTicks(uint16_t ticks)
{
	m_ticks = ticks;
}

//returns length of blast
uint16_t Bomb::GetFlame() const
{

	return m_flame;
}


//sets flame size on new bombs
void Bomb::SetFlame(uint16_t F) 
{

	m_flame = F;
}

std::ostream& operator<<(std::ostream& out, const Bomb& bomb)
{
	return out << "* ";
}
