#ifndef LIFE_H
#define LIFE_H


class World;

class Life {
public:

	int getCol() const; // const member functions cannot modify member variables.
	int getRow() const;
	int getHeight() const;
	int getWidth() const;
	char getFromFigure(int r, int c) const;

protected:
	int m_col;
	int m_row;
	int m_height;
	int m_width;
	char** m_figure;
	World* m_world;
};


#endif 