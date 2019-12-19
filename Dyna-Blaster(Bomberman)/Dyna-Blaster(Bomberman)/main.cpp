#include "DynaGame.h"
#include"../Logging/Logger.h"
#include<fstream>
void main()
{
	std::ofstream logFile("log.log", std::ios::app);
	Logger logger(logFile, Logger::Level::Info);
	logger.Log("Start aplication.", Logger::Level::Info);
	DynaGame game;
	game.Run();
}
//#include<iostream>
//#include<ctime>
//#include<cstdlib>
//#include"SFML\Graphics.hpp"
//int main()
//	{
//		sf::RenderWindow m_window(sf::VideoMode(1800, 1000), "SFML works!");
//		sf::CircleShape shape(100.f);
//		shape.setFillColor(sf::Color::Green);
//
//		while (m_window.isOpen())
//		{
//			sf::Event event;
//			while (m_window.pollEvent(event))
//			{
//				if (event.type == sf::Event::Closed)
//					m_window.close();
//			}
//
//			//m_window.clear();
//			m_window.draw(shape);
//			m_window.display();
//		}
//	}
