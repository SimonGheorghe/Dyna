#include"Player.h"
#pragma once
class Powers: public Entity
{
public:
	enum class Power
	{
		FireUp,
		FireDown,
		BombUp,
		BombDown,
		SkateUp,
		SkateDown,
		SoftBlockPass,
		BombPass,
		Heart,
		Vest,
		RemoteControl
	};

public:
	Powers(Power power);
	void UpdatePlayerPower(Player player,Power power);
	bool isBlock();

private:
	Power m_power;

};

