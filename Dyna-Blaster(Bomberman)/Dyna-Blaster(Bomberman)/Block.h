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
		NoneBlock
	};
public:
	Block(Type type);
	bool isBlock();
	Type GetType();



private:
	Type m_type;
};

