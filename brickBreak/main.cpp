#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Brick.h"
#include "Ball.h"


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
	ballShape.setFillColor(sf::Color::Red);
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
	int cpt_h = 0, cpt_v = 0;
	/*Size of the inside window*/
	sf::Vector2f resolution(1024, 768);

	//creation of object vectors
	std::vector<Ball> myBalls;
	std::vector<Brick*> myBricks;
	int test[50] = { 0 };

	//creation of the bar
	Bar bar(sf::Vector2f((resolution.x - 350) / 2, resolution.y - 35), sf::Vector2f(350, 35), sf::Color::Red);

	//creation of the bricks
	for (cpt_v=0; cpt_v < 5; cpt_v++) {
		for (cpt_h=0; cpt_h < 6; cpt_h++) {
			myBricks.push_back(new ClassicBrick(sf::Vector2f(200 + 2*cpt_h * 60, 150 + cpt_v * 30), sf::Vector2f(50, 20), sf::Color::Yellow));
			if (cpt_h < 5) {
				if (cpt_v == 0 || cpt_v == 2 || cpt_v == 4) {
					myBricks.push_back(new StrongBrick(sf::Vector2f(200 + (2 * cpt_h + 1) * 60, 150 + cpt_v * 30), sf::Vector2f(50, 20), sf::Color::Yellow, 3));
				}
				else {
					myBricks.push_back(new BallBrick(sf::Vector2f(200 + (2 * cpt_h + 1) * 60, 150 + cpt_v * 30), sf::Vector2f(50, 20), sf::Color::Yellow, myBalls));
				}
			}
		}
	}

	//creation of the ball
	myBalls.push_back(Ball(sf::Vector2f(100, 100), 10, sf::Vector2f(1,1)));

	//creation of the window
	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "My window");

	// program is running until window is closed
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// enable window closing
			if (event.type == sf::Event::Closed || 
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();

			// capture mouse movement
			if (event.type == sf::Event::MouseMoved)
			{
				bar.setPosx(event.mouseMove.x - bar.getDim().x / 2);
			}
		}

		// keyboard direction action
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bar.setPosx(bar.getPos().x - 4);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bar.setPosx(bar.getPos().x + 4);
		}

		//check bar position
		bar.isInsideScreen(resolution);

		// color window in black
		window.clear(sf::Color::Black);

		// draw bar
		window.draw(drawBar(bar));		

		// draw frame
		for (int i = 0; i < myBalls.size(); i++)
		{
			//draw the balls
			window.draw(drawBall(myBalls[i]));
			for (int j = 0; j < myBricks.size(); j++)
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
			//balls movement
			myBalls[i].isColliding(bar);
			myBalls[i].move(resolution);
		}
				
		// end of the draw frame
		window.display();
		sf::sleep(sf::milliseconds(1));
	}

	return 0;
}