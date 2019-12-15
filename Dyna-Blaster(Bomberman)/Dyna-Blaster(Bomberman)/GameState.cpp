#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	:State(window)
{

}

GameState::~GameState()
{

}

void GameState::endState()
{
	std::cout << "Ending game states!" << std::endl;
}


void GameState::UpdateKeybinds(const float& dt)
{
	this->CheckForQuit();

}

void GameState::Update(const float& dt)
{
	this->UpdateKeybinds(dt);
	this->player.Update(dt);

}

void GameState::Render(sf::RenderTarget* target)
{
	if (target)
	{
	
	}
	else
	this->player.Render(this->window);
}
