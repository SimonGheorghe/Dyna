#include <iostream>
#include "Entity.h"

#pragma once
class Powers: public Entity
{
public:
	enum class Type
	{
		FireUp = 0,
		BombUp,
		SkateUp,
		SoftBlockPass,
		BombPass,
		Heart,
		Vest,
		RemoteControl,
		FireDown,
		BombDown,
		SkateDown,
		Skull
	};

public:
	Powers(Type power);
	
	bool isBlock();
	friend std::ostream& operator<<(std::ostream& out, const Powers& power);

	bool GetPowerStatus() ;
	Type GetPowerType() const;
	void SetPowerStatus(bool value);

	Powers& operator=(const Powers& other);
	Powers& operator=(Powers&& other);

private:
	Type m_power;
	bool m_powersIsHidden = 1;

};

