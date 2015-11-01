#include "BallsHandler.h"
#include "Brick.h"

BallsHandler::BallsHandler()
{
	standardBallSpeed= sf::Vector2f(7, 7);
}

int BallsHandler::move(sf::Vector2f& resolution, Bar& bar, std::vector<Brick*>& myBricks)
{
	ballsCollision();
	ballsMove(resolution);
	barCollision(bar);
	bricksCollision(myBricks);
	return 1;
}

int BallsHandler::ballsCollision()
{
	for (unsigned int i = 0; i < myBalls.size(); i++)
	{
		for (unsigned int k = 1; i + k < myBalls.size(); k++)
		{
			myBalls[i].isColliding(myBalls[k + i]);
		}
	}
	return 1;
}

int BallsHandler::ballsMove(sf::Vector2f& resolution)
{
	for (unsigned int i = 0; i < myBalls.size(); i++)
	{
		myBalls[i].move(resolution);
		if (!myBalls[i].isInsideScreen(resolution))
		{
			myBalls.erase(myBalls.begin() + i);
		}
	}
	return 1;
}

int BallsHandler::barCollision(Bar& bar)
{
	for (unsigned int i = 0; i < myBalls.size(); i++)
	{
		myBalls[i].isColliding(bar);
	}
	return 1;
}

int BallsHandler::bricksCollision(std::vector<Brick*>& myBricks)
{
	for (unsigned int i = 0; i < myBalls.size(); i++)
	{
		for (unsigned int j = 0; j < myBricks.size(); j++)
		{
			myBalls[i].isColliding(*myBricks[j]);
		}
	}
	return 1;
}


int BallsHandler::newBall(sf::Vector2f position, float radius, sf::Color color)
{
	Ball newBall = Ball(position, radius, standardBallSpeed, color);
	myBalls.push_back(newBall);
	return myBalls.size()-1;

}

int BallsHandler::aliveBalls()
{
	return myBalls.size();

}

std::vector<Ball> BallsHandler::getBalls()
{
	return myBalls;
}
