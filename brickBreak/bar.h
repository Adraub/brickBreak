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
	int setDim(sf::Vector2f);
	void draw(sf::RenderWindow&);
	void addBall();
	void launchedBall();
	bool isBall();
	int Bar::upCollision(sf::Vector2f&, sf::Vector2f&);

private:
	sf::Vector2f pos;
	sf::Vector2f dim;
	sf::Color color;
	bool ball;

};

#endif