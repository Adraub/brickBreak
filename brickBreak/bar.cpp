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


int Bar::upCollision(sf::Vector2f& speed, sf::Vector2f& ballPos)
{
	double constantSpeedAdjust(1);
	double coeff(1);
	double midBar = getPos().x;
	double xToCenter = midBar - ballPos.x;
	double realSpeed = sqrt(speed.x*speed.x + speed.y*speed.y); // to be kept constant
	double diffractionRate(0.08);
	speed.y = -speed.y; //the rebound itself

	if (speed.x * xToCenter > 0) //  = cases where ball moves from left to right and bounces on left side or from right to left and on right side
	{
		speed.y -= abs(xToCenter)*diffractionRate;
	}
	else if (speed.x * xToCenter < 0)
	{
		if (speed.x>0) speed.x += abs(xToCenter)*diffractionRate;
		else speed.x -= abs(xToCenter)*diffractionRate;
	}
	else if ((speed.x * xToCenter == 0) && (xToCenter != 0)) // special case where we still want the ball to be difracted
	{
		if (xToCenter>0) speed.x -= abs(xToCenter)*diffractionRate;// ball on the left
		else speed.x += abs(xToCenter)*diffractionRate;
	}
	constantSpeedAdjust = realSpeed / (sqrt(speed.x*speed.x + speed.y*speed.y));
	speed.x = constantSpeedAdjust*speed.x;
	speed.y = constantSpeedAdjust*speed.y;
	return 1;
}