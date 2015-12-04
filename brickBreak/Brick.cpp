#include "Ball.h"
#include "Brick.h"
#include "BallsHandler.h"


Brick::Brick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris)
{
	dim = dimension;
	pos = position;
	color = coloris;
}


void Brick::draw(sf::RenderWindow& window)
{
	sf::RectangleShape brick(dim);
	brick.setPosition(pos);
	brick.setFillColor(color);
	window.draw(brick);
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

void Brick::onCollision()
{
	if (hits > 0)
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
	}
	
}

float Brick::getTanBrick() const
{
	return dim.y / dim.x;
}

bool Brick::isDestroyed(std::vector<Ball>&, std::vector<Particle>&)
{
	return hits == 0;
}

int Brick::getHits()
{
	return hits;
}