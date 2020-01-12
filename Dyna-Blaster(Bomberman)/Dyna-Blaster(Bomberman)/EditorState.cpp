#include "EditorState.h"

void EditorState::initVariables()
{

}

void EditorState::initBackground()
{

}

void EditorState::initFonts()
{
	/*if (!m_font.loadFromFile("Fonts\Dosis-Light.ttf"))
	{
		throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT");
	}*/
}

void EditorState::InitKeyBinds()
{

}

void EditorState::InitButtons()
{

}

EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states)
	:State(window, suportedKeys, states)
{
	this->initBackground();
	this->initFonts();
	this->InitKeyBinds();
	this->InitButtons();

	/*m_background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	m_background.setFillColor(sf::Color::Blue);*/
}

EditorState::~EditorState()
{
	for (auto it = m_buttons.begin(); it != m_buttons.end(); ++it)
	{
		delete it->second;
	}
}



void EditorState::UpdateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		endState();
}

void EditorState::UpdateButtons()
{
	for (auto& it : m_buttons)
	{
		it.second->update(m_mousePosView);
	}
}

void EditorState::Update(const float& dt)
{
	this->updateMousePositions();
	this->UpdateInput(dt);
	this->UpdateButtons();
}

void EditorState::RenderButtons(sf::RenderTarget& target)
{
	for (auto& it : m_buttons)
	{
		it.second->Render(target);
	}
}

void EditorState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = m_window;
	RenderButtons(*target);
}

