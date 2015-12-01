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
	void setBarPositionY(float);
	float getBarPosition();
	float getBarPositionY();
	void createBricks(int level);
	void deleteDestroyedBricks();
	void drawComponents(sf::RenderWindow&, sf::Vector2f&);
	bool isOver();
	void finishLevel();
	bool isFinished();
	void posArrayBarAdd(float);

private:
	// Bricks array
	std::vector<Brick*> myBricks;
	BallsHandler balls= BallsHandler();
	Bar bar;
	Score score;
	// Keyboard sensibility
	int keyboardSensibility;
	// Level status
	bool levelFinished;
};

#endif
