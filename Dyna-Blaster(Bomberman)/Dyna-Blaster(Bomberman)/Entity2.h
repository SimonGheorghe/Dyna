#pragma once

#include "MovementComponent.h"

class Entity2
{
private:
	void initVariables();

protected:
	sf::Texture* texture;
	sf::Sprite* sprite;
	
	MovementComponent* m_movementComponent;

public : 
	Entity2();
	virtual ~Entity2();

	void createSprite(sf::Texture* texture);
	void CreateMovementComponent(const float maxVelocity);

	virtual void SetPosition(const float x, const float y);
	virtual void move(const float& dt,const float dir_x, const float dir_y);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
};


