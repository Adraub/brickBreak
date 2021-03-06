#include "Ball.h"
#include "Brick.h"

Ball::Ball(sf::Vector2f position, float rayon, sf::Vector2f vitesse, sf::Color colori )
{
	radius=rayon;
	speed=vitesse;
	pos=position;
	color = colori;
}



void Ball::move(sf::Vector2f& resolution)
{
	pos += speed;
}


bool Ball::isInsideScreen(sf::Vector2f& resolution) 
{
	if (pos.y > resolution.y)
	{
		/*ball is out of the screen, at the bottom*/
		return false;
	}
	else if (pos.y <= 0)
	{
		/*ball reflected on the top of the window*/
		speed.y = -speed.y;
		if (speed.y == 0)
		{
			speed.y = 1;
		}
	}
	if (pos.x + radius * 2 >= resolution.x)
	{
		/*Ball reflected on the right corner*/
		speed.x = -speed.x;
		if (speed.x == 0)
		{
			speed.x = -1;
		}
	}
	else if (pos.x <= 0)
	{
		/*ball reflected on the left corner*/
		speed.x = -speed.x;
		if (speed.x == 0)
		{
			speed.x = 1;
		}
	}
	return true;
}


bool Ball::isColliding(class Brick& brick)
{
	if (brick.getPos().y <= (pos.y + 2 * radius) && pos.y <= (brick.getPos().y + brick.getDim().y))
	{
		/*ball inside horizontal limits of the brick*/
		if (brick.getPos().x <= (pos.x + 2 * radius) && pos.x <= (brick.getPos().x + brick.getDim().x))
		{
			/*ball inside vertical limits of the brick*/
			if (pos.y +radius >= brick.getPos().y + (pos.x+ radius- brick.getPos().x)*brick.getTanBrick())
			{
				if (pos.y +radius >= brick.getPos().y + brick.getDim().y - (pos.x +radius - brick.getPos().x)*brick.getTanBrick())
				{
					/*Down position*/
					if (speed.y < 0)
					{
						speed.y = -speed.y;
						brick.onCollision();
						return true;
					}
					else if (speed.y == 0)
					{
						speed.y = 1;
						return true;
					}
				}
				else
				{
					/*left position*/
					if (speed.x > 0)
					{
						speed.x = -speed.x;
						brick.onCollision();
						return true;
					}
					else if (speed.x == 0)
					{
						speed.x = -1;
						return true;
					}
				}
			}
			else
			{
				if (pos.y + radius >= brick.getPos().y + brick.getDim().y - (pos.x +radius- brick.getPos().x)*brick.getTanBrick())
				{
					/*right position*/
					if (speed.x < 0)
					{
						speed.x = -speed.x;
						brick.onCollision();
						return true;
					}
					else if (speed.x == 0)
					{
						speed.x = 1;
						return true;
					}
				}
				else
				{
					/*Up position*/
					if (speed.y > 0)
					{
						speed.y = -speed.y;
						brick.onCollision();
						return true;
					}
					else if (speed.y == 0)
					{
						speed.y = -1;
						return true;
					}
				}
			}

		}
	}
	return false;
}

bool Ball::isColliding(class Bar& bar)
{
	if (bar.getPos().y <= (pos.y + 2 * radius) && pos.y <= (bar.getPos().y + bar.getDim().y))
	{
		/*ball inside horizontal limits of the bar*/
		if ((bar.getPos().x-bar.getDim().x/2) <= (pos.x + 2 * radius) && pos.x <= (bar.getPos().x + bar.getDim().x/2))
		{
			/*ball inside vertical limits of the bar*/
			if (pos.y + radius >= bar.getPos().y + (pos.x + radius - (bar.getPos().x - bar.getDim().x / 2))*bar.getTanBar())
			{
				if (pos.y + radius < bar.getPos().y + bar.getDim().y - (pos.x + radius - (bar.getPos().x - bar.getDim().x / 2))*bar.getTanBar())
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
				if (pos.y + radius >= bar.getPos().y + bar.getDim().y - (pos.x + radius - (bar.getPos().x - bar.getDim().x / 2))*bar.getTanBar())
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
						bar.upCollision(speed, getPosition());
					}
				}
			}

		}
	}
	return false;
}

bool Ball::isColliding(class Ball& otherBall)
{
	sf::Vector2f diff = this->getPosition() - otherBall.getPosition();
	float distance = sqrt(pow(diff.x, 2) + pow(diff.y, 2));
	diff.x /= distance;
	diff.y /= distance;
	if (distance <= this->getRadius()+ otherBall.getRadius())
	{
		/*Conservation of cinetic energy*/
		float energy = pow(otherBall.getRadius(),2)*(pow(otherBall.getSpeed().x, 2) + pow(otherBall.getSpeed().y, 2))
			+ pow(radius, 2)*(pow(speed.x, 2) + pow(speed.y, 2));
		/*Energy reparted equally between each balls*/
		energy /= 2;
		float vitesse= sqrt(energy / pow(otherBall.getRadius(), 2));
		sf::Vector2f speed;
		speed.x = diff.x * vitesse;
		speed.y = diff.y * vitesse;
		/*Balls are rejecting each other*/
		otherBall.setSpeed(-speed);
		vitesse = sqrt(energy / pow(radius, 2));
		speed.x = diff.x * vitesse;
		speed.y = diff.y * vitesse;
		this->setSpeed(speed);
		return true;
	}
	return false;
}

float Ball::getRadius() const {
	return radius;
}

sf::Vector2f Ball::getPosition() const {
	return pos;

}

sf::Vector2f Ball::getSpeed() const {
	return speed;

}

sf::Color Ball::getColor() const
{
	return color;
}

bool Ball::setSpeed(sf::Vector2f& vitesse) {
  if (pow(vitesse.x, 2) + pow(vitesse.y, 2) < pow(maxSpeed.x, 2) + pow(maxSpeed.y, 2))
  {
	 /*limited ball speed*/
  	speed = vitesse;
  	return true;
  }
  return false;
}