#include "bar.h"

Bar::Bar(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris)
{
	dim = dimension;
	pos = position;
	color = coloris;
	tanBar = dim.y / dim.x;
}


Bar::~Bar()
{
}

sf::Vector2f Bar::getDim()
{
	return dim;
}

int Bar::isInsideScreen(sf::Vector2f& resolution)
{
	if (pos.x + dim.x > resolution.x)
	{
		// bar on the right of the window
		pos.x = resolution.x - dim.x;
	}
	if (pos.x < 0)
	{
		// bar on the left of the window
		pos.x = 0;
	}
	return 1;
}

sf::Vector2f Bar::getPos()
{
	return pos;
}

sf::Color Bar::getColor()
{
	return color;
}

double Bar::getTanBar()
{
	return tanBar;
}

int Bar::setPosx(float posx)
{
	pos.x = posx;
	return 1;
}