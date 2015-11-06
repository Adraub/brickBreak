#include <SFML/Graphics.hpp>
#include <iostream>
#include "bar.h"
#include "Ball.h"
#include "Brick.h"
#include "Score.h"
#include "BallsHandler.h"






int main()
{
	// Initialisation du score
	Score score(0, 0);
	score.initialize();
	
	sf::Texture texture;
	texture.loadFromFile("wallpaper.jpg");

	float cpt_h = 0, cpt_v = 0;
	
	/*Size of the space used to draw*/
	sf::Vector2f resolution(1920,1080);
	/*Bricks array*/
	std::vector<Brick*> myBricks;
	
	/*keyboard sensibility*/
	int keyboardSensibility(10);
	/*time between each graphical loop*/
	sf::Time loopTime = sf::microseconds(16666);
	BallsHandler balls;
	//creation of the ball
	balls.newBall(sf::Vector2f(100, 100), 10, sf::Color::Red);
	Bar bar(sf::Vector2f((resolution.x - 350) / 2, resolution.y - 35), sf::Vector2f(350, 35), sf::Color::Red);
	sf::RenderWindow window(sf::VideoMode((unsigned int)resolution.x, (unsigned int)resolution.y), "Awesome brick breaker", sf::Style::Fullscreen);
	//creation of the bricks
	for (cpt_v=0; cpt_v < 5; cpt_v++) {
		for (cpt_h=0; cpt_h < 6; cpt_h++) {
			myBricks.push_back(new ClassicBrick(sf::Vector2f(300 + 2*cpt_h * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow));
			if (cpt_h < 5) {
				if (cpt_v == 0 || cpt_v == 2 || cpt_v == 4) {
					myBricks.push_back(new StrongBrick(sf::Vector2f(300 + (2 * cpt_h + 1) * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow, 3));
				}else {
					myBricks.push_back(new BallBrick(sf::Vector2f(300 + (2 * cpt_h + 1) * 120, 200 + cpt_v * 60), sf::Vector2f(100, 40), sf::Color::Yellow, balls.getBalls()));
				}
			}
		}
	}
	float ratio = 0.95f;
	//fit window to user screen
	if (sf::VideoMode::getDesktopMode().width == 1920)
	{
		ratio = 0.955f;
	}
	window.setSize(sf::Vector2u(sf::VideoMode::getDesktopMode().width, (unsigned int)(sf::VideoMode::getDesktopMode().height*ratio)));

	
	
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
		if (balls.aliveBalls()==0)
		{
			score.reduceScore();
			if (score.getScore() < 0)
			{
				window.close();
			}
			balls.newBall(sf::Vector2f(100, 100), 10, sf::Color::Yellow);
			balls.newBall(sf::Vector2f(250, 150), 20, sf::Color::Red);
			balls.newBall(sf::Vector2f(300, 100), 30, sf::Color::Green);
			balls.newBall(sf::Vector2f(400, 100), 40, sf::Color::Magenta);
			balls.newBall(sf::Vector2f(500, 100), 25, sf::Color::Blue);
			balls.newBall(sf::Vector2f(600, 100), 15, sf::Color::Cyan);
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
		window.clear();

		//Draw background wallpaper
		sf::Vector2f size = sf::Vector2f(1920, (float)(1920*texture.getSize().y/ texture.getSize().x));
		sf::RectangleShape wallpaper(size);
		wallpaper.setTexture(&texture);
		wallpaper.setOutlineThickness(50);
		wallpaper.setOutlineColor(sf::Color(44, 135, 190));
		window.draw(wallpaper);
		
		
		balls.move(resolution, bar, myBricks);

		// draw frame
		
		for (unsigned int j = 0; j < myBricks.size(); j++)
		{
			//draw the balls
			myBricks[j]->draw(window);
		
			//detection of destroyed bricks
			if (myBricks[j]->isDestroyed() == true) 
			{
				myBricks.erase(myBricks.begin()+j);
			}
		}

		// draw bar
		bar.draw(window);
		balls.draw(window);

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