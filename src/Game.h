#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// game data
#include "gamedata/StateMachine.h"
#include "gamedata/AssetManager.h"

struct WindowSettings
{
	std::string title;
	unsigned int width, height;
	bool fullscreen;
};

struct GameData
{
	sf::RenderWindow window;
	WindowSettings winConfig;
	StateMachine states;
	AssetManager assets;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
private:
	GameDataRef _data = std::make_shared<GameData>();
	sf::Clock _deltaClock;

	void read_cfg();

public:
	Game();
	~Game();

	void run();

};
