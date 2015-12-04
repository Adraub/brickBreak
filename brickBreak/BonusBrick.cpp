#include "BonusBrick.h"

BonusBrick::BonusBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris) : Brick(position, dimension, coloris)
{
	hits = 1;
}


void BonusBrick::draw(sf::RenderWindow& window)
{
	Brick::draw(window);
	sf::CircleShape trappedBall(10);
	trappedBall.setPosition(sf::Vector2f((pos.x + dim.x / 2) - 10, (pos.y + dim.y / 2) - 10));
	trappedBall.setFillColor(sf::Color::Green);
	window.draw(trappedBall);
}

bool BonusBrick::isDestroyed(std::vector<Ball>& ref, std::vector<Particle>& ParticleVector)
{
	Brick::isDestroyed(ref, ParticleVector);
	if (hits == 0) {
		/*Send the ball created in a random direction*/
		ParticleVector.push_back(Particle(sf::Vector2f( (pos.x + dim.x / 2) - 10, (pos.y + dim.y / 2) - 10), 10, sf::Vector2f(0,2), sf::Color::Green));
		return true;
	}
	return false;
}