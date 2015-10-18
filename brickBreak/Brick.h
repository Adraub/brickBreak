#ifndef DEF_BRICK
#define DEF_BRICK

#include "Ball.h"
#include <SFML/Graphics.hpp>

class Brick {
public:
	Brick(sf::Vector2f, sf::Vector2f, sf::Color);
	~Brick();
	sf::Vector2f getDim() const;
	sf::Vector2f getPos() const;
	sf::Color getColor() const;
	int onCollision();
	double getTanBrique() const;
	bool isDestroyed();

protected:
	sf::Vector2f pos;
	sf::Vector2f dim;
	sf::Color color;
	double tanBrick;
	std::string texture;
	int hits;
	bool destroyed;

};

#endif