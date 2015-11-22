#ifndef DEF_LEVEL
#define DEF_LEVEL
#include "BallsHandler.h"
#include "Score.h"
#include "StrongBrick.h"
#include "BallBrick.h"

class Level
{
public:
	Level(sf::Vector2f, int);
	void forward(sf::Vector2f,sf::RenderWindow&, Score&);
	void setBarPosition(float);
	float getBarPosition();
	void createBricks(int level);

private:
	/*Bricks array*/
	std::vector<Brick*> myBricks;
	BallsHandler balls= BallsHandler();
	Bar bar;
	/*keyboard sensibility*/
	int keyboardSensibility;
};

#endif
