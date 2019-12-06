//#include "DynaGame.h"
//#include"../Logging/Logger.h"
//#include<fstream>
////void main()
//{
//	std::ofstream logFile("log.log", std::ios::app);
//	Logger logger(logFile, Logger::Level::Info);
//	logger.Log("Start aplication.", Logger::Level::Info);
//	DynaGame game;
//	game.Run();
//}
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"SFML\Graphics.hpp"
int main()
	{
		sf::RenderWindow window(sf::VideoMode(1800, 1000), "SFML works!");
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			//window.clear();
			window.draw(shape);
			window.display();
		}
	}
