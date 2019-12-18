#pragma once
#include "GameState.h"
#include "Button.h"

class MainMenuState :
	public State
{
private:
	sf::RectangleShape background;
	sf::Font m_font;

	void initFonts();
	void InitKeyBinds();
	 
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys);
	virtual ~MainMenuState();
	void endState();
	//void endStates();
	void UpdateInput(const float& dt);
	void Update(const float& dt);
	void Render(sf::RenderTarget* target = nullptr);
};

