#include "BallsHandler.h"
#include "Brick.h"

BallsHandler::BallsHandler()
{
	standardBallSpeed= sf::Vector2f(0, -9);
}

void BallsHandler::move(sf::Vector2f& resolution, Bar& bar, std::vector<Brick*>& myBricks)
{
	ballsCollision();
	ballsMove(resolution);
	barCollision(bar);
	bricksCollision(myBricks);
}

void BallsHandler::ballsCollision()
{
	for (unsigned int i = 0; i < myBalls.size(); i++)
	{
		for (unsigned int k = 1; i + k < myBalls.size(); k++)
		{
			myBalls[i].isColliding(myBalls[k + i]);
		}
	}
}

void BallsHandler::ballsMove(sf::Vector2f& resolution)
{
	for (unsigned int i = 0; i < myBalls.size(); i++)
	{
		myBalls[i].move(resolution);
		if (!myBalls[i].isInsideScreen(resolution))
		{
			myBalls.erase(myBalls.begin() + i);
		}
	}
}

void BallsHandler::barCollision(Bar& bar)
{
	for (unsigned int i = 0; i < myBalls.size(); i++)
	{
		myBalls[i].isColliding(bar);
	}
}

void BallsHandler::bricksCollision(std::vector<Brick*>& myBricks)
{
	for (unsigned int i = 0; i < myBalls.size(); i++)
	{
		for (unsigned int j = 0; j < myBricks.size(); j++)
		{
			myBalls[i].isColliding(*myBricks[j]);
		}
	}
}


unsigned int BallsHandler::newBall(sf::Vector2f position, float radius, sf::Color color)
{
	Ball newBall = Ball(position, radius, standardBallSpeed, color);
	myBalls.push_back(newBall);
	return myBalls.size();

}

unsigned int BallsHandler::aliveBalls()
{
	return myBalls.size();
}

void BallsHandler::launchBall(Bar& bar)
{
	float radius = 10;
	sf::Vector2f posBall = sf::Vector2f(bar.getPos().x, bar.getPos().y-radius);
	newBall(posBall, radius, sf::Color::Red);
	bar.launchedBall();
}

std::vector<Ball>& BallsHandler::getBalls()
{
	return myBalls;
}

void BallsHandler::draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < aliveBalls(); i++)
	{
		//draw the balls

		sf::CircleShape ballShape(myBalls[i].getRadius());
		ballShape.setPosition(myBalls[i].getPosition());
		ballShape.setFillColor(myBalls[i].getColor());
		window.draw(ballShape);
	}
}
