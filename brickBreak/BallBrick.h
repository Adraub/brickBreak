#ifndef DEF_BALLBRICK
#define DEF_BALLBRICK

#include "Brick.h"

/*Special break that throws a ball when destroyed*/

class BallBrick : public Brick {
public:
	BallBrick(sf::Vector2f, sf::Vector2f, sf::Texture*&);

	virtual bool BallBrick::isDestroyed(std::vector<Ball>&,std::vector<Particle>&);
};


#endif
