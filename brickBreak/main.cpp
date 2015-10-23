#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Score.h"

sf::RectangleShape drawBrick(Brick brique)
{
	sf::RectangleShape brick(brique.getDim());
	brick.setPosition(brique.getPos());
	brick.setFillColor(brique.getColor());
	return brick;
}

sf::CircleShape drawBall(Ball ball)
{
	sf::CircleShape ballShape(ball.getRadius());
	ballShape.setPosition(ball.getPosition());
	ballShape.setFillColor(ball.getColor());
	return ballShape;
}

sf::RectangleShape drawBar(Bar bar)
{
	sf::RectangleShape barShape(bar.getDim());
	barShape.setPosition(bar.getPos());
	barShape.setFillColor(bar.getColor());
	return barShape;
}


int main()
{
	// Initialisation du score
	Score score(0, 0);
	score.initialize();
	
	float cpt_h = 0, cpt_v = 0;
	
	/*Size of the space used to draw*/
	sf::Vector2f resolution(1920, 1080);
	/*Balls array*/
	std::vector<Ball> myBalls;
	/*Bricks array*/
	std::vector<Brick*> myBricks;
	int test[50] = { 0 };
	/*default ball speed*/
	sf::Vector2f standardBallSpeed(5, 5);
	/*keyboard sensibility*/
	int keyboardSensibility(10);
	/*time between each graphical loop*/
	sf::Time loopTime = sf::microseconds(16666);

	Bar bar(sf::Vector2f((resolution.x - 350) / 2, resolution.y - 35), sf::Vector2f(350, 35), sf::Color::Red);
	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Awesome brick breaker", sf::Style::Fullscreen);
	//creation of the bricks
	for (cpt_v=0; cpt_v < 5; cpt_v++) {
		for (cpt_h=0; cpt_h < 6; cpt_h++) {
			myBricks.push_back(new ClassicBrick(sf::Vector2f(300 + 2*cpt_h * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow));
			if (cpt_h < 5) {
				if (cpt_v == 0 || cpt_v == 2 || cpt_v == 4) {
					myBricks.push_back(new StrongBrick(sf::Vector2f(300 + (2 * cpt_h + 1) * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow, 3));
				}
				else {
					//myBricks.push_back(new BallBrick(sf::Vector2f(200 + (2 * cpt_h + 1) * 60, 150 + cpt_v * 30), sf::Vector2f(50, 20), sf::Color::Yellow, myBalls));
				}
			}
		}
	}
	
	//creation of the ball
	myBalls.push_back(Ball(sf::Vector2f(100, 100), 10, sf::Vector2f(10,10), sf::Color::Red));
	
	//force rendering to screen framerate
	window.setVerticalSyncEnabled(true);
	//hide the mouse
	window.setMouseCursorVisible(false);

	// program is running until window is closed
	while (window.isOpen())
	{
		//launch timer / needs to be at the beginning of the loop!!
		sf::Clock clock;

		// test null score
		if (score.getScore() == 0)
		{
			window.close();
		}

		// test to reduce score 
		if (myBalls.empty())
		{
			score.reduceScore();
			if (score.getScore() < 0)
			{
				window.close();
			}
			myBalls.push_back(Ball(sf::Vector2f(100, 100), 10, standardBallSpeed, sf::Color::Yellow));
			myBalls.push_back(Ball(sf::Vector2f(250, 150), 20, standardBallSpeed, sf::Color::Red));
			myBalls.push_back(Ball(sf::Vector2f(300, 100), 30, standardBallSpeed, sf::Color::Green));
			myBalls.push_back(Ball(sf::Vector2f(400, 100), 40, standardBallSpeed, sf::Color::Magenta));
			myBalls.push_back(Ball(sf::Vector2f(500, 100), 25, standardBallSpeed, sf::Color::Blue));
			myBalls.push_back(Ball(sf::Vector2f(600, 100), 15, standardBallSpeed, sf::Color::Cyan));
		}

		

		sf::Event event;
		while (window.pollEvent(event))
		{
			// enable window closing
			if (event.type == sf::Event::Closed || 
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
			// capture mouse movement
			else if (event.type == sf::Event::MouseMoved)
			{
				//Convert window size to world size
				sf::Vector2f mouse=window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y), window.getView());
				bar.setPosx(mouse.x - bar.getDim().x / 2);
			}
			else if (event.type == sf::Event::Resized)
			{
				sf::View view(sf::FloatRect(-(event.size.width - resolution.x) / 2.0f, -(event.size.height - resolution.y) / 2.0f
					, (float)event.size.width, (float)event.size.height));
				float zoom = std::max(resolution.x/ event.size.width, resolution.y/ event.size.height);
				view.zoom(zoom);
				window.setView(view);
			}
		}

		// keyboard direction action
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bar.setPosx(bar.getPos().x - keyboardSensibility);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bar.setPosx(bar.getPos().x + keyboardSensibility);
		}

		//check bar position
		bar.isInsideScreen(resolution);

		// color window in black
		window.clear(sf::Color::Black);
	

		// draw frame
		for (unsigned int i = 0; i < myBalls.size(); i++)
		{
			//draw the balls
			window.draw(drawBall(myBalls[i]));
			for (unsigned int j = 0; j < myBricks.size(); j++)
			{
				//draw the balls
				myBricks[j]->draw(window);

				//detection of collisions
				myBalls[i].isColliding(*myBricks[j]);

				//detection of destroyed bricks
				if (myBricks[j]->isDestroyed() == true) {
					myBricks.erase(myBricks.begin()+j);
				}
			}
			for (unsigned int k = 1; i+k < myBalls.size(); k++)
			{
				myBalls[i].isColliding(myBalls[k+i]);
			}
			myBalls[i].isColliding(bar);
			myBalls[i].move(resolution);
			if (!myBalls[i].isInsideScreen(resolution))
			{
				myBalls.erase(myBalls.begin() + i);
			}
		}

		// draw bar
		window.draw(drawBar(bar));

		// show score
		window.draw(score.textScore(resolution));		
		
		// end of the draw frame
		window.display();
		sf::Time elapsed = clock.getElapsedTime();
		//framerate 60 hertz
		if (elapsed.asMicroseconds() < loopTime.asMicroseconds())
		{
			sf::sleep(loopTime - elapsed);
		}

	}

	return 0;
}