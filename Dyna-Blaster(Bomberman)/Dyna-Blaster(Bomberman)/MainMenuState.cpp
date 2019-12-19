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

void MainMenuState::InitButtons()
{
	m_buttons["GAME_STATE"]= new Button(window->getSize().x / 2 - 75, window->getSize().y / 2, 150, 50,
		m_font, "New Game",
		sf::Color(10, 10, 10, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));


	m_buttons["EXIT_STATE"] = new Button(window->getSize().x / 2 - 75, window->getSize().y / 2+60, 150, 50,
		m_font, "Quit",
		sf::Color(10, 10, 10, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states)
	:State(window, suportedKeys, states)
{
	this->initFonts();
	this->InitKeyBinds();
	this->InitButtons();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	auto it = m_buttons.begin();
	for (it = m_buttons.begin(); it != m_buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::endState()
{
	std::cout << "Ending MainMenuStates!" << std::endl;
}

void MainMenuState::UpdateInput(const float& dt)
{
	this->CheckForQuit();
}

void MainMenuState::UpdateButtons()
{
	for (auto& it : m_buttons)
	{
		it.second->update(m_mousePosView);
	}

	if (m_buttons["GAME_STATE"]->isPressed())
	{
		this->m_states->push(new GameState(this->window, this->suportedKeys, m_states));
	}

	if (m_buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}
}

void MainMenuState::Update(const float& dt)
{
	this->updateMousePositions();
	this->UpdateInput(dt);
	this->UpdateButtons();
}

void MainMenuState::RenderButtons(sf::RenderTarget* target)
{
	for (auto& it : m_buttons)
	{
		it.second->Render(target);
	}
}

void MainMenuState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	RenderButtons(target);
}