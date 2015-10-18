#include "Brique.h"


Brique::Brique(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris)
{
	dim = dimension;
	pos = position;
	color = coloris;
	hits = 1;
	destroyed = false;
	tanBrick=dim.y / dim.x;
}


Brique::~Brique()
{
}

sf::Vector2f Brique::getDim() const
{
	return dim;
}

sf::Vector2f Brique::getPos() const
{
	return pos;
}

sf::Color Brique::getColor() const
{
	return color;
}

int Brique::onCollision()
{
	hits--;
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

double Brique::getTanBrique() const
{
	return tanBrick;
}

bool Brique::isDestroyed() 
{
	if (hits <= 0) {
		destroyed = true;
	}
	return destroyed;
}