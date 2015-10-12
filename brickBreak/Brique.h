#ifndef DEF_BRIQUE
#define DEF_BRIQUE

#include "Ball.h"
#include <SFML/Graphics.hpp>

class Brique {
public:
	Brique(sf::Vector2f, sf::Vector2f, sf::Color);
	~Brique();
	sf::Vector2f getDim();
	sf::Vector2f getPos();
	sf::Color getColor();
	int onCollision();
	double getTanBrique();

private:
	sf::Vector2f pos;
	sf::Vector2f dim;
	sf::Color color;
	double tanBrick;
	std::string texture;
	int hits = 0;

};

#endif