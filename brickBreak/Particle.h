#ifndef DEF_PARTICLE
#define DEF_PARTICLE

#include "bar.h"
#include "BallsHandler.h"
#include "Score.h"
#include <SFML/Graphics.hpp>

class Particle
{
public:
	Particle(sf::Vector2f, float, sf::Vector2f, sf::Color);
	int move(sf::Vector2f&);
	bool isColliding(class Bar&);
	bool isLost();
	int giveBonus(class BallsHandler&, class Bar&, class Score&);
	void draw(sf::RenderWindow&);
	sf::Vector2f getPosition() const;

private:
	float radius;
	sf::Vector2f speed;
	sf::Vector2f pos;
	sf::Color color;
};

#endif

