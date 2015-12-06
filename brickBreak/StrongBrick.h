#ifndef DEF_STRONGBRICK
#define DEF_STRONGBRICK

#include "Brick.h"

/*Creates a brick that can be collided a specified number of time before it breaks*/

class StrongBrick : public Brick {
public:
	StrongBrick(sf::Vector2f, sf::Vector2f, sf::Texture*&, int);
};


#endif
