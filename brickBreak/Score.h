#ifndef DEF_SCORE
#define DEF_SCORE

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

class Score
{
public:
	Score();
	Score(int);
	int initialize();
	int reduceScore();
	int increaseScore();
	int getScore();
	void draw(sf::Vector2f&, sf::RenderWindow&);

private:
	unsigned int init;
	unsigned int score;
	sf::Font* font;
};

#endif