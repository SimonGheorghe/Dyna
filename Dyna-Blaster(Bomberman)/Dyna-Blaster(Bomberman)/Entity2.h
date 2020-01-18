#pragma once

#include "HitboxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"
#include "Map.h"
#include <math.h>

class Entity2
{
private:
	void initVariables();

protected:
	sf::Sprite m_sprite;
	
	HitboxComponent* m_hitboxComponent;
	MovementComponent* m_movementComponent;
	AnimationComponent* m_animationComponent;

public : 
	Entity2();
	virtual ~Entity2();

	void SetTexture(sf::Texture& texture);
	void CreateHitBoxComponent(sf::Sprite& sprite, float offset_x, float offset_y,float width, float height);

	void CreateMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void CreateAnimationComponent(sf::Texture& textureSheet);

	virtual void SetPosition(const float x, const float y);
	virtual void move(const float dir_x, const float dir_y, const float& dt, Map& map);
	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget& target);
};