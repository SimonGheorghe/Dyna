#include "GameState.h"

void GameState::InitKeyBinds()
{
	this->keyBinds.emplace("MOVE_LEFT",this->suportedKeys->at("A"));
	this->keyBinds.emplace("MOVE_RIGHT",this->suportedKeys->at("D"));
	this->keyBinds.emplace("MOVE_UP",this->suportedKeys->at("W"));
	this->keyBinds.emplace("MOVE_DOWN",this->suportedKeys->at("S"));
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys)
	:State(window,suportedKeys)
{
	this->InitKeyBinds();
}

GameState::~GameState()
{

}

void GameState::endState()
{
	std::cout << "Ending game states!" << std::endl;
}


void GameState::UpdateInput(const float& dt)
{
	this->CheckForQuit();


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player.move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player.move(dt, 0.f, 1.f);

}

void GameState::Update(const float& dt)
{
	this->updateMousePositions();
	this->UpdateInput(dt);
	this->player.Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player.Render(target);
	
}
