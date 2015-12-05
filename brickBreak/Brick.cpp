#include "Ball.h"
#include "Brick.h"
#include "BallsHandler.h"


Brick::Brick(sf::Vector2f position, sf::Vector2f dimension, sf::Texture*& texture)
{
	dim = dimension;
	pos = position;
	tex = texture;
	(*tex).setSmooth(true);
}


void Brick::draw(sf::RenderWindow& window)
{
	sf::RectangleShape brick(dim);
	brick.setPosition(pos);
	brick.setTexture(tex);
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

sf::Texture* Brick::getTexture() const
{
	return tex;
}

int Brick::onCollision()
{
	if (hits > 0)
	{
		hits--;
		if (hits == 2)
		// Set adapted texture
		{
			tex = new sf::Texture;
			if (!(*tex).loadFromFile("strong2Texture.jpg"))
			{
				std::puts("error loading strong texture\n");
			}
		}
		else if (hits == 1)
		// Set adapted texture
		{
			tex = new sf::Texture;
			if (!(*tex).loadFromFile("normalTexture.jpg"))
			{
				std::puts("error loading normal texture\n");
			}
		}
	}
	
	return 0;
}

double Brick::getTanBrick() const
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