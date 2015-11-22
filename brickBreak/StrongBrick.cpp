#include "StrongBrick.h"

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
	sf::RectangleShape brick2(sf::Vector2f(dim.x - 6, dim.y - 6));
	brick2.setPosition(sf::Vector2f(pos.x + 3, pos.y + 3));
	brick2.setFillColor(color);
	window.draw(brick2);
}