#include "Entity2.h"

void Entity2::initVariables()
{
	texture = NULL;
	sprite = NULL;
	m_movemedSpeed = 100.f;
}

Entity2::Entity2()
{
	initVariables();

}

Entity2::~Entity2()
{
	delete sprite;
}

void Entity2::createSPrite(sf::Texture* texture)
{
	texture = texture;
	sprite->setTexture(*texture);
}

void Entity2::move(const float& dt,const float dir_x, const float dir_y)
{
	if(sprite)
	 sprite->move(dir_x * m_movemedSpeed * dt, dir_y * m_movemedSpeed * dt);
}

void Entity2::Update(const float& dt)
{
	
}

void Entity2::Render(sf::RenderTarget* target)
{
	if(sprite)
	 target->draw(*sprite);
}
