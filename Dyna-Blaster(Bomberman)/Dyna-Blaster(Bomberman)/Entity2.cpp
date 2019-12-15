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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->move(dt,-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->move(dt, 0.f, 1.f);
}

void Entity2::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
