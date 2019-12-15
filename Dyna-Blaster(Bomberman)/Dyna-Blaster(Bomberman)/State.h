#pragma once
#include"Entity2.h"
class State
{
public:

	State(sf::RenderWindow* window, std::map<std::string,int>* suportedKeys);
	virtual ~State();

	const bool& GetQuit() const;
	virtual void CheckForQuit();
	virtual void endState()=0;
	virtual void UpdateInput(const float& dt) = 0;;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;

protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* suportedKeys;
	std::map<std::string, int> keyBinds;
	bool quit;

	virtual void InitKeyBinds() = 0;

	std::vector<sf::Texture> m_textures;
};

