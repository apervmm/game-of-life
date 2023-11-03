#include <iostream>

#include "world.h"
#include "globals.h"
#include "utils.h"

using std::cout;
using std::endl;





World::World() :
	m_toggle(true)
{
	m_world = new char* [MAX_ROWS];
	m_otherWorld = new char* [MAX_ROWS];
	for (unsigned char i = 0; i < MAX_ROWS; i++) {
		m_world[i] = new char[MAX_COLS];
		m_otherWorld[i] = new char[MAX_COLS];
	}

	for (unsigned char i = 0; i < MAX_ROWS; i++) {
		for (unsigned char j = 0; j < MAX_COLS; j++) {
			m_world[i][j] = DEAD;
		}
	}

}

World::~World() {
	for (unsigned char i = 0; i < MAX_ROWS; i++) {
		delete[] m_world[i];
		delete[] m_otherWorld[i];
	}
	delete[] m_world;
	delete[] m_otherWorld;

}

void World::print() const {
	clearScreen();
	if (m_toggle) {
		for (unsigned char i = 0; i < MAX_ROWS; i++) {
			for (unsigned char j = 0; j < MAX_COLS; j++) {
				std::cout << m_world[i][j];
			}
			std::cout << std::endl;
		}
	}
	else {
		for (unsigned char i = 0; i < MAX_ROWS; i++) {
			for (unsigned char j = 0; j < MAX_COLS; j++) {
				std::cout << m_otherWorld[i][j];
			}
			std::cout << std::endl;
		}
	}
	for (char i = 0; i < MAX_COLS; i++) {
		std::cout << '=';
	}
	std::cout << std::endl;
}
bool World::hasWorldChanged() const {

	for (unsigned char i = 0; i < MAX_ROWS; i++) {
		for (unsigned char j = 0; j < MAX_COLS; j++) {

			if (m_otherWorld[i][j] != m_world[i][j]) {
				return true;
			}

		}
	}
	return false;
}
void World::updateWorld() {
	if (m_toggle) {
		for (unsigned char i = 0; i < MAX_ROWS; i++) {
			for (unsigned char j = 0; j < MAX_COLS; j++) {
				m_otherWorld[i][j] =
					getNextState(m_world[i][j], i, j, m_toggle);
			}
		}
		m_toggle = !m_toggle;
	}
	else {
		for (unsigned char i = 0; i < MAX_ROWS; i++) {
			for (unsigned char j = 0; j < MAX_COLS; j++) {
				m_world[i][j] =
					getNextState(m_otherWorld[i][j], i, j, m_toggle);
			}
		}
		m_toggle = !m_toggle;
	}
}

char World::getNextState(char state, char row, char col, bool toggle) const {
	int yCoord = row;
	int xCoord = col;
  int Label = -1;
	char neighbors = 0;
	if (toggle) {
		for (unsigned char i = yCoord - 1; i <= yCoord + 1; i++) {
			for (unsigned char j = xCoord - 1; j <= xCoord + 1; j++) {
				if (i == yCoord && j == xCoord) {
					continue;
				}
				if (i > Label && i < MAX_ROWS && j > Label && j < MAX_COLS) {
					if (m_world[i][j] == ALIVE) {
						neighbors++;
					}
				}
			}
		}
	}
	else {
		for (unsigned char i = yCoord - 1; i <= yCoord + 1; i++) {
			for (unsigned char j = xCoord - 1; j <= xCoord + 1; j++) {
				if (i == yCoord && j == xCoord) {
					continue;
				}
				if (i > Label && i < MAX_ROWS && j > Label && j < MAX_COLS) {
					if (m_otherWorld[i][j] == ALIVE) {
						neighbors++;
					}
				}
			}
		}
	}
	if (state == ALIVE) {
		return (neighbors > 1 && neighbors < 4) ? ALIVE : DEAD;
	}
	else {
		return (neighbors == 3) ? ALIVE : DEAD;
	}
}

bool World::initLife(Life* life) {

	if (life == nullptr) {
		cout << "Cannot add nullptr life" << endl;
		return false;
	}

	// Should check life extents with world bounds.

	for (unsigned char i = life->getRow(); i - life->getRow() < life->getHeight(); i++) {
		for (unsigned char j = life->getCol(); j - life->getCol() < life->getWidth(); j++) {
			if (i < MAX_ROWS && j < MAX_COLS) {
				m_world[i][j] =
					life->getFromFigure(i - life->getRow(), j - life->getCol());
			}
		}
	}
	return true;
}