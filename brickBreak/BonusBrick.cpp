#include "BonusBrick.h"

BonusBrick::BonusBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Texture*& texture) : Brick(position, dimension, texture)
{
	
}

bool BonusBrick::isDestroyed(std::vector<Ball>& ref, std::vector<Particle>& ParticleVector)
{
	Brick::isDestroyed(ref, ParticleVector);
	if (hits == 0) {
		ParticleVector.push_back(Particle(sf::Vector2f( (pos.x + dim.x / 2) - 10, (pos.y + dim.y / 2) - 10), 10, sf::Vector2f(0,2), sf::Color::Green));
		return true;
	}
	return false;
}