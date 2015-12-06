#include "Score.h"

Score::Score()
{

}

Score::Score(int current)
{
	lives = current;
	font = new sf::Font;
	if (!(*font).loadFromFile("arial.ttf"))
	{
		std::puts("error loading font\n");
	}
}

int Score::initialize()
{
	unsigned int initial = 3;
	lives = initial;
	return 1;
}

int Score::reduceLives()
{
	--lives;
	return lives;
}

int Score::addLife()
{
	++lives;
	return lives;
}

int Score::getLives()
{
	return lives;
}


void Score::draw(sf::Vector2f& resolution, sf::RenderWindow& window)
{
	/*draw remaining lives on the screen*/
	sf::Text text;
	std::stringstream convert;
	convert << "Lives: " << lives;
	text.setFont(*font);
	text.setString(convert.str());
	text.setCharacterSize(36);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	text.setPosition(resolution-sf::Vector2f(150, resolution.y+5));
	window.draw(text);
}