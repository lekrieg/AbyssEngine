#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

class Shape
{
public:
	sf::CircleShape shape;

	Shape() { };
	Shape(sf::CircleShape s) : shape(s) { };
};

#endif // !SHAPE_H