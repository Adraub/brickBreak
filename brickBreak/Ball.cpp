#include "Ball.h"


Ball::Ball(sf::Vector2f position, int rayon, sf::Vector2f vitesse, sf::Color colori )
{
	radius=rayon;
	speed=vitesse;
	pos=position;
	color = colori;
}



int Ball::move(sf::Vector2f& resolution)
{
	pos += speed;
	return 1;
}


bool Ball::isInsideScreen(sf::Vector2f& resolution) 
{
	if (pos.y + radius * 2 > resolution.y)
	{
		return false;
	}
	else if (pos.y <= 0)
	{
		/*ball on the top of the window*/
		speed.y = -speed.y;
	}
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
	return true;
}


int Ball::isColliding(class Brique& brick)
{
	if (brick.getPos().y <= (pos.y + 2 * radius) && pos.y <= (brick.getPos().y + brick.getDim().y))
	{
		/*ball inside horizontal limits of the brick*/
		if (brick.getPos().x <= (pos.x + 2 * radius) && pos.x <= (brick.getPos().x + brick.getDim().x))
		{
			/*ball inside vertical limits of the brick*/
			if (pos.y +radius >= brick.getPos().y + (pos.x+ radius- brick.getPos().x)*brick.getTanBrique())
			{
				if (pos.y +radius >= brick.getPos().y + brick.getDim().y - (pos.x +radius - brick.getPos().x)*brick.getTanBrique())
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
				if (pos.y + radius >= brick.getPos().y + brick.getDim().y - (pos.x +radius- brick.getPos().x)*brick.getTanBrique())
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
					/*Up position*/
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
			if (pos.y + radius >= bar.getPos().y + (pos.x + radius - bar.getPos().x)*bar.getTanBar())
			{
				if (pos.y + radius < bar.getPos().y + bar.getDim().y - (pos.x + radius - bar.getPos().x)*bar.getTanBar())
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
				if (pos.y + radius >= bar.getPos().y + bar.getDim().y - (pos.x + radius - bar.getPos().x)*bar.getTanBar())
				{
					/*right position*/
					if (speed.x < 0)
					{
						speed.x = -speed.x;
					}
				}
				else
				{
					/*up position*/
					if (speed.y > 0)
					{
						double constantSpeedAdjust(1);
						double coeff(1);
						double midBar = bar.getPos().x + bar.getDim().x / 2;
						double xToCenter = midBar-pos.x;
						double realSpeed = sqrt(speed.x*speed.x + speed.y*speed.y); // to be kept constant

						speed.y = -speed.y; //the rebound itself

						if (speed.x * xToCenter > 0) //  = cases where ball moves from left to right and bounces on left side or from right to left and on right side
						{
							speed.y -= abs(xToCenter)*0.12;
						}
						else if (speed.x * xToCenter < 0)
						{
							if (speed.x>0) speed.x += abs(xToCenter)*0.12;
							else speed.x -= abs(xToCenter)*0.12;
						}
						else {}
						constantSpeedAdjust = realSpeed / (sqrt(speed.x*speed.x + speed.y*speed.y));
						speed.x = constantSpeedAdjust*speed.x;
						speed.y = constantSpeedAdjust*speed.y;
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
	if (distance <= (*this).getRadius()+ otherBall.getRadius())
	{
		/*Conservation of cinetic energy*/
		double energy = pow(otherBall.getRadius(),2)*(pow(otherBall.getSpeed().x, 2) + pow(otherBall.getSpeed().y, 2))
			+ pow(radius, 2)*(pow(speed.x, 2) + pow(speed.y, 2));
		/*Energy reparted equally between each balls*/
		energy /= 2;
		double vitesse= sqrt(energy / pow(otherBall.getRadius(), 2));
		sf::Vector2f speed;
		speed.x = diff.x * vitesse;
		speed.y = diff.y * vitesse;
		/*Balls are rejecting each other*/
		otherBall.setSpeed(-speed);
		vitesse = sqrt(energy / pow(radius, 2));
		speed.x = diff.x * vitesse;
		speed.y = diff.y * vitesse;
		(*this).setSpeed(speed);
	}
	return 1;
}

int Ball::getRadius() {
	return radius;
}

sf::Vector2f Ball::getPosition() {
	return pos;

}

sf::Vector2f Ball::getSpeed() {
	return speed;

}

sf::Color Ball::getColor()
{
	return color;
}

int Ball::setSpeed(sf::Vector2f& vitesse) {
	speed = vitesse;
	return 0;
}