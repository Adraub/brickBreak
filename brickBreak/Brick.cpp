#include "Brick.h"


Brick::Brick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris)
{
	dim = dimension;
	pos = position;
	color = coloris;
	hits = 1;
	destroyed = false;
	tanBrick=dim.y / dim.x;
}


Brick::~Brick()
{
}

sf::Vector2f Brick::getDim() const
{
	return dim;
}

sf::Vector2f Brick::getPos() const
{
	return pos;
}

sf::Color Brick::getColor() const
{
	return color;
}

int Brick::onCollision()
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

double Brick::getTanBrique() const
{
	return tanBrick;
}

bool Brick::isDestroyed() 
{
	if (hits <= 0) {
		destroyed = true;
	}
	return destroyed;
}