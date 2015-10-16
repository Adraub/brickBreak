
#ifndef DEF_BALL
#define DEF_BALL

#include "Brique.h"
#include "bar.h"
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(sf::Vector2f, int, sf::Vector2f, sf::Color);
	int move(sf::Vector2f&);
	int isInsideScreen(sf::Vector2f&);
	int isColliding(class Brique&);
	int isColliding(Ball& otherBall);
	int isColliding(class Bar&);
	int getRadius();
	sf::Vector2f getPosition();
	sf::Vector2f getSpeed();
	int setSpeed(sf::Vector2f& vitesse);
	sf::Color getColor();
private:
	int radius;
	sf::Vector2f speed;
	sf::Vector2f pos;
	double spin = 0;
	sf::Color color;
};

#endif

