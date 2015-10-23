
#ifndef DEF_BALL
#define DEF_BALL

#include "Brick.h"
#include "bar.h"
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(sf::Vector2f, float, sf::Vector2f, sf::Color);
	int move(sf::Vector2f&);
	bool isInsideScreen(sf::Vector2f&);
	int isColliding(class Brick&);
	int isColliding(Ball& otherBall);
	int isColliding(class Bar&);
	float getRadius() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getSpeed() const;
	int setSpeed(sf::Vector2f& vitesse);
	sf::Color getColor();

protected:
	float radius;
	sf::Vector2f speed;
	sf::Vector2f pos;
	float spin = 0;
	sf::Color color;
};

#endif

