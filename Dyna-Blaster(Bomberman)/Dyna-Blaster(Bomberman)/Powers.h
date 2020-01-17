#include <iostream>
#include "Entity.h"

#pragma once
class Powers: public Entity
{
public:
	enum class Type
	{
		FireUp=0,
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
	Powers(Type power, const float x, const float y, std::vector<sf::Texture>& textureSheet);
	
	friend std::ostream& operator<<(std::ostream& out, const Powers& power);

	virtual void Render(sf::RenderTarget& target);

	bool GetPowerStatus() ;
	Type GetPowerType() const;
	void SetPowerStatus(bool value);



private:
	Type m_power;
	bool m_powersIsHidden = 1;

};

