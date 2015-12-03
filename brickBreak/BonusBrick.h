#ifndef DEF_BONUSBRICK
#define DEF_BONUSBRICK

#include "Brick.h"

class BonusBrick : public Brick {
public:
	BonusBrick(sf::Vector2f, sf::Vector2f, sf::Color);
	virtual void draw(sf::RenderWindow&);
	virtual bool BonusBrick::isDestroyed(std::vector<Ball>&, std::vector<Particle>&);

};


#endif