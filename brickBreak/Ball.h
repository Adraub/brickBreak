#ifndef DEF_BALL
#define DEF_BALL

#include "bar.h"
#include <SFML/Graphics.hpp>

/*Handles ball effects and moving*/

class Ball
{
public:
	Ball(sf::Vector2f, float, sf::Vector2f, sf::Color);

	void move(sf::Vector2f&);
	bool isInsideScreen(sf::Vector2f&);
	bool isColliding(class Brick&);
	bool isColliding(Ball& otherBall);
	bool isColliding(class Bar&);
	bool setSpeed(sf::Vector2f& vitesse);
	sf::Vector2f getPosition() const;
	sf::Vector2f getSpeed() const;
	float getRadius() const;
	sf::Color getColor() const;

private:
	float radius;
	sf::Vector2f speed;
	sf::Vector2f pos; /*position of its up left corner*/
	sf::Color color;
	sf::Vector2f maxSpeed=sf::Vector2f(500,500);
};

#endif

