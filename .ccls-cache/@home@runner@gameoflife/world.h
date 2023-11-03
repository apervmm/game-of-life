#ifndef WORLD_H
#define WORLD_H

#include "life.h"

class World {
public:
	// Constructor/destructor
	World();
	~World();

	void print() const;
	bool hasWorldChanged() const;

	bool initLife(Life* life);
	void updateWorld();
private:

	char getNextState(char state, char row, char col, bool toggle) const;

	// The rules of Conway's Game of Life requires each cell to
	// examine it's neighbors.  So, we have to check the entire world
	// first before we change it.  We can use two copies of the world, 
	// one to check the current state (current day) then another to generate 
	// the next state(for the next day). We can toggle between them each 
	// step, to avoid having to copy between worlds each step (day) of the game.
	char** m_world;
	char** m_otherWorld;
	bool m_toggle;


};

#endif