#pragma once
#include"Entity2.h"
class State
{
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& GetQuit() const;
	virtual void CheckForQuit();
	virtual void endState()=0;
	virtual void UpdateKeybinds(const float& dt) = 0;;
	virtual void Update(const float& dt) = 0;
	virtual void Render(sf::RenderTarget* target = nullptr) = 0;

protected:
	bool quit;
	sf::RenderWindow* window;
	std::vector<sf::Texture> m_textures;
};

