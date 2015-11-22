#include "ClassicBrick.h"

//class ClassicBrick//
ClassicBrick::ClassicBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris) : Brick(position, dimension, coloris)
{
	hits = 1;
}
