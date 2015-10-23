#ifndef DEF_SCORE
#define DEF_SCORE

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

class Score
{
public:
	Score(int, int);
	int initialize();
	int reduceScore();
	int getScore();
	int getInit();
	sf::Text textScore(sf::Vector2f&);

private:
	unsigned int init;
	unsigned int score;
	sf::Font* font;
};

#endif