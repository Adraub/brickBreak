#include "Particle.h"
#include "Ball.h"
#include "Brick.h"
#include "bar.h"
#include "Score.h"

Particle::Particle(sf::Vector2f position, float rayon, sf::Vector2f vitesse, sf::Color coloris)
{
	radius = rayon;
	speed = vitesse;
	pos = position;
	color = coloris;
}



int Particle::move(sf::Vector2f& resolution)
{
	pos += speed;
	return 1;
}


sf::Vector2f Particle::getPosition() const {
	return pos;

}


bool Particle::isColliding(class Bar& bar)
{

	if (bar.getPos().y <= (pos.y + 2 * radius) && pos.y <= (bar.getPos().y + bar.getDim().y))
	{
		/*Particle inside horizontal limits of the bar*/
		if ((bar.getPos().x - bar.getDim().x / 2) <= (pos.x + 2 * radius) && pos.x <= (bar.getPos().x + bar.getDim().x / 2))
		{
			/*Particle inside vertical limits of the bar*/
			if (!(pos.y + radius >= bar.getPos().y + (pos.x + radius - (bar.getPos().x - bar.getDim().x / 2))*bar.getTanBar()))
			{
				if (!(pos.y + radius >= bar.getPos().y + bar.getDim().y - (pos.x + radius - (bar.getPos().x - bar.getDim().x / 2))*bar.getTanBar()))
				{
					/*up position*/
					return true;
				}
			}

		}
	}
	return false;
}


bool Particle::isLost()
{
	if (pos.y <0)
	{
		return true;
	}
	return false;
}

int Particle::giveBonus(BallsHandler& ball, Bar& bar, Score& score)
{
	static int alea;
	static int choice=0,precedent_choice=0;
	static int bar_width = 2;
	
	//definition of a random bonus
	do {
		alea = rand() % 8;
		if (alea < 2) {
			choice = 1;
		}
		if (alea>=3 & alea<4 & bar_width!=0) {
			choice = 2;
			--bar_width;
		}
		if (alea >= 5 & alea<6 & bar_width!=4) {
			choice = 3;
			++bar_width;
		}
		if (alea >= 7 & alea<8) {
			choice = 4;
		}
	} while (choice == precedent_choice);
	precedent_choice = choice;
	switch (choice)
	{
		case 1: {
			//bonus: new ball
			ball.launchBall(bar);
			break;
		}
		case 2:
		{
			//bonus: bar width divided by 2
			sf::Vector2f newdim;
			newdim.x = bar.getDim().x / 2;
			newdim.y = bar.getDim().y;
			bar.setDim(newdim);
			break;
		}
		case 3:
		{
			//bonus: bar multiplyed by 2
			sf::Vector2f newdim;
			newdim.x = bar.getDim().x * 2;
			newdim.y = bar.getDim().y;
			bar.setDim(newdim);
			break;
		}
		case 4:
		{
			//bonus: one life more
			score.increaseScore();
			break;
		}
	}
	return 1;
}


void Particle::draw(sf::RenderWindow& window)
{
	sf::CircleShape particleShape(radius);
	particleShape.setPosition(pos);
	particleShape.setFillColor(color);
	window.draw(particleShape);
}