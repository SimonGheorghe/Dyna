#include <iostream>
#include "Entity.h"

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
	
	bool isBlock();
	friend std::ostream& operator<<(std::ostream& out, const Powers& power);

	bool GetPowerStatus() ;
	Power GetPowerType() const;
	void SetPowerStatus(bool value);



private:
	Power m_power;
	bool m_powersIsHidden = 1;

};

