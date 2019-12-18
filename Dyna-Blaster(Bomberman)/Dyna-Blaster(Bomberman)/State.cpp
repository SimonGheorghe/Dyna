#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys)
{
	this->window = window;
	this->suportedKeys = suportedKeys;
	this->quit = false;

}

State::~State()
{

}

const bool& State::GetQuit() const
{
	return this->quit;
}

void State::CheckForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

void State::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition();
	m_mousePosWindow = sf::Mouse::getPosition(*this->window);
	m_mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
