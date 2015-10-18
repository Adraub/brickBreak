#ifndef DEF_BRIQUE
#define DEF_BRIQUE

#include "Ball.h"
#include <SFML/Graphics.hpp>

class Brique {
public:
	Brique(sf::Vector2f, sf::Vector2f, sf::Color);
	~Brique();
	sf::Vector2f getDim() const;
	sf::Vector2f getPos() const;
	sf::Color getColor() const;
	int onCollision();
	double getTanBrique() const;
	bool isDestroyed();

private:
	sf::Vector2f pos;
	sf::Vector2f dim;
	sf::Color color;
	double tanBrick;
	std::string texture;
	int hits;
	bool destroyed;

};

#endif