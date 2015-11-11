#include "bar.h"

Bar::Bar()
{
}

Bar::Bar(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris, bool isball)
{
	dim = dimension;
	pos = position;
	color = coloris;
	tanBar = dim.y / dim.x;
	ball = isball;
}



sf::Vector2f Bar::getDim() const
{
	return dim;
}

int Bar::isInsideScreen(sf::Vector2f& resolution)
{
	if (pos.x + dim.x/2 > resolution.x)
	{
		// bar on the right of the window
		pos.x = resolution.x - dim.x / 2;
	}
	if (pos.x - dim.x / 2 < 0)
	{
		// bar on the left of the window
		pos.x = dim.x / 2;
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

void Bar::draw(sf::RenderWindow& window)
{
	sf::RectangleShape barShape(getDim());
	barShape.setPosition(pos-sf::Vector2f(getDim().x / 2.0f,0.0f));
	barShape.setFillColor(getColor());
	window.draw(barShape);
	if (isBall())
	{
		sf::Vector2f posBall = sf::Vector2f(pos.x , pos.y - 20);
		sf::CircleShape ballShape(10);
		ballShape.setPosition(posBall);
		ballShape.setFillColor(sf::Color::Red);
		window.draw(ballShape);
	}
}

bool Bar::isBall()
{
	return ball;
}

void Bar::addBall()
{
	ball = true;
}

void Bar::launchedBall()
{
	ball = false;
}


