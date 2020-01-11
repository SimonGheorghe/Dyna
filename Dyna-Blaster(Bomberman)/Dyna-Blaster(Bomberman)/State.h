#pragma once
#include"Player.h"
#include "Button.h"

class State
{
public:
	State(sf::RenderWindow* window, std::map<std::string,int>* suportedKeys, std::stack<State*>* states);
	virtual ~State();

	const bool& GetQuit() const;


	void endState();
	virtual void updateMousePositions();

	virtual void UpdateInput(const float& dt) = 0;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;

protected:
	virtual void InitKeyBinds() = 0;

	std::stack<State*>* m_states;
	sf::RenderWindow* m_window;
	std::map<std::string, int>* m_suportedKeys;
	std::map<std::string, int> m_keyBinds;
	bool m_quit;

	sf::Vector2i m_mousePosScreen;
	sf::Vector2i m_mousePosWindow;
	sf::Vector2f m_mousePosView;

	std::map<std::string, sf::Texture> m_textures;
};

