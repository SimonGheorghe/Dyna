#include "GameState.h"

void GameState::InitKeyBinds()
{
	m_keyBinds.emplace("MOVE_LEFT",m_suportedKeys->at("A"));
	m_keyBinds.emplace("MOVE_RIGHT",m_suportedKeys->at("D"));
	m_keyBinds.emplace("MOVE_UP",m_suportedKeys->at("W"));
	m_keyBinds.emplace("MOVE_DOWN",m_suportedKeys->at("S"));
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states)
	:State(window,suportedKeys, states)
{
	this->InitKeyBinds();
}

GameState::~GameState()
{

}



void GameState::UpdateInput(const float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_player.move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_player.move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		endState();
}

void GameState::Update(const float& dt)
{
	this->updateMousePositions();
	this->UpdateInput(dt);
	m_player.Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = m_window;

	m_player.Render(target);
}
