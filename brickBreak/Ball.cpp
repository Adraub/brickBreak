#include "Ball.h"


Ball::Ball(sf::Vector2f position, int rayon, sf::Vector2f vitesse )
{
	radius=rayon;
	speed=vitesse;
	pos=position;
}


Ball::~Ball()
{
}

int Ball::move(sf::Vector2f& resolution)
{
	isInsideScreen(resolution);
	pos += speed;
	return 1;
}


int Ball::isInsideScreen(sf::Vector2f& resolution) 
{
	if (pos.x + radius * 2 >= resolution.x)
	{
		/*Ball on the right corner*/
		speed.x = -speed.x;
	}
	else if (pos.x <= 0)
	{
		/*ball on the left corner*/
		speed.x = -speed.x;
	}
	if (pos.y <= 0)
	{
		/*ball on the top of the window*/
		speed.y = -speed.y;
	}
	return 1;
}


int Ball::isColliding(class Brick& brick)
{
	if (brick.getPos().y <= (pos.y + 2 * radius) && pos.y <= (brick.getPos().y + brick.getDim().y))
	{
		/*ball inside horizontal limits of the brick*/
		if (brick.getPos().x <= (pos.x + 2 * radius) && pos.x <= (brick.getPos().x + brick.getDim().x))
		{
			/*ball inside vertical limits of the brick*/
			if (pos.y >= brick.getPos().y + (pos.x - brick.getPos().x)*brick.getTanBrique())
			{
				if (pos.y >= brick.getPos().y + brick.getDim().y - (pos.x - brick.getPos().x)*brick.getTanBrique())
				{
					/*Down position*/
					if (speed.y < 0)
					{
						speed.y = -speed.y;
						brick.onCollision();
					}
				}
				else
				{
					/*left position*/
					if (speed.x > 0)
					{
						speed.x = -speed.x;
						brick.onCollision();
					}
				}
			}
			else
			{
				if (pos.y >= brick.getPos().y + brick.getDim().y - (pos.x - brick.getPos().x)*brick.getTanBrique())
				{
					/*right position*/
					if (speed.x < 0)
					{
						speed.x = -speed.x;
						brick.onCollision();
					}
				}
				else
				{
					/*down position*/
					if (speed.y > 0)
					{
						speed.y = -speed.y;
						brick.onCollision();
					}
				}
			}

		}
	}
	return 1;
}

int Ball::isColliding(class Bar& bar)
{
	if (bar.getPos().y <= (pos.y + 2 * radius) && pos.y <= (bar.getPos().y + bar.getDim().y))
	{
		/*ball inside horizontal limits of the bar*/
		if (bar.getPos().x <= (pos.x + 2 * radius) && pos.x <= (bar.getPos().x + bar.getDim().x))
		{
			/*ball inside vertical limits of the bar*/
			if (pos.y >= bar.getPos().y + (pos.x - bar.getPos().x)*bar.getTanBar())
			{
				if (pos.y < bar.getPos().y + bar.getDim().y - (pos.x - bar.getPos().x)*bar.getTanBar())
				{
					/*left position*/
					if (speed.x > 0)
					{
						speed.x = -speed.x;
					}
				}
			}
			else
			{
				if (pos.y >= bar.getPos().y + bar.getDim().y - (pos.x - bar.getPos().x)*bar.getTanBar())
				{
					/*right position*/
					if (speed.x < 0)
					{
						speed.x = -speed.x;
					}
				}
				else
				{
					/*down position*/
					if (speed.y > 0)
					{
						speed.y = -speed.y;
					}
				}
			}

		}
	}
	return 1;
}

int Ball::isColliding(class Ball& otherBall)
{
	sf::Vector2f diff = (*this).getPosition() - otherBall.getPosition();
	double distance = sqrt(pow(diff.x, 2) + pow(diff.y, 2));
	diff.x /= distance;
	diff.y /= distance;
	if (distance < std::max((*this).getRadius(), otherBall.getRadius()))
	{
		/*Conservation of cinetic energy*/
		double vitesse = pow(otherBall.getSpeed().x, 2) + pow(otherBall.getSpeed().y, 2)
			+ pow(speed.x, 2) + pow(speed.y, 2);
		vitesse = sqrt(vitesse);
		diff.x *= vitesse / sqrt(2);
		diff.y *= vitesse / sqrt(2);
		/*Balls are rejecting each other*/
		otherBall.setSpeed(-diff);
		(*this).setSpeed(diff);
	}
	return 1;
}

int Ball::getRadius() const {
	return radius;
}

sf::Vector2f Ball::getPosition() const {
	return pos;

}

sf::Vector2f Ball::getSpeed() const {
	return speed;

}

int Ball::setSpeed(sf::Vector2f& vitesse) {
	speed = vitesse;
	return 0;
}

