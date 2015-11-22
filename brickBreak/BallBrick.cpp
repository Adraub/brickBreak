#include "BallBrick.h"

BallBrick::BallBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris) : Brick(position, dimension, coloris)
{
	hits = 1;
}


void BallBrick::draw(sf::RenderWindow& window)
{
	Brick::draw(window);
	sf::CircleShape trappedBall(10);
	trappedBall.setPosition(sf::Vector2f((pos.x + dim.x / 2) - 10, (pos.y + dim.y / 2) - 10));
	trappedBall.setFillColor(sf::Color::Red);
	window.draw(trappedBall);
}

bool BallBrick::isDestroyed(std::vector<Ball>& ref)
{
	Brick::isDestroyed(ref);
	if (destroyed) {
		/*Send the ball created in a random direction*/
		float angle=(rand()%360)*3.14/360.0f;
		sf::Vector2f speedDir(15 * cos(angle), 15 * sin(angle));
		ref.push_back(Ball(sf::Vector2f((pos.x + dim.x / 2) - 10, (pos.y + dim.y / 2) - 10), 10, speedDir, sf::Color::Red));
		return 1;
	}
	return destroyed;
}