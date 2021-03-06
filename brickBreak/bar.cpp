#include "bar.h"

Bar::Bar()
{
}

Bar::Bar(sf::Vector2f position, sf::Vector2f dimension, sf::Color coloris, bool isball)
{
	dim = dimension;
	pos = position;
	color = coloris;
	ball = isball;
}



sf::Vector2f Bar::getDim() const
{
	return dim;
}

void Bar::isInsideScreen(sf::Vector2f& resolution)
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
}

sf::Vector2f Bar::getPos() const
{
	return pos;
}


double Bar::getTanBar() const
{
	return dim.y / dim.x;
}

void Bar::setPosx(float posx)
{
	pos.x = posx;
}


void Bar::setDim(sf::Vector2f newdim)
{
	dim = newdim;
}


void Bar::draw(sf::RenderWindow& window)
{
	sf::RectangleShape barShape(getDim());
	sf::RectangleShape barLeftEdge(sf::Vector2f(1.0f*getDim().x / 8.0f, getDim().y));
	sf::RectangleShape barRightEdge(sf::Vector2f(1.0f*getDim().x / 8.0f, getDim().y));
	barShape.setPosition(pos-sf::Vector2f(getDim().x / 2.0f,0.0f));
	barShape.setFillColor(color);
	barLeftEdge.setPosition(pos - sf::Vector2f(getDim().x / 2.0f, 0.0f));
	barRightEdge.setPosition(pos + sf::Vector2f(getDim().x / 2.0f, 0.0f)- sf::Vector2f(1.0f*getDim().x / 8.0f, 0.0f));
	window.draw(barShape);
	window.draw(barLeftEdge);
	window.draw(barRightEdge);
	if (isBall())
	{
		sf::Vector2f posBall = sf::Vector2f(pos.x , pos.y - 20);
		sf::CircleShape ballShape(10);
		ballShape.setPosition(posBall);
		ballShape.setFillColor(sf::Color::Red);
		window.draw(ballShape);
	}
}

bool Bar::isBall() const
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
	float constantSpeedAdjust(1);
	float xToCenter = getPos().x - ballPos.x;
	float realSpeed = sqrt(speed.x*speed.x + speed.y*speed.y); // to be kept constant
	float diffractionRate(0.08f);
	float speedBoostCoef(1.4f);
	speed.y = -speed.y; //the rebound itself
	if ((color==sf::Color::Blue) && (realSpeed < 13)) 
	{
		if (speed.x * xToCenter > 0) //  = cases where ball moves from left to right and bounces on left side or from right to left and on right side
		{
			if (abs(xToCenter) >= (3 * getDim().x / 8))
			{
				speed.x = -speed.x;
			}
			else speed.y -= abs(xToCenter)*diffractionRate;

		}
		else if (speed.x * xToCenter < 0)
		{
			if (speed.x > 0) speed.x += abs(xToCenter)*diffractionRate;
			else speed.x -= abs(xToCenter)*diffractionRate;
		}
		else if ((speed.x * xToCenter == 0) && (xToCenter != 0)) // special case where we still want the ball to be difracted
		{
			if (xToCenter > 0) speed.x -= abs(xToCenter)*diffractionRate;// ball on the left
			else speed.x += abs(xToCenter)*diffractionRate;
		}
		constantSpeedAdjust = realSpeed / (sqrt(speed.x*speed.x + speed.y*speed.y));
		speed.x = speedBoostCoef*constantSpeedAdjust*speed.x;
		speed.y = speedBoostCoef*constantSpeedAdjust*speed.y;

	}
	else
	{
		if (speed.x * xToCenter > 0) //  = cases where ball moves from left to right and bounces on left side or from right to left and on right side
		{
			if (abs(xToCenter) >= (3 * getDim().x / 8))
			{
				speed.x = -speed.x;
			}
			else speed.y -= abs(xToCenter)*diffractionRate;

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
}
	return 1;
}

void Bar::setColor(sf::Color coloris)
{
	color = coloris;
}

sf::Color Bar::getColor() const
{
	return color;
}
