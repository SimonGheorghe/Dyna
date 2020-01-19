#pragma once
#include"Entity.h"
#include<iostream>

class Block: public Entity
{
public:
	enum class Type
	{
		NoneBlock,
		HardBlock,
		SoftBlock,
		ExplodedBlock,
		HorizontalFire,
		VerticalFire,
		ExplodedBomb,
		HiddenExit,
		Exit
	};
	
public:
	bool isBlock();
	Block(Type type);
	Type GetType() const;
	Block& operator=(const Block& other);
	Block& operator=(Block&& other);

	friend std::ostream& operator<<(std::ostream& out, const Block& block);

private:
	Type m_type;
};

