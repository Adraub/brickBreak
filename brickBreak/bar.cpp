#include "bar.h"

Bar::Bar(sf::Vector2f position, sf::Vector2f dimension, sf::Color colori)
{
	dim = dimension;
	pos = position;
	color = colori;
}


Bar::~Bar()
{
}

sf::Vector2f Bar::getDim()
{
	return dim;
}

sf::Vector2f Bar::getPos()
{
	return pos;
}