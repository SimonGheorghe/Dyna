#pragma once
#include "State.h"

class EditorState :
	public State
{
private:
	sf::Font m_font;

	std::map<std::string, Button*> m_buttons;

	void initVariables();
	void initBackground();
	void initFonts();
	void InitKeyBinds();
	void InitButtons();

public:
	EditorState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states);
	virtual ~EditorState();
	//void endStates();
	void UpdateInput(const float& dt);
	void UpdateButtons();
	void Update(const float& dt);
	void RenderButtons(sf::RenderTarget* target = nullptr);
	void Render(sf::RenderTarget* target = nullptr);
};

