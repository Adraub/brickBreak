#ifndef DEF_BALLSHANDLER
#define DEF_BALLSHANDLER
#include "Ball.h"
#include "Brick.h"
#include "bar.h"

class BallsHandler
{
public:
	BallsHandler();
	void move(sf::Vector2f&, Bar&, std::vector<Brick*>& );
	void ballsCollision();
	void barCollision(Bar&);
	void bricksCollision(std::vector<Brick*>&);
	void ballsMove(sf::Vector2f&);
	int newBall(sf::Vector2f, float , sf::Color );
	int aliveBalls();
	void launchBall(Bar&);
	std::vector<Ball>& getBalls();
	void draw(sf::RenderWindow&);

private:
	std::vector<Ball> myBalls; /*Balls array*/
	sf::Vector2f standardBallSpeed; /*default ball speed*/
};

#endif
