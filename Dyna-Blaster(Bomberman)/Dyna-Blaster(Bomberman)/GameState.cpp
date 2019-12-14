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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A" << "\n";


}

void GameState::Render(sf::RenderTarget* target)
{

}
