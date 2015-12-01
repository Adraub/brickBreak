#ifndef DEF_LEVEL
#define DEF_LEVEL
#include "BallsHandler.h"
#include "Score.h"
#include "StrongBrick.h"
#include "BallBrick.h"
#include "Menu.h"

class Level
{
public:
	Level(sf::Vector2f, int, Score&);
	void forward(sf::Vector2f,sf::RenderWindow&, Menu&);
	void setBarPosition(float);
	float getBarPosition();
	void createBricks(int level);
	void deleteDestroyedBricks();
	void drawComponents(sf::RenderWindow&, sf::Vector2f&);
	bool isOver();

private:
	/*Bricks array*/
	std::vector<Brick*> myBricks;
	BallsHandler balls= BallsHandler();
	Bar bar;
	Score score;
	/*keyboard sensibility*/
	int keyboardSensibility;
};

#endif
