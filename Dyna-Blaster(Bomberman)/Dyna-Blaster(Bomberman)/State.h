#pragma once

#include <ctime>
#include <stdlib.h>
#include<stack>
#include<map>
#include<iostream>


#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

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

private:
	bool quit;
	sf::RenderWindow* window;
	std::vector<sf::Texture> m_textures;
};

