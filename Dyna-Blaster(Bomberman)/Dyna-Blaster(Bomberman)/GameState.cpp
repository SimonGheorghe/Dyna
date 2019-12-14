#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	:State(window)
{

}

GameState::~GameState()
{

}

void GameState::endStates()
{
}

void GameState::Update(const float& dt)
{
	std::cout << "Hello from GameStates! " << std::endl;
}

void GameState::Render(sf::RenderTarget* target)
{

}
