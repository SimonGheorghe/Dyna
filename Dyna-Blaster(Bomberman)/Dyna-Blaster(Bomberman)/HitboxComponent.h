#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class HitboxComponent
{
private:
	sf::Sprite& m_sprite;
	sf::RectangleShape m_hitbox;
	float m_offsetX;
	float m_offsetY;

public:
	HitboxComponent(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);
	virtual~HitboxComponent();

	bool CheckIntersect(const sf::FloatRect& frect);
	void Update();
	void Render(sf::RenderTarget& target);
};