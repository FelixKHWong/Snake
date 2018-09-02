#ifndef FOOD_H
#define FOOD_H

class Food
{		
		int rspx = 0;																	// x coordinate of fruit
		int rspy = 0;																	// y coordinate of fruit
	public:
		bool touch;																		// contact between fruit or snake?
		void gone(int plane[15][45]);													// removes fruit when contact made
		void spawn(int plane[15][45]);													// spawns fruit
		Food();																			// initiates fruit 
};

#endif
