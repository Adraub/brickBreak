#include "Brick.h"

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

//end class ClassicBrick//


//class StrongBrick//
StrongBrick::StrongBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris, int nb_hits) : Brick(position, dimension, coloris)
{
	hits = nb_hits;
}


void StrongBrick::draw(sf::RenderWindow& window)
{
	sf::RectangleShape brick1(dim);
	brick1.setPosition(pos);
	brick1.setFillColor(sf::Color::White);
	window.draw(brick1);
	sf::RectangleShape brick2(sf::Vector2f(dim.x-6,dim.y-6));
	brick2.setPosition(sf::Vector2f(pos.x + 3, pos.y + 3));
	brick2.setFillColor(color);
	window.draw(brick2);
}
//end class StrongBrick//


//class BallBrick//

//BallBrick::BallBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris, std::vector<Ball>& myBalls) : Brick(position, dimension, coloris)
//{	
//	myBall = &myBalls;
//	hits = 1;
//}


//void BallBrick::draw(sf::RenderWindow& window)
//{
//	Brick::draw(window);
//	sf::CircleShape trappedBall(10);
//	trappedBall.setPosition(sf::Vector2f((pos.x+dim.x/2)-10, (pos.y+dim.y/2)-10));
//	trappedBall.setFillColor(sf::Color::Red);
//	window.draw(trappedBall);
//}

//bool BallBrick::isDestroyed()
//{
//	Brick::isDestroyed();
//	if (destroyed) {
//		myBall->push_back(Ball(sf::Vector2f((pos.x + dim.x / 2) - 10, (pos.y + dim.y / 2) - 10), 10, sf::Vector2f(-1, 1),sf::Color::Red));
//	}
//	return destroyed;
//}
//end class BallBrick//