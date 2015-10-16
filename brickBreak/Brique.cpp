#include "Brique.h"


Brique::Brique(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris)
{
	dim = dimension;
	pos = position;
	color = coloris;
	tanBrick=dim.y / dim.x;
}



sf::Vector2f Brique::getDim()
{
	return dim;
}

sf::Vector2f Brique::getPos()
{
	return pos;
}

sf::Color Brique::getColor()
{
	return color;
}

int Brique::onCollision()
{
	hits++;
	if (color == sf::Color::Yellow)
	{
		color = sf::Color::Blue;
	}
	else
	{
		color = sf::Color::Yellow;
	}
	return 0;
}

double Brique::getTanBrique()
{
	return tanBrick;
}
