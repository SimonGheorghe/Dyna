#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states)
{
	m_window = window;
	m_suportedKeys = suportedKeys;
	m_states = states;
	m_quit = false;
}

State::~State()
{

}

const bool& State::GetQuit() const
{
	return m_quit;
}
void State::endState()
{
	m_quit = true;
}
void State::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition();
	m_mousePosWindow = sf::Mouse::getPosition(*m_window);
	m_mousePosView = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));
}