#include <SFML/Graphics.hpp>
#include "bar.h"
#include "Ball.h"
#include "Brick.h"
#include "Score.h"
#include "Level.h"
#include "BallsHandler.h"
#include "Menu.h"






int main()
{
	Score score(0, 0);
	score.initialize();
	
	sf::Texture texture;
	texture.loadFromFile("wallpaper.jpg");

	/*Size of the space used to draw*/
	sf::Vector2f resolution(1920,1080);
	
	/*handle windows task bar*/
	float ratio;
	if (sf::VideoMode::getDesktopMode().width == 1920)
	{
		ratio = 0.955f;
	}
	else {
		ratio = 0.95f;
	}
	sf::RenderWindow window(sf::VideoMode((unsigned int)resolution.x, (unsigned int)resolution.y), "Awesome brick breaker", sf::Style::Fullscreen);
	window.setSize(sf::Vector2u(sf::VideoMode::getDesktopMode().width, (unsigned int)(sf::VideoMode::getDesktopMode().height*ratio)));
	//force rendering to screen framerate
	window.setVerticalSyncEnabled(true);
	//hide the mouse
	window.setMouseCursorVisible(false);
	Menu menu;

	Level level(resolution, 2);
	/*time between each graphical loop*/
	sf::Time loopTime = sf::microseconds(16666);
	/*Graphical loop*/
	while (window.isOpen())
	{
		//launch timer / needs to be at the beginning of the loop!!
		sf::Clock clock;


		sf::Event event;
		while (window.pollEvent(event))
		{
			// enable window closing
			if (event.type == sf::Event::Closed || 
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
			// capture mouse movement
			else if (event.type == sf::Event::MouseMoved && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
				&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				//Convert window size to world size
				sf::Vector2f mouse=window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y), window.getView());
				level.setBarPosition(mouse.x);
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


		//Draw background wallpaper
		sf::Vector2f size = sf::Vector2f(1920, (float)(1920*texture.getSize().y/ texture.getSize().x));
		sf::RectangleShape wallpaper(size);
		wallpaper.setTexture(&texture);
		wallpaper.setOutlineThickness(45);
		wallpaper.setOutlineColor(sf::Color(44, 135, 190));
		window.draw(wallpaper);

		/*Select level and then play!*/
		if (!menu.isChoiceMade())
		{
			menu.draw(window, resolution);
			if (menu.isChoiceMade())
			{
				level= Level (resolution, menu.getSelectedItem());
			}
		}
		else {
			level.forward(resolution, window, score);
		}

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