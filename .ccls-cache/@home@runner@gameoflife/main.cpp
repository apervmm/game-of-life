#include "life.h"
#include "glider.h"
#include "toad.h"
#include "game.h"
#include "utils.h"

int main() {

	Life** population = new Life * [2];

	//population[0] = new Toad(4, 5); //toad alone
	//int numLife = 1;

	//population[0] = new Glider(0,0); //glider alone
	//int numLife = 1;


	population[0] = new Glider(0, 0); // Toad and Glider
	population[1] = new Toad(4, 5);
	int numLife = 2;

	// Create the game
	Game g(population, numLife);

	// Run the game
	g.play();

	// Report
	report();

	// Clean up
	delete population[0];
	delete population[1];
	delete[] population;

}