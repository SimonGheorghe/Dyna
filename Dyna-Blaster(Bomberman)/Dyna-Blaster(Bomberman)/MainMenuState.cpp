#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	if (m_font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FOONT");
	}
}

void MainMenuState::InitKeyBinds()
{
	/*this->keyBinds.emplace("MOVE_LEFT", this->suportedKeys->at("A"));
	this->keyBinds.emplace("MOVE_RIGHT", this->suportedKeys->at("D"));
	this->keyBinds.emplace("MOVE_UP", this->suportedKeys->at("W"));
	this->keyBinds.emplace("MOVE_DOWN", this->suportedKeys->at("S"));*/
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys)
	:State(window, suportedKeys)
{
	this->initFonts();
	this->InitKeyBinds();
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Cyan);
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::endState()
{
	std::cout << "Ending game states!" << std::endl;
}

void MainMenuState::UpdateInput(const float& dt)
{
	this->CheckForQuit();
}

void MainMenuState::Update(const float& dt)
{
	this->updateMousePositions();
	this->UpdateInput(dt);

	system("cls");
	std::cout << m_mousePosView.x << " " << m_mousePosView.y << "\n";
}

void MainMenuState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
}