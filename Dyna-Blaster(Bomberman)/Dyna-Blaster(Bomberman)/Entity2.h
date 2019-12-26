#pragma once

#include "MovementComponent.h"

class Entity2
{
private:
	void initVariables();

protected:
	sf::Sprite m_sprite;
	
	MovementComponent* m_movementComponent;

public : 
	Entity2();
	virtual ~Entity2();

	void SetTexture(sf::Texture& texture);
	void CreateMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);

	virtual void SetPosition(const float x, const float y);
	virtual void move(const float dir_x, const float dir_y, const float& dt);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
};