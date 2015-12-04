#include "Score.h"

Score::Score()
{

}

Score::Score(int current)
{
	score = current;
	font = new sf::Font;
	if (!(*font).loadFromFile("arial.ttf"))
	{
		std::puts("error loading font\n");
	}
}

int Score::initialize()
{
	unsigned int initial = 3;
	score = initial;
	return 1;
}

int Score::reduceScore()
{
	--score;
	return score;
}

int Score::increaseScore()
{
	++score;
	return score;
}

int Score::getScore()
{
	return score;
}


void Score::draw(sf::Vector2f& resolution, sf::RenderWindow& window)
{
	sf::Text text;
	std::stringstream convert;
	convert << "Lives: " << score;
	text.setFont(*font);
	text.setString(convert.str());
	text.setCharacterSize(36);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	text.setPosition(resolution-sf::Vector2f(150, resolution.y+5));
	window.draw(text);
}