#include "GameState.h"

void GameState::InitKeyBinds()
{
	m_keyBinds.emplace("MOVE_LEFT",m_suportedKeys->at("A"));
	m_keyBinds.emplace("MOVE_RIGHT",m_suportedKeys->at("D"));
	m_keyBinds.emplace("MOVE_UP",m_suportedKeys->at("W"));
	m_keyBinds.emplace("MOVE_DOWN",m_suportedKeys->at("S"));
}

void GameState::InitTextures()
{
	if (!m_textures["PLAYER_SHEET"].loadFromFile("./Resources/Images/Sprites/Player/PLAYER_SHEET.png"))
	{
		std::cout << "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}
}

void GameState::InitPlayers()
{
	m_player = new Player(0, 0, m_textures["PLAYER_SHEET"]);
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* suportedKeys, std::stack<State*>* states)
	:State(window,suportedKeys, states)
{
	InitKeyBinds();
	InitTextures();
	InitPlayers();
}

GameState::~GameState()
{
	delete m_player;
}



void GameState::UpdateInput(const float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_player->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_player->move(0.f, 1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		endState();
}

void GameState::Update(const float& dt)
{
	this->updateMousePositions();
	this->UpdateInput(dt);
	m_player->Update(dt);
}

void GameState::Render(sf::RenderTarget* target)
{
	if (!target)
		target = m_window;

	m_player->Render(target);
}
