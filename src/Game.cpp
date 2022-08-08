#include "Game.h"
#include "glm/ext/vector_float2.hpp"
#include "EntityManager.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"

#include <iostream>
#include <fstream>

Game::Game(const std::string& config)
{
	init(config);
}

void Game::init(const std::string& config)
{
	std::ifstream fin(config);

	if(!fin.is_open())
	{
		std::cerr << "Could not open file!\n";
		exit(-1);
	}

	while(fin.good())
	{
		std::string objectType;
		fin >> objectType;
		
		if (objectType.compare("Window") == 0)
		{
			fin >> windowConfig.n >> windowConfig.w >> windowConfig.h;
		}
		else if (objectType.compare("Font") == 0)
		{
			fin >> fontConfig.n >> fontConfig.s >> fontConfig.r >> fontConfig.g >> fontConfig.b;
		}
		else if (objectType.compare("Circle") == 0)
		{
			CircleConfig temp;
			fin >> temp.n >> temp.x >> temp.y >> temp.sx >> temp.sy >> temp.r >> temp.g >> temp.b >> temp.radius >> temp.pc;
			circleConfigs.push_back(temp);
		}
	}

	_running = true;

	if(!_font.loadFromFile(fontConfig.n))
	{
		std::cerr << "Could not load font!\n";
		exit(-1);
	}

	_window.create(sf::VideoMode(windowConfig.w, windowConfig.h), windowConfig.n);
	_window.setFramerateLimit(60);

	objectSpawnerSystem();
}

void Game::run()
{
	// TODO: add pause functionality
	while (_running)
	{
		_entityManager.update();

		
		userInputSystem();
		movementSystem();
		collisionSystem();
		renderSystem();
	}
}

void Game::setPaused(bool paused)
{

}

void Game::movementSystem()
{
	// TODO: implement all entity movements here
	for(auto e : _entityManager.getEntities())
	{
		e->transform->pos = e->transform->pos + e->transform->velocity;
	}
	// TODO: Ver video do javidx sobre sistema de rpg sem engine e livros sobre game programming
	// TODO: implements delta time system and use it with physics

	// sample movement speed update
	/*_player->transform->pos.x += _player->transform->velocity.x;
	_player->transform->pos.y += _player->transform->velocity.y;*/
}

void Game::userInputSystem()
{
	// TODO: handle user input here
	// Usar o sisteminha do outro livro
	sf::Event event;
	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_running = false;
		}

		if (event.type == sf::Event::KeyPressed)
		{
			/* switch (event.key.code)
			{
			case sf::Keyboard::W:
				// Faz algo
				break;
			} */
		}
	}
}

void Game::renderSystem()
{
	_window.clear();
	for (auto e : _entityManager.getEntities())
	{
		e->shape->shape.setPosition(e->transform->pos.x, e->transform->pos.y);
		e->text->text.setPosition(e->transform->pos.x, e->transform->pos.y);

		_window.draw(e->shape->shape);
		_window.draw(e->text->text);
	}
	// set the position of the shape based on the transform->pos
	// set the rotation(mayber) based on the transform->angle
	// _window.draw(entity->Shape->type);
	 _window.display();
}

void Game::collisionSystem()
{
	// TODO: implement all proper collisions
	// use collision radius no shape radius
	for(auto e : _entityManager.getEntities())
	{
		if(e->shape->shape.getPosition().x < 0
		|| e->shape->shape.getPosition().y < 0
		|| e->shape->shape.getPosition().x > windowConfig.w
		|| e->shape->shape.getPosition().y > windowConfig.h)
		{
			// e->transform->velocity = abyss::math::reflection(e->transform->velocity, e->transform->pos.Normalized());
			e->transform->velocity *= -1;
		}
	}
}

void Game::objectSpawnerSystem()
{
	for(auto circle : circleConfigs)
	{
		auto e = _entityManager.addEntity("circle");
		e->shape = std::make_shared<Shape>(sf::CircleShape(circle.radius, circle.pc));
		e->shape->shape.setFillColor(sf::Color(circle.r, circle.g, circle.b));
		// TODO: modificar isso pra uma velocidade X sei la
		e->transform = std::make_shared<Transform>(glm::vec2(circle.x, circle.y), glm::vec2(circle.sx, circle.sy), glm::vec2(0, 0));
		e->text = std::make_shared<Text>(sf::Text(circle.n, _font,  fontConfig.s));
		e->text->text.setFillColor(sf::Color(fontConfig.r, fontConfig.g, fontConfig.b));
	}
}

void Game::spawnObject()
{

}