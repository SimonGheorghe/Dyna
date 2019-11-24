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