#ifndef GAME_H
#define GAME_H

#include "EntityManager.h"

#include <SFML/Graphics.hpp>

struct WindowConfig{ std::string n; int w; int h; };
struct FontConfig{ std::string n; int s, r, g, b; };
struct CircleConfig{ std::string n; int x, y, sx, sy, r, g, b; float radius; int pc; };

class Game
{
private:
	WindowConfig windowConfig;
	FontConfig fontConfig;
	std::vector<CircleConfig> circleConfigs;

	sf::RenderWindow _window;
	sf::Font _font;
	EntityManager _entityManager;
	// variavel do tipo struct com as configs
	bool _paused;
	bool _running;

	void init(const std::string& config);
	void setPaused(bool paused);

	void movementSystem();
	void userInputSystem();
	void renderSystem();
	void collisionSystem();
	void objectSpawnerSystem();

	void spawnObject();

public:
	Game(const std::string& config);

	void run();
};

#endif // !GAME_H
