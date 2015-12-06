#include "Level.h"
#include "BonusBrick.h"

//class Brick//
Level::Level(sf::Vector2f resolution, int number, Score& scoring)
{

	//creation of the ball
	bar=Bar(sf::Vector2f((resolution.x - 350) / 2, resolution.y - 35), sf::Vector2f(350, 25), sf::Color::Red,false);
	bar.addBall();
	createBricks(number);
	score = scoring;
	levelFinished = false;
}

void Level::forward(sf::Vector2f resolution, sf::RenderWindow& window, Menu& menu)
{
	// test null score
	if (score.getLives() == 0)
	{
		/*display game over screen*/
		sf::Font* font = new sf::Font;
		if (!(*font).loadFromFile("arial.ttf"))
		{
			std::puts("error loading font\n");
		}
		sf::Text text("Game Over", *font);
		text.setCharacterSize(100);
		text.setStyle(sf::Text::Bold);
		text.setColor(sf::Color::Red);
		sf::FloatRect rect = text.getGlobalBounds();
		text.setPosition(sf::Vector2f(window.getSize().x/2 - rect.width/2, window.getSize().y/2 - rect.height/2));
		sf::Time t1 = sf::seconds(2);
		window.clear();
		window.draw(text);
		window.display();
		sf::sleep(t1);
		finishLevel();
	}

	// test null bricks
	if (isOver())
	{
		/*display level success screen*/
		sf::Font* font = new sf::Font;
		if (!(*font).loadFromFile("arial.ttf"))
		{
			std::puts("error loading font\n");
		}
		sf::Text text("You won!", *font);
		text.setCharacterSize(100);
		text.setStyle(sf::Text::Bold);
		text.setColor(sf::Color::Red);
		sf::FloatRect rect = text.getGlobalBounds();
		text.setPosition(sf::Vector2f(window.getSize().x / 2 - rect.width / 2, window.getSize().y / 2 - rect.height / 2));
		sf::Time t1 = sf::seconds(2);
		window.clear();
		window.draw(text);
		window.display();
		sf::sleep(t1);
		finishLevel();
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
		score.reduceLives();
		if (score.getLives() < 0)
		{
			window.close();
		}
		bar.addBall();
	}
	//check destroyed particles
	Level::checkParticleStates();
	// when the bar is blue (V pressed), it gives the ball a speedboost
	int loop(0);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::V)) && (loop == 0))
	{
		bar.setColor(sf::Color::Blue);
		loop = 1;
	}
	else if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::V))) 
	{
		bar.setColor(sf::Color::Red);
		loop = 0;
	}
	//check bar position
	bar.isInsideScreen(resolution);

	//update mouvements
	balls.move(resolution, bar, myBricks);
	for (unsigned int i = 0; i < myParticles.size(); i++)
	{
		myParticles[i].move(resolution);
	}

	deleteDestroyedBricks();
	drawComponents(window, resolution);

}

void Level::setBarPosition(float barpos)
{
	bar.setPosx(barpos);
}

float Level::getBarPosition() const
{
	return bar.getPos().x;
}

void Level::createBricks(int level)
{
	// Load level textures
	sf::Texture* normalTexture = new sf::Texture;
	if (!(*normalTexture).loadFromFile("normalTexture.jpg"))
	{
		std::puts("error loading normal texture\n");
	}

	sf::Texture* undestroyableTexture = new sf::Texture;
	if (!(*undestroyableTexture).loadFromFile("undestroyableTexture.jpg"))
	{
		std::puts("error loading undestroyable texture\n");
	}

	sf::Texture* strong3Texture = new sf::Texture;
	if (!(*strong3Texture).loadFromFile("strong3Texture.jpg"))
	{
		std::puts("error loading strong texture\n");
	}

	sf::Texture* ballTexture = new sf::Texture;
	if (!(*ballTexture).loadFromFile("ballTexture.jpg"))
	{
		std::puts("error loading ball texture\n");
	}

	sf::Texture* bonusTexture = new sf::Texture;
	if (!(*bonusTexture).loadFromFile("bonusTexture.jpg"))
	{
		std::puts("error loading bonus texture\n");
	}

	float cpt_x = 0, cpt_y = 0;
	// Creation of the bricks depending on the level selected
	if (level == 0)
	{
				
		// Create bricks
		for (cpt_y = 0; cpt_y < 5; cpt_y++) {
			for (cpt_x = 0; cpt_x < 6; cpt_x++) {
				myBricks.push_back(new Brick(sf::Vector2f(300 + 2 * cpt_x * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), normalTexture));
				if (cpt_x < 5) {
					if (cpt_y == 0 || cpt_y == 2 || cpt_y == 4) {
						myBricks.push_back(new BallBrick(sf::Vector2f(300 + (2 * cpt_x + 1) * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), ballTexture));
					}
					else {
						myBricks.push_back(new StrongBrick(sf::Vector2f(300 + (2 * cpt_x + 1) * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), strong3Texture, 3));

					}
				}
			}
		}
	}

	else if (level==1)
	{

		// Create bricks
		for (cpt_y = 0; cpt_y < 5; cpt_y++) {
			for (cpt_x = 0; cpt_x < 6; cpt_x++) {
				myBricks.push_back(new Brick(sf::Vector2f(300 + 2 * cpt_x * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), normalTexture));
				if (cpt_x < 5) {
					if (cpt_y == 0 || cpt_y == 2 || cpt_y == 4) {
						myBricks.push_back(new StrongBrick(sf::Vector2f(300 + (2 * cpt_x + 1) * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), undestroyableTexture, -1));
					}
					else {
						myBricks.push_back(new BonusBrick(sf::Vector2f(300 + (2 * cpt_x + 1) * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), bonusTexture));
					}
				}
			}
		}
	}

	else
	{
		

		// Create bricks
		for (cpt_y = 0; cpt_y < 5; cpt_y++) {
			for (cpt_x = 0; cpt_x < 6; cpt_x++) {
				if (cpt_y == 0 || cpt_y == 2 || cpt_y == 4)
				{
					myBricks.push_back(new Brick(sf::Vector2f(300 + 2 * cpt_x * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), normalTexture));
				}
				else
				{
					myBricks.push_back(new StrongBrick(sf::Vector2f(300 + 2 * cpt_x * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), strong3Texture, 3));
				}
				if (cpt_x < 5) {
					if (cpt_y == 0 || cpt_y == 2 || cpt_y == 4)
					{
						myBricks.push_back(new StrongBrick(sf::Vector2f(300 + (2 * cpt_x + 1) * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), undestroyableTexture, -1));
					}
					else if (cpt_x == 0 || cpt_x == 2 || cpt_x == 4)
					{
						myBricks.push_back(new BallBrick(sf::Vector2f(300 + (2 * cpt_x + 1) * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), ballTexture));
					}
					else
					{
						myBricks.push_back(new Brick(sf::Vector2f(300 + (2 * cpt_x + 1) * 120, 200 + cpt_y * 60), sf::Vector2f(100, 40), normalTexture));
					}
				}
			}
		}
	}
}

void Level::deleteDestroyedBricks()
{
	for (unsigned int j = 0; j < myBricks.size(); j++)
	{
		//detection of destroyed bricks
		if (myBricks[j]->isDestroyed(balls.getBalls(),myParticles))
		{
			myBricks.erase(myBricks.begin() + j);
		}
	}
}

void Level::drawComponents(sf::RenderWindow& window, sf::Vector2f& resolution)
{

	// show score
	score.draw(resolution, window);
	bar.draw(window);
	balls.draw(window);
	for (unsigned int j = 0; j < myBricks.size(); j++)
	{
		myBricks[j]->draw(window);
	}
	for (unsigned int i = 0; i < myParticles.size(); i++)
	{
		myParticles[i].draw(window);
	}
}

bool Level::isOver()
{
	unsigned int nbToDestroy=0;
	for (unsigned int i = 0; i < myBricks.size(); i++)
	{
		if (myBricks[i]->getHits() > 0)
		{
			nbToDestroy++;
		}
	}
	return nbToDestroy == 0;
}

void Level::finishLevel()
{
	levelFinished = true;
}

bool Level::isFinished()
{
	return levelFinished;
}

void Level::checkParticleStates()
{
	for (unsigned int i = 0; i < myParticles.size(); i++)
	{
		if (myParticles[i].isLost())
		{ 
			/* delete particles out of the screen*/
			myParticles.erase(myParticles.begin() + i);
		}
		else {
			if (myParticles[i].isColliding(bar))
			{
				myParticles[i].giveBonus(balls,bar,score);
				myParticles.erase(myParticles.begin() + i);
			}
		}
	}
}

