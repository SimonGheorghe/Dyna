#include <iostream>
#include "Entity.h"

#pragma once
class Powers: public Entity
{
public:
	enum class Type
	{
		FireUp,
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
	
	friend std::ostream& operator<<(std::ostream& out, const Powers& power);

	bool GetPowerStatus() ;
	Type GetPowerType() const;
	void SetPowerStatus(bool value);



private:
	Type m_power;
	bool m_powersIsHidden = 1;

};

