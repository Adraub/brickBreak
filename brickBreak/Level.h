#ifndef DEF_LEVEL
#define DEF_LEVEL
#include "BallsHandler.h"
#include "Score.h"
#include "StrongBrick.h"
#include "BallBrick.h"
#include "Menu.h"
#include "Particle.h"

/*Class that handles every stuff related to a particular level during the game. Created and destroyed for each level*/

class Level
{
public:
	Level(sf::Vector2f, int, Score&);

	void forward(sf::Vector2f,sf::RenderWindow&, Menu&);
	void createBricks(int level);
	void deleteDestroyedBricks();
	void drawComponents(sf::RenderWindow&, sf::Vector2f&);
	void checkParticleStates();
	void finishLevel();
	bool isFinished();
	bool isOver();
	void setBarPosition(float);
	float getBarPosition() const;

private:
	// Bricks array
	std::vector<Brick*> myBricks; /*bricks array*/
	BallsHandler balls= BallsHandler(); /*Balls array with behaviour simplified*/
	std::vector<Particle> myParticles; /*particles array*/
	Bar bar;
	Score score; /*user current lives*/
	int keyboardSensibility=20; /* regulates bar moving speed using keyboard */
	bool levelFinished; /* Level status */
};

#endif
