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
	/*Size of the inside window*/
	sf::Vector2f resolution(1024, 768);
	std::vector<Ball> balls;
	std::vector<Brique> bricks;
	sf::Vector2f standardBallSpeed(5, 5);
	int keyboardSensibility(10);
	sf::Time loopTime = sf::microseconds(16666);
	Bar bar(sf::Vector2f((resolution.x - 350) / 2, resolution.y - 35), sf::Vector2f(350, 35), sf::Color::Red);
	balls.push_back(Ball(sf::Vector2f(100, 100), 20, standardBallSpeed, sf::Color::Yellow));
	balls.push_back(Ball(sf::Vector2f(200, 100), 20, standardBallSpeed, sf::Color::Red));
	balls.push_back(Ball(sf::Vector2f(300, 100), 20, standardBallSpeed, sf::Color::Green));
	balls.push_back(Ball(sf::Vector2f(400, 100), 20, standardBallSpeed, sf::Color::Magenta));
	balls.push_back(Ball(sf::Vector2f(500, 100), 20, standardBallSpeed, sf::Color::Blue));
	balls.push_back(Ball(sf::Vector2f(600, 100), 20, standardBallSpeed, sf::Color::Cyan));
	bricks.push_back(Brique(sf::Vector2f(resolution.x / 2, resolution.y / 2), sf::Vector2f(200, 100), sf::Color::Yellow));
	bricks.push_back(Brique(sf::Vector2f(150, resolution.y / 2), sf::Vector2f(200, 100), sf::Color::Yellow));
	bricks.push_back(Brique(sf::Vector2f(170, 115), sf::Vector2f(200, 100), sf::Color::Yellow));
	bricks.push_back(Brique(sf::Vector2f(resolution.x / 2, 100), sf::Vector2f(200, 100), sf::Color::Yellow));
	bricks.push_back(Brique(sf::Vector2f(800, 100), sf::Vector2f(200, 100), sf::Color::Yellow));
	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Awesome brick breaker", sf::Style::Close);
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// program is running until window is closed
	while (window.isOpen())
	{
		//launch timer
		sf::Clock clock;

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
		for (int i = 0; i < balls.size(); i++)
		{
			window.draw(drawBall(balls[i]));
			for (int j = 0; j < bricks.size(); j++)
			{
				window.draw(drawBrick(bricks[j]));
				balls[i].isColliding(bricks[j]);
			}
			for (int k = 1; i+k < balls.size(); k++)
			{
				balls[i].isColliding(balls[k+i]);
			}
			balls[i].isColliding(bar);
			balls[i].move(resolution);
		}

		// draw bar
		window.draw(drawBar(bar));
		
		
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