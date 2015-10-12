
#ifndef DEF_BALL
#define DEF_BALL

#include "Brique.h"
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(sf::Vector2f, int, sf::Vector2f);
	~Ball();
	int move(sf::Vector2f&);
	int isInsideScreen(sf::Vector2f&);
	int Ball::isColliding(class Brique&);
	int isColliding(Ball& otherBall);
	int Ball::getRadius();
	sf::Vector2f Ball::getPosition();
	sf::Vector2f getSpeed();
	int setSpeed(sf::Vector2f& vitesse);
private:
	int radius;
	sf::Vector2f speed;
	sf::Vector2f pos;
	double spin = 0;
};

#endif

