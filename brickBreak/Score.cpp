#include "Score.h"


Score::Score(int initial, int current)
{
	init = initial;
	score = current;
	font = new sf::Font;
	if (!(*font).loadFromFile("arial.ttf"))
	{
		std::puts("error loading font\n");
	}
}

int Score::initialize()
{

	unsigned int initial = 0;
	std::cout << "Please enter a valid number of HP:\n>";
	std::cin >> initial;
	std::cin.clear();
	init = initial;
	score = initial;
	return 1;
}

int Score::reduceScore()
{
	--score;
	return 1;
}

int Score::getScore()
{
	return score;
}

int Score::getInit()
{
	return init;
}

sf::Text Score::textScore(sf::Vector2f& resolution)
{
	sf::Text text;
	std::stringstream convert;
	convert << "HP: " << score;
	text.setFont(*font);
	text.setString(convert.str());
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
	return text;
}