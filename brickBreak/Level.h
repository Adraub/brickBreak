#ifndef DEF_LEVEL
#define DEF_LEVEL
#include "BallsHandler.h"
#include "Score.h"

class Level
{
public:
	Level(sf::Vector2f);
	void forward(sf::Vector2f,sf::RenderWindow&, Score&);
	void setBarPosition(float);
	float getBarPosition();

private:
	/*Bricks array*/
	std::vector<Brick*> myBricks;
	BallsHandler balls= BallsHandler();
	Bar bar;
	/*keyboard sensibility*/
	int keyboardSensibility;
};

#endif
