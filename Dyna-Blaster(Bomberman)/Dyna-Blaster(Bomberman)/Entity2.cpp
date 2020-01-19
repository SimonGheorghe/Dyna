#include "Entity2.h"

void Entity2::initVariables()
{
	m_hitboxComponent = NULL;
	m_movementComponent = NULL;
	m_animationComponent = NULL;
}

Entity2::Entity2()
{
	initVariables();
}

Entity2::~Entity2()
{
	delete m_hitboxComponent;
	delete m_movementComponent;
	delete m_animationComponent;
} 

void Entity2::SetTexture(sf::Texture& texture)
{
	m_sprite.setTexture(texture);
}

void Entity2::CreateHitBoxComponent(sf::Sprite& sprite, float offset_x, float offset_y,float width, float height)
{
	m_hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width,height);

	
}

void Entity2::CreateMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	m_movementComponent = new MovementComponent(m_sprite, maxVelocity, acceleration, deceleration);
}

void Entity2::CreateAnimationComponent(sf::Texture& textureSheet)
{
	m_animationComponent = new AnimationComponent(m_sprite, textureSheet);
}

void Entity2::SetPosition(const float x, const float y)
{
	m_sprite.setPosition(x, y);
}

void Entity2::move(const float dir_x, const float dir_y, const float& dt, Map& map)
{
	float coordX, coordY;
	uint16_t x = 0, y = 0;
	sf::Vector2f coords =  m_sprite.getPosition();
	coords.x += 16;
	coords.y += 22;
	std::modf(coords.x, &coordX);
	std::modf(coords.y, &coordY);
	if (int(coordX) % 32 > 16 && (dir_x>0 || dir_y > 0))
		x = 1;
	if (int(coordY) % 32 > 16 && (dir_x > 0 || dir_y > 0))
		y = 1;
	coordX = int(coordX) / 32 + x;
	coordY = int(coordY) / 32 + y;
	if (dir_x > 0)
		coordX += dir_x;
	if (dir_y > 0)
		coordY += dir_y;

	if (m_movementComponent && 
		instanceOf<Block, Entity*>(map[{int(coordX), int(coordY)}]) &&
		(coordX>0 && coordY>0 && coordX<map.GetWidth() && coordY<map.GetLength()) &&
		(instanceOf<Block, Entity*>(map[{int(coordX), int(coordY)}])->GetType()==Block::Type::NoneBlock ||
		!m_hitboxComponent->CheckIntersect(instanceOf<Block, Entity*>(map[{int(coordX), int(coordY)}])->GetGlobalBounds()))
		)
	{
		m_movementComponent->move(dir_x, dir_y, dt);
	}
}

void Entity2::Update(const float& dt)
{

}

void Entity2::Render(sf::RenderTarget& target)
{
	target.draw(m_sprite);
	if (m_hitboxComponent)
	{
		m_hitboxComponent->Render(target);
	}
}
