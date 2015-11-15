#ifndef DEF_MENU
#define DEF_MENU
#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu();
	void forward(sf::RenderWindow&);
	void draw(sf::RenderWindow&, sf::Vector2f&);
	bool isChoiceMade();
	unsigned int getSelectedItem();
private:
	std::vector<std::string> items;
	unsigned int selectedItem =0;
	std::string title="Awesome brick breaker!";
	sf::Font* font;
	unsigned int loop = 0;
	bool choiceMade = false;
};

#endif
