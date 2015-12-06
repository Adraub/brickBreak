#ifndef DEF_BAR
#define DEF_BAR

#include <SFML/Graphics.hpp>

/*Moving bar commanded with mouse/keyboard that repels the balls on collision, and capture particles*/

class Bar {
public:
	Bar();
	Bar(sf::Vector2f, sf::Vector2f, sf::Color, bool);

	void isInsideScreen(sf::Vector2f&);
	void draw(sf::RenderWindow&);
	void addBall();
	void launchedBall();
	bool isBall() const;
	int Bar::upCollision(sf::Vector2f&, sf::Vector2f&);
	void setColor(sf::Color);
	void setPosx(float);
	void setDim(sf::Vector2f);
	sf::Color getColor() const;
	sf::Vector2f getDim() const;
	sf::Vector2f getPos() const;
	double getTanBar() const;

private:
	sf::Vector2f pos; /*position of its up middle*/
	sf::Vector2f dim; /*dimensions*/
	sf::Color color;
	bool ball; /*has a ball ready to be launched*/

};

#endif