#ifndef DEF_BAR
#define DEF_BAR

#include <SFML/Graphics.hpp>

class Bar {
public:
	Bar();
	Bar(sf::Vector2f, sf::Vector2f, sf::Color, bool);
	int isInsideScreen(sf::Vector2f&);
	sf::Vector2f getDim() const;
	sf::Vector2f getPos() const;
	double getTanBar() const;
	int setPosx(float);
	int setPosy(float);
	void draw(sf::RenderWindow&);
	void addBall();
	void launchedBall();
	bool isBall();
	int Bar::upCollision(sf::Vector2f&, sf::Vector2f&);
	std::vector<int> getPosArray();
	int posArrayPushBack(int); 
private:
	sf::Vector2f pos;
	sf::Vector2f dim;
	sf::Color color;
	bool ball;
	std::vector<int> posArray; // posArray stores a value at every loop of the main graphical loop. It stores 1 if the bar is below Oy (because player pressed V) and 0 otherwise
};

#endif