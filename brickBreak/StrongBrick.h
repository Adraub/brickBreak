#ifndef DEF_STRONGBRICK
#define DEF_STRONGBRICK

#include "Brick.h"

class StrongBrick : public Brick {
public:
	StrongBrick(sf::Vector2f, sf::Vector2f, sf::Color, int);
	virtual void draw(sf::RenderWindow&);
};


#endif