
#ifndef DEF_BALL
#define DEF_BALL

#include "Brick.h"
#include "bar.h"
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(sf::Vector2f, int, sf::Vector2f);
	~Ball();
	int move(sf::Vector2f&);
	int isInsideScreen(sf::Vector2f&);
	int isColliding(class Brick&);
	int isColliding(Ball& otherBall);
	int isColliding(class Bar&);
	int getRadius() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getSpeed() const;
	int setSpeed(sf::Vector2f& vitesse);
private:
	int radius;
	sf::Vector2f speed;
	sf::Vector2f pos;
	double spin = 0;
};

#endif

