#include "MainMenuState.h"
void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
	m_background.setSize(
		sf::Vector2f
		(
			static_cast<float>(m_window->getSize().x),
			static_cast<float>(m_window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/dyna.png"))
	{
		std::cout<< " ERROR::MAIN_MENU_STATE::FALIED_TO_LOAD_BACKGROUND_TEXTURE";
		this->m_background.setFillColor(sf::Color::Black);

	}
	m_background.setTexture(&backgroundTexture);
}

void MainMenuState::initFonts()
{
	/*if (!m_font.loadFromFile("Fonts\Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}*/
}

void MainMenuState::InitKeyBinds()
{
	m_keyBinds.emplace("MOVE_LEFT", this->m_suportedKeys->at("A"));
	m_keyBinds.emplace("MOVE_RIGHT", this->m_suportedKeys->at("D"));
	m_keyBinds.emplace("MOVE_UP", this->m_suportedKeys->at("W"));
	m_keyBinds.emplace("MOVE_DOWN", this->m_suportedKeys->at("S"));
}

void MainMenuState::InitButtons()
{
	m_buttons["GAME_STATE"] = new Button(m_window->getSize().x / 2 - 75, m_window->getSize().y / 2 + 30, 150, 50,
		&m_font, "New Game",
		sf::Color(10, 10, 10, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	m_buttons["BATTLE_STATE"] = new Button(m_window->getSize().x / 2 - 75, m_window->getSize().y / 2 + 81, 150, 50,
		&m_font, "Battle",
		sf::Color(10, 10, 10, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	m_buttons["SETUP_STATE"] = new Button(m_window->getSize().x / 2 - 75, m_window->getSize().y / 2 + 132, 150, 50,
		&m_font, "Setup",
		sf::Color(10, 10, 10, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	m_buttons["PASSWORD_STATE"] = new Button(m_window->getSize().x / 2 - 75, m_window->getSize().y / 2 + 183, 150, 50,
		&m_font, "Password",
		sf::Color(10, 10, 10, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states)
	:State(window, suportedKeys, states)
{
	this->initBackground();
	this->initFonts();
	this->InitKeyBinds();
	this->InitButtons();

	m_background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	m_background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{
	for (auto it = m_buttons.begin(); it != m_buttons.end(); ++it)
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
		m_states->push(new GameState(m_window, m_suportedKeys, m_states));
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
		target = m_window;
	target->draw(m_background);
	RenderButtons(target);

	/*sf::Text mouseText;
	mouseText.setPosition(m_mousePosView.x,m_mousePosView.y);
	mouseText.setFont(m_font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << m_mousePosView.x << " " << m_mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);*/
}

