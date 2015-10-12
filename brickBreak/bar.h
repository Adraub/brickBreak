#ifndef DEF_BAR
#define DEF_BAR

#include <SFML/Graphics.hpp>

class Bar {
public:

	Bar(sf::Vector2f, sf::Vector2f, sf::Color);
	~Bar();
	sf::Vector2f getDim();
	sf::Vector2f getPos();

private:

	sf::Vector2f pos;
	sf::Vector2f dim;
	sf::Color color;

};

#endif