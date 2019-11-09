#pragma once
class Powers
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
	void UpdatePlayerPower(Player player,Power power); //class player don't have implementation

private:
	Power m_power;

};

