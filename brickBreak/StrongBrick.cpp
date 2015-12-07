#include "StrongBrick.h"

StrongBrick::StrongBrick(sf::Vector2f position, sf::Vector2f dimension, sf::Texture*& texture, int nb_hits) : Brick(position, dimension, texture)
{
	//definition of the number of hits to destroy
	hits = nb_hits;
}
