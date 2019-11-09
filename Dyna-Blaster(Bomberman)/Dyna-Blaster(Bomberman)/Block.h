#pragma once
class Block
{
public:
	enum class Type
	{
		HardBlock,
		SoftBlock,
	};
public:
	Block(Type type);

private:
	Type m_type;
};

