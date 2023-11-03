#include "toad.h"
#include "globals.h"

Toad::Toad(int r, int c) {

	m_col = c;
	m_row = r;
	m_height = TOAD_HEIGHT;
	m_width = TOAD_WIDTH;

	//Allocate space for figure
	m_figure = new char* [TOAD_HEIGHT];
	for (int i = 0; i < TOAD_HEIGHT; i++) {
		m_figure[i] = new char[TOAD_WIDTH];
	}

	//Initialize figure
	for (int i = 0; i < TOAD_HEIGHT; i++) {
		for (int j = 0; j < TOAD_WIDTH; j++) {
			m_figure[i][j] = ALIVE;
		}
	}

	m_figure[0][3] = DEAD;
	m_figure[1][0] = DEAD;
}

Toad::~Toad() {
	for (int i = 0; i < TOAD_HEIGHT; i++) {
		delete[] m_figure[i];
	}
	delete[] m_figure;
}