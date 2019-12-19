#pragma once

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <sstream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

enum button_states
{
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_ACTIVE
};

class Button
{
private:
	short unsigned m_buttonState;

	sf::RectangleShape m_shape;
	sf::Font* m_font;
	sf::Text m_text;

	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	sf::Color m_activeColor;

protected:

public:
	Button(float x, float y, float width, float height,
		sf::Font font, std::string text,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();

	const bool isPressed() const;

	void update(const sf::Vector2f mousePos);
	void Render(sf::RenderTarget* target);
};

