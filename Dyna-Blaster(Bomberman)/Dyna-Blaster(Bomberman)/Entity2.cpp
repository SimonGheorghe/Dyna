#include "Entity2.h"

Entity2::Entity2()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Blue);
	this->movemedSpeed = 100.f;
}

Entity2::~Entity2()
{

}

void Entity2::move(const float& dt,const float dir_x, const float dir_y)
{
	this->shape.move(dir_x *this->movemedSpeed*dt, dir_y*this->movemedSpeed * dt);

}

void Entity2::Update(const float& dt)
{
	
}

void Entity2::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
