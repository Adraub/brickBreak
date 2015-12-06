#ifndef DEF_BONUSBRICK
#define DEF_BONUSBRICK

#include "Brick.h"

/*Special brick that throws a particle when destroyed*/

class BonusBrick : public Brick {
public:
	BonusBrick(sf::Vector2f, sf::Vector2f, sf::Texture*&);

	virtual bool BonusBrick::isDestroyed(std::vector<Ball>&, std::vector<Particle>&);
};


#endif