#include "Menu.h"
#include <sstream>

Menu::Menu()
{
	font = new sf::Font;
	if (!(*font).loadFromFile("arial.ttf"))
	{
		std::puts("error loading font\n");
	}
	items.push_back("Level 1");
	items.push_back("Level 2");
	items.push_back("Level 3");
	items.push_back("Quit");
}

void Menu::forward(sf::RenderWindow& window)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (loop > 3)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				selectedItem = (selectedItem != 0) ? selectedItem - 1 : selectedItem;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				selectedItem = (selectedItem != items.size() - 1) ? selectedItem + 1 : selectedItem;
			}
			loop = 0;
		}else {
			loop++;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		choiceMade = true;
	}
	
}

void Menu::draw(sf::RenderWindow& window, sf::Vector2f& resolution)
{
	if (!choiceMade)
	{
		forward(window);
	}
	
	sf::Text text;
	std::stringstream convert;
	convert << title;
	text.setFont(*font);
	text.setString(convert.str());
	text.setCharacterSize(60);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(resolution.x / 2, resolution.y / 2 - 400));
	window.draw(text);

	for (unsigned int i = 0; i < items.size(); i++)
	{
		sf::Text text;
		std::stringstream convert;
		convert << items[i];
		text.setFont(*font);
		text.setString(convert.str());
		text.setCharacterSize(38);
		text.setStyle(sf::Text::Bold);
		text.setColor((i==selectedItem)? sf::Color::Red : sf::Color::White);
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		text.setPosition(sf::Vector2f(resolution.x / 2, resolution.y / 2-200+150*i));
		window.draw(text);
	}
	
}

bool Menu::isChoiceMade()
{
	return choiceMade;
}

unsigned int Menu::getSelectedItem()
{
	return selectedItem;
}

void Menu::setNewLevel()
{
	choiceMade = false;
}
