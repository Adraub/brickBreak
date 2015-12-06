#ifndef DEF_MENU
#define DEF_MENU
#include <SFML/Graphics.hpp>

/*Allow user to select the level he wants to play*/

class Menu
{
public:
	Menu();
	void forward(sf::RenderWindow&);
	void draw(sf::RenderWindow&, sf::Vector2f&);
	bool isChoiceMade();
	void setNewLevel();
	unsigned int getSelectedItem() const;
private:
	std::vector<std::string> items; /*Level names array*/
	unsigned int selectedItem =0;
	std::string title="Awesome brick breaker!"; /*Game title*/
	sf::Font* font; /*used font*/
	unsigned int loop = 0; /*regulates keyboard sensibility*/
	bool choiceMade = false;
};

#endif
