#include "BallBrick.h"

BallBrick::BallBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Texture*& texture) : Brick(position, dimension, texture)
{
	hits = 1;
}

bool BallBrick::isDestroyed(std::vector<Ball>& ref, std::vector<Particle>& ParticleVector)
{
	Brick::isDestroyed(ref, ParticleVector);
	if (hits==0) {
		/*Send the ball created in a random direction*/
		float angle=(rand()%360)*3.14/360.0f;
		sf::Vector2f speedDir(15 * cos(angle), 15 * sin(angle));
		ref.push_back(Ball(sf::Vector2f((pos.x + dim.x / 2) - 10, (pos.y + dim.y / 2) - 10), 10, speedDir, sf::Color::Red));
		return true;
	}
	return false;
}