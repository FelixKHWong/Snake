#include "Snek.h"
#include <iostream>
#include "Food.h"

using namespace std;

Snek::Snek(int plane[15][45], int a, int b)																	// initiate snake in space									
{	
	dirx = a;
	diry = b;
	plane[diry][dirx] = 1;
	alive = true;
	size = 2;
}

int Snek::moveSK(int plane[15][45], char direction, Food *Froot){											// movement and collisin detection of snake
	switch(direction){																						// takes inputted direction, allows snake to continue in direction
		case 'a' : dirx--;
				   break;
		case 'd' : dirx++;
				   break;
		case 'w' : diry--;
				   break;
		case 's' : diry++;
				   break;
	}	
	if ((diry > 14)||(diry < 0)||(dirx < 0)||(dirx > 44)){													// detects if snake exits plane
		alive = false;
	}	
	else if(plane[diry][dirx] == 0){																		// detect froot collision
		size++;
		Froot->touch = true;
	}	
	else if(plane[diry][dirx] > 2){																			// detect collision with self
		alive = false;
	}
	plane[diry][dirx]= 1;																					// sets spot snake moves to to 1
	for (int j = 0; j < 15; j++){																			// for all spots in plane...
		for (int i = 0; i < 45; i++){
			if (plane[j][i] >= 1){																			// add one to all integers that represent snake
				plane[j][i]++;																				// this allows restriction of snake length in the plane
			}
			if (plane[j][i] > size){																		// if spot has a value greater than size of snake, set spot to a blank space
				plane[j][i] = -1;
			}
		}
	}
}
