#ifndef GLOBALS_H
#define GLOBALS_H

const int MAX_ROWS = 11;
const int MAX_COLS = 11;

const int TOAD_HEIGHT = 2;
const int TOAD_WIDTH = 4;

const int GLIDER_SIZE = 3;

const int MAX_STEPS = 50;

const char ALIVE = 'X';
const char DEAD = '.';

void clearScreen();
void delay(int ms);
void report();

#endif 
