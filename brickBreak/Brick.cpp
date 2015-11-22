#include "Ball.h"
#include "Brick.h"
#include "BallsHandler.h"

//class Brick//
Brick::Brick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris)
{
	dim = dimension;
	pos = position;
	color = coloris;
	destroyed = false;
	tanBrick=dim.y / dim.x;
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

bool Brick::isDestroyed(std::vector<Ball>&)
{
	if (hits <= 0) {
		destroyed = true;
	}
	return destroyed;
}
//end class Brick//


//end class ClassicBrick//




//class BallBrick//


//end class BallBrick//