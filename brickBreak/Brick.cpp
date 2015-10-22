#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Brick.h"
#include "Ball.h"

//class Brick//
Brick::Brick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris)
{
	dim = dimension;
	pos = position;
	color = coloris;
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
//end class Brick//


//class ClassicBrick//
ClassicBrick::ClassicBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris) : Brick(position, dimension, coloris)
{
	hits = 1;
}

ClassicBrick::~ClassicBrick()
{

}
//end class ClassicBrick//


//class StrongBrick//
StrongBrick::StrongBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris, int nb_hits) : Brick(position, dimension, coloris)
{
	hits = nb_hits;
}

StrongBrick::~StrongBrick()
{

}
//end class StrongBrick//


//class BallBrick//

BallBrick::BallBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris, std::vector<Ball>& myBalls) : Brick(position, dimension, coloris)
{	
	myBall = &myBalls;
	hits = 2;
}

BallBrick::~BallBrick()
{
	
}

bool BallBrick::isDestroyed()
{
	Brick::isDestroyed();
	if (destroyed) {
		myBall->push_back(Ball(pos, 10, sf::Vector2f(-1, 1)));
	}
	return destroyed;
}
//end class BallBrick//