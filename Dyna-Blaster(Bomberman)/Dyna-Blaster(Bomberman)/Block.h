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
		Exit
	};
	
public:
	Block(Type type);
	bool isBlock();
	Type GetType() const;
	uint16_t GetExitX() const;
	uint16_t GetExitY() const;

	void SetExitX(uint16_t coordX);
	void SetExitY(uint16_t coordY);
	void SetExitStatus(bool value);

	friend std::ostream& operator<<(std::ostream& out, const Block& block);

private:
	Type m_type;
	uint16_t m_exitX;
	uint16_t m_exitY;
	bool m_exitIsHidden = 1;
};

