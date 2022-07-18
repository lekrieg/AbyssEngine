#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>

class Text
{
public:
	sf::Text text;

	Text(sf::Text t) : text(t) { };
};

#endif // !TEXT_H