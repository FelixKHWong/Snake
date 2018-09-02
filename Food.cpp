#include "Food.h"
#include <chrono>
#include <iostream>

using namespace std;
Food::Food()
{
	touch = false;																					// allow touch to determine contact
}
		
void Food::spawn(int plane[15][45]){																// random generation for  fruit placement
	srand(time(NULL));																				// initiate clock for random num gen
	rspy = rand() % 13 + 1;																	
	rspx = rand() % 40 + 1;
	plane[rspy][rspx] = 0;																			// removes fruit from plane
}

