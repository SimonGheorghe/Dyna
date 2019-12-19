#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState :
	public State
{
private:
	sf::RectangleShape m_background;
	sf::Font m_font;

	std::map<std::string, Button*> m_buttons;

	void initFonts();
	void InitKeyBinds();
	void InitButtons();
	 
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();
	void endState();
	//void endStates();
	void UpdateInput(const float& dt);
	void UpdateButtons();
	void Update(const float& dt);
	void RenderButtons(sf::RenderTarget* target = nullptr);
	void Render(sf::RenderTarget* target = nullptr);
};

