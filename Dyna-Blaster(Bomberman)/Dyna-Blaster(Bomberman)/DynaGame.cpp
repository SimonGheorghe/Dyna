
#include "DynaGame.h"

void DynaGame::InitVariables()
{
	m_window = NULL;
	m_deltaTime = 0.f;
}

void DynaGame::InitWindow()
{
	m_videoModes = sf::VideoMode::getFullscreenModes();	
	bool fullscreen = false;
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialiasing_level = 0;

	m_windowsSettings.antialiasingLevel = antialiasing_level;
	if(fullscreen)
		m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Dyna Blaster", sf::Style::Fullscreen, m_windowsSettings);
	else
		m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "Dyna Blaster", sf::Style::Titlebar | sf::Style::Close, m_windowsSettings);

	m_window->setFramerateLimit(framerate_limit);
	m_window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void DynaGame::InitKeys()
{
	this->suportedKeys.emplace("ESC", sf::Keyboard::Key::Escape);

	this->suportedKeys.emplace("A", sf::Keyboard::Key::A);
	this->suportedKeys.emplace("D", sf::Keyboard::Key::D);
	this->suportedKeys.emplace("W", sf::Keyboard::Key::W);
	this->suportedKeys.emplace("S", sf::Keyboard::Key::S);

	//std::cout << this->suportedKeys.at("A") << std::endl;
}

void DynaGame::InitStates()
{
	this->states.push(new MainMenuState(this->m_window, &this->suportedKeys, &this->states));

	//this->states.push(new GameState(this->m_window, &this->suportedKeys));
}

DynaGame::DynaGame()
{
	this->InitWindow();
	this->InitKeys();

	this->InitStates();
}

DynaGame::~DynaGame()
{
	delete m_window;
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}

}

void DynaGame::UpdateDt()
{
	m_deltaTime = m_dtClock.restart().asSeconds();
}

void DynaGame::UpdateSFMLEvents()
{
	while (m_window->pollEvent(m_sfEvent))
	{
		if (m_sfEvent.type == sf::Event::Closed)
			m_window->close();
	}
}

void DynaGame::Update()
{
	UpdateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->Update(this->m_deltaTime);
		if (this->states.top()->GetQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->endAplication();
		this->m_window->close();
	}
}

void DynaGame::Render()
{
	m_window->clear();

	if (!this->states.empty())
		this->states.top()->Render();

	m_window->display();
}

void DynaGame::Run()
{
	while (m_window->isOpen())
	{
		UpdateDt();
		Update();
		Render();
	}
}

void DynaGame::endAplication()
{
	std::cout << "Ending APlication";
}