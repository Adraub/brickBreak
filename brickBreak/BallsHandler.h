#ifndef DEF_BALLSHANDLER
#define DEF_BALLSHANDLER
#include "Ball.h"
#include "Brick.h"
#include "bar.h"

/*Class that handle commons operation related to ball vector*/

class BallsHandler
{
public:
	BallsHandler();
	void move(sf::Vector2f&, Bar&, std::vector<Brick*>& );
	void ballsMove(sf::Vector2f&);
	void ballsCollision();
	void barCollision(Bar&);
	void bricksCollision(std::vector<Brick*>&);
	unsigned int newBall(sf::Vector2f, float , sf::Color );
	unsigned int aliveBalls();
	void launchBall(Bar&);
	void draw(sf::RenderWindow&);
	std::vector<Ball>& getBalls();

private:
	std::vector<Ball> myBalls; /*Balls array*/
	sf::Vector2f standardBallSpeed; /*default ball speed*/
};

#endif
