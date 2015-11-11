#include "Level.h"

//class Brick//
Level::Level(sf::Vector2f resolution)
{

	/*keyboard sensibility*/
	keyboardSensibility=20;
	float cpt_h = 0, cpt_v = 0;
	//creation of the ball
	bar=Bar(sf::Vector2f((resolution.x - 350) / 2, resolution.y - 35), sf::Vector2f(350, 35), sf::Color::Red,false);
	bar.addBall();
	//creation of the bricks
	for (cpt_v = 0; cpt_v < 5; cpt_v++) {
		for (cpt_h = 0; cpt_h < 6; cpt_h++) {
			myBricks.push_back(new ClassicBrick(sf::Vector2f(300 + 2 * cpt_h * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow));
			if (cpt_h < 5) {
				if (cpt_v == 0 || cpt_v == 2 || cpt_v == 4) {
					myBricks.push_back(new StrongBrick(sf::Vector2f(300 + (2 * cpt_h + 1) * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow, 3));
				}
				else {
					myBricks.push_back(new BallBrick(sf::Vector2f(300 + (2 * cpt_h + 1) * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow, balls.getBalls()));
				}
			}
		}
	}
}

void Level::forward(sf::Vector2f resolution, sf::RenderWindow& window, Score& score)
{

	// keyboard direction action
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setBarPosition(getBarPosition() - keyboardSensibility);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setBarPosition(getBarPosition() + keyboardSensibility);
	}

	// launch ball in bar
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bar.isBall())
	{
		balls.launchBall(bar);
	}
	// test to reduce score 
	if (balls.aliveBalls() == 0 && !bar.isBall())
	{
		score.reduceScore();
		if (score.getScore() < 0)
		{
			window.close();
		}
		bar.addBall();
	}
	//check bar position
	bar.isInsideScreen(resolution);

	balls.move(resolution, bar, myBricks);
	// draw frame

	for (unsigned int j = 0; j < myBricks.size(); j++)
	{
		//draw the balls
		myBricks[j]->draw(window);

		//detection of destroyed bricks
		if (myBricks[j]->isDestroyed() == true)
		{
			myBricks.erase(myBricks.begin() + j);
		}
	}

	// draw bar
	bar.draw(window);
	balls.draw(window);
}

void Level::setBarPosition(float barpos)
{
	bar.setPosx(barpos);
}

float Level::getBarPosition()
{
	return bar.getPos().x;
}

