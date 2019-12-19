#include "Entity2.h"

Entity2::Entity2()
{
	m_shape.setSize(sf::Vector2f(50.f, 50.f));
	m_shape.setFillColor(sf::Color::Blue);
	m_movemedSpeed = 100.f;
}

Entity2::~Entity2()
{

}

void Entity2::move(const float& dt,const float dir_x, const float dir_y)
{
	m_shape.move(dir_x * m_movemedSpeed * dt, dir_y * m_movemedSpeed * dt);
}

void Entity2::Update(const float& dt)
{
	
}

void Entity2::Render(sf::RenderTarget* target)
{
	target->draw(m_shape);
}
