#ifndef SNEK_H
#define SNEK_H
#include "Food.h"

class Snek
{	private:
		int dirx;																	// left or right direction
		int diry;																	// up or down direction
	public:			
		int size;																	// length of snake+1
		bool alive;																	// has snake collided
		Snek(int plane[15][45], int,int);											// initializes snake
		int moveSK(int plane[15][45], char, Food *Froot);							// allows movement, collision detection
};

#endif
