#ifndef DEF_BAR
#define DEF_BAR

#include <SFML/Graphics.hpp>

class Bar {
public:
	Bar(sf::Vector2f, sf::Vector2f, sf::Color);
	int isInsideScreen(sf::Vector2f&);
	sf::Vector2f getDim() const;
	sf::Vector2f getPos();
	sf::Color getColor();
	double getTanBar();
	int setPosx(float);
	void draw(sf::RenderWindow&);

private:
	sf::Vector2f pos;
	sf::Vector2f dim;
	sf::Color color;
	double tanBar;

};

#endif