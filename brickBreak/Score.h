#ifndef DEF_SCORE
#define DEF_SCORE

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>


/*Handles users remaining lives*/


class Score
{
public:
	Score();
	Score(int);
	int initialize();
	int reduceLives();
	int addLife();
	int getLives();
	void draw(sf::Vector2f&, sf::RenderWindow&);

private:
	unsigned int lives; /*current remaining lives*/
	sf::Font* font;
};

#endif