#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Font* font, sf::String text, unsigned characterSize,
	sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	m_buttonState = BTN_IDLE;
	m_shape.setPosition(sf::Vector2f(x, y));
	m_shape.setSize(sf::Vector2f(width, height));

	m_font = font;
	m_text.setFont(*m_font);
	m_text.setString(text);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(characterSize);
	m_text.setStyle(sf::Text::Bold);
	m_text.setPosition(
		m_shape.getPosition().x + m_shape.getGlobalBounds().width / 2.f - m_text.getGlobalBounds().width / 2.f,
		m_shape.getPosition().y + m_shape.getGlobalBounds().height / 2.f - m_text.getGlobalBounds().height / 2.f
	);

	m_textIdleColor = textIdleColor;
	m_textHoverColor = textHoverColor;
	m_textActiveColor = textActiveColor;

	m_idleColor = idleColor;
	m_hoverColor = hoverColor;
	m_activeColor = activeColor;

	m_shape.setFillColor(m_idleColor);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	if (m_buttonState == BTN_ACTIVE)
		return true;
	return false;
}



void Button::update(const sf::Vector2f mousePos)
{
	/* Update the booleans for hover and pressed */
	// Idle
	m_buttonState = BTN_IDLE;

	// Hover
	if (m_shape.getGlobalBounds().contains(mousePos))
	{
		m_buttonState = BTN_HOVER;
		
		// Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_buttonState = BTN_ACTIVE;
		}
	}

	switch (m_buttonState)
	{
	case BTN_IDLE:
		m_shape.setFillColor(m_idleColor);
		break;
	case BTN_HOVER:
		m_shape.setFillColor(m_hoverColor);
		break;
	case BTN_ACTIVE:
		m_shape.setFillColor(m_activeColor);
		break;
	default:
		m_shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::Render(sf::RenderTarget& target)
{
	target.draw(m_shape);
	target.draw(m_text);
}
