#ifndef DEF_BALLSHANDLER
#define DEF_BALLSHANDLER
#include "Ball.h"
#include "Brick.h"
#include "bar.h"

class BallsHandler
{
public:
	BallsHandler();
	int move(sf::Vector2f&, Bar&, std::vector<Brick*>& );
	int ballsCollision();
	int barCollision(Bar&);
	int bricksCollision(std::vector<Brick*>&);
	int ballsMove(sf::Vector2f&);
	int newBall(sf::Vector2f, float , sf::Color );
	int aliveBalls();
	int launchBall(Bar&);
	std::vector<Ball>& getBalls();
	void draw(sf::RenderWindow&);

private:
	std::vector<Ball> myBalls; /*Balls array*/
	sf::Vector2f standardBallSpeed; /*default ball speed*/
};

#endif
