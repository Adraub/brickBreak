#include "Level.h"

//class Brick//
Level::Level(sf::Vector2f resolution, int number)
{

	/*keyboard sensibility*/
	keyboardSensibility=20;
	//creation of the ball
	bar=Bar(sf::Vector2f((resolution.x - 350) / 2, resolution.y - 35), sf::Vector2f(350, 35), sf::Color::Red,false);
	bar.addBall();
	createBricks(number);
}

void Level::forward(sf::Vector2f resolution, sf::RenderWindow& window, Score& score)
{

	// test null score
	if (score.getScore() == 0 || myBricks.size()==0)
	{
		window.close();
	}

	// keyboard direction action
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setBarPosition(getBarPosition() - keyboardSensibility);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setBarPosition(getBarPosition() + keyboardSensibility);
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)|| sf::Mouse::isButtonPressed(sf::Mouse::Left)) && bar.isBall())
	{
		// launch ball in bar
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

	for (unsigned int j = 0; j < myBricks.size(); j++)
	{
		//detection of destroyed bricks
		if (myBricks[j]->isDestroyed())
		{
			myBricks.erase(myBricks.begin() + j);
		}
		//draw the balls
		if (j < myBricks.size())
		{
			myBricks[j]->draw(window);
		}
	}

	bar.draw(window);
	balls.draw(window);
	// show score
	window.draw(score.textScore(resolution));
}

void Level::setBarPosition(float barpos)
{
	bar.setPosx(barpos);
}

float Level::getBarPosition()
{
	return bar.getPos().x;
}

void Level::createBricks(int level)
{

	float cpt_h = 0, cpt_v = 0;
	//creation of the bricks
	if (level == 1)
	{
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
	}else{
		for (cpt_v = 0; cpt_v < 5; cpt_v++) {
			for (cpt_h = 0; cpt_h < 6; cpt_h++) {
				myBricks.push_back(new ClassicBrick(sf::Vector2f(300 + 2 * cpt_h * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow));
				if (cpt_h < 5) {
					if (cpt_v == 0 || cpt_v == 2 || cpt_v == 4) {
						myBricks.push_back(new BallBrick(sf::Vector2f(300 + (2 * cpt_h + 1) * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow, balls.getBalls()));
					}
					else {
						myBricks.push_back(new StrongBrick(sf::Vector2f(300 + (2 * cpt_h + 1) * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow, 3));
						
					}
				}
			}
		}
	}
	
}

