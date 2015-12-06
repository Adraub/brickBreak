#include <iostream>
#include <gtest/gtest.h>
#include "Ball.h"
#include "Brick.h"
#include "Score.h"

TEST(ball, creation)
{
	Ball ball=Ball(sf::Vector2f(2,4), 0.50f, sf::Vector2f(2, 15), sf::Color::Yellow);
	EXPECT_EQ(0.50f, ball.getRadius());
	EXPECT_EQ(sf::Vector2f(2, 15), ball.getSpeed());
	EXPECT_EQ(sf::Vector2f(2, 4), ball.getPosition());
	ball.setSpeed(sf::Vector2f(15.33f, 140.33f));
	EXPECT_EQ(sf::Vector2f(15.33f, 140.33f), ball.getSpeed());
	ball.setSpeed(sf::Vector2f(500, 501));
	EXPECT_EQ(sf::Vector2f(15.33f, 140.33f), ball.getSpeed());
	EXPECT_EQ(sf::Color::Yellow, ball.getColor());
	EXPECT_EQ(true, ball.isColliding(ball));
}

TEST(brick, creation)
{
	sf::Texture* normalTexture = new sf::Texture;
	if (!(*normalTexture).loadFromFile("normalTexture.jpg"))
	{
		std::puts("error loading normal texture\n");
	}
	Brick brick=Brick(sf::Vector2f(2, 4), sf::Vector2f(15, 15), normalTexture);
	EXPECT_EQ(sf::Vector2f(2, 4), brick.getPos());
	EXPECT_EQ(sf::Vector2f(15, 15), brick.getDim());
	EXPECT_EQ(normalTexture, brick.getTexture());
	EXPECT_EQ(1, brick.getTanBrick());
	EXPECT_EQ(1, brick.getHits());
}

TEST(bar, creation)
{
	Bar bar = Bar(sf::Vector2f(2, 4), sf::Vector2f(15, 15), sf::Color::Blue, true);
	EXPECT_EQ(sf::Vector2f(2, 4), bar.getPos());
	EXPECT_EQ(sf::Vector2f(15, 15), bar.getDim());
	EXPECT_EQ(1, bar.getTanBar());
	EXPECT_EQ(true, bar.isBall());
}

TEST(handler, creation)
{
	BallsHandler ballshandler=BallsHandler();
	ballshandler.newBall(sf::Vector2f(2, 4), 0.50f, sf::Color::Yellow);
	EXPECT_EQ(1, ballshandler.aliveBalls());
}

TEST(score, creation)
{
	Score score(0);
	EXPECT_EQ(0, score.getLives());
	score.initialize();
	EXPECT_EQ(3, score.getLives());
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
}