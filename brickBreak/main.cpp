#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Brique.h"
#include "Ball.h"

sf::RectangleShape drawBrick(Brique brique)
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
	/*Size of the inside window*/
	sf::Vector2f resolution(1024, 768);
	std::vector<Ball> balls;
	std::vector<Brique> bricks;
	Bar bar(sf::Vector2f((resolution.x - 350) / 2, resolution.y - 35), sf::Vector2f(350, 35), sf::Color::Red);
	balls.push_back(Ball(sf::Vector2f(100, 100), 20, sf::Vector2f(1, 1)));
	balls.push_back(Ball(sf::Vector2f(200, 100), 20, sf::Vector2f(1, 1)));
	balls.push_back(Ball(sf::Vector2f(300, 100), 20, sf::Vector2f(1, 1)));
	balls.push_back(Ball(sf::Vector2f(400, 100), 20, sf::Vector2f(1, 1)));
	balls.push_back(Ball(sf::Vector2f(500, 100), 20, sf::Vector2f(1, 1)));
	balls.push_back(Ball(sf::Vector2f(600, 100), 20, sf::Vector2f(1, 1)));
	bricks.push_back(Brique(sf::Vector2f(resolution.x / 2, resolution.y / 2), sf::Vector2f(200, 100), sf::Color::Yellow));
	bricks.push_back(Brique(sf::Vector2f(150, resolution.y / 2), sf::Vector2f(200, 100), sf::Color::Yellow));
	bricks.push_back(Brique(sf::Vector2f(170, 115), sf::Vector2f(200, 100), sf::Color::Yellow));
	bricks.push_back(Brique(sf::Vector2f(resolution.x / 2, 100), sf::Vector2f(200, 100), sf::Color::Yellow));
	bricks.push_back(Brique(sf::Vector2f(800, 100), sf::Vector2f(200, 100), sf::Color::Yellow));
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
		for (int i = 0; i < balls.size(); i++)
		{
			window.draw(drawBall(balls[i]));
			for (int j = 0; j < bricks.size(); j++)
			{
				//detection of destroyed bricks
				if (bricks[j].isDestroyed() == false) {
					window.draw(drawBrick(bricks[j]));
					balls[i].isColliding(bricks[j]);
				}
			}
			balls[i].isColliding(bar);
			balls[i].move(resolution);
		}
		
		
		
		// end of the draw frame
		window.display();
		sf::sleep(sf::milliseconds(1));
	}

	return 0;
}