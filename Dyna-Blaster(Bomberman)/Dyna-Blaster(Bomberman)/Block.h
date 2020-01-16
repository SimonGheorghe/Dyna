#pragma once
#include"Entity.h"
#include<iostream>

class Block: public Entity
{
public:
	enum class Type
	{
		HardBlock,
		SoftBlock,
		NoneBlock,
		ExplodedBlock,
		HorizontalFire,
		VerticalFire,
		ExplodedBomb,
		HiddenExit,
		Exit
	};
	
public:
	Block(Type type);
	Type GetType() const;

	friend std::ostream& operator<<(std::ostream& out, const Block& block);

private:
	Type m_type;
};

