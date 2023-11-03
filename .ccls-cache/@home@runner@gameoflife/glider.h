#ifndef GLIDER_H
#define GLIDER_H

#include "life.h"

class Glider : public Life {
public:
	// Constructor/destructor
	Glider(int r, int c);
	~Glider();
};

#endif