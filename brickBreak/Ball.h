#ifndef DEF_BALL
#define DEF_BALL

#include "bar.h"
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(sf::Vector2f, float, sf::Vector2f, sf::Color);
	void move(sf::Vector2f&);
	bool isInsideScreen(sf::Vector2f&);
	bool isColliding(class Brick&);
	bool isColliding(Ball& otherBall);
	bool isColliding(class Bar&);
	float getRadius() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getSpeed() const;
	bool setSpeed(sf::Vector2f& vitesse);
	sf::Color getColor() const;

private:
	float radius;
	sf::Vector2f speed;
	sf::Vector2f pos;
	sf::Color color;
	sf::Vector2f maxSpeed=sf::Vector2f(500,500);
};

#endif

