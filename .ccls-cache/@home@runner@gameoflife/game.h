#ifndef GAME_H
#define GAME_H

#include "life.h"
#include "world.h"

class Game {
public:
	// Constructor/destructor
	Game(Life** life, int numLife);
	~Game();

	void play();
private:
	World* m_world;
	int m_steps;
	bool m_automate;
};

#endif