#pragma once
#include "GameState.h"
#include "EditorState.h"

class MainMenuState :
	public State
{
private:
	sf::Texture backgroundTexture;
	sf::RectangleShape m_background;
	sf::Font m_font;

	std::map<std::string, Button*> m_buttons;

	void initVariables();
	void initBackground();
	void initFonts();
	void InitKeyBinds();
	void InitButtons();
	
public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();
	//void endStates();
	void UpdateInput(const float& dt);
	void UpdateButtons();
	void Update(const float& dt);
	void RenderButtons(sf::RenderTarget& target);
	void Render(sf::RenderTarget* target = nullptr);
};

