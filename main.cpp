#include <iostream>
#include <thread>
#include <chrono>
#include "Snek.h"
#include "Food.h"
#include <conio.h>																// added libraries for thread, sleep etc.

using namespace std;

int plane[15][45];																// initiating the plane 														
int refresh(Snek*, Food);														// Function to allow screen to update
int user(Snek*);																// function to allow user input
void build();
void output();
char direction;																	// gives direction for detection

int main(int argc, char** argv) {
	srand(time(NULL));															// initiate clock for random num gen
	build();																	// build the array
	Snek Snake(plane, 20, 8);													// initialize snake object
	Food Froot;																	// initialize fruit object
	thread T2(user, &Snake);													// initiate thread to allow user input
	thread T1(refresh, &Snake, Froot);											// initiate thread to allow snake to move											
	T1.join();																	// end threads when game over
	T2.join();	
	return 0;
}

int refresh(Snek *Snake, Food Froot){
	Froot.spawn(plane);															// spawn the first fruit
	while(Snake->alive == true){												// while the player has not collided with anything
		system("CLS");															// update screen
		Snake->moveSK(plane, direction, &Froot);								
		if (Froot.touch == true){												// if the last fruit has been touched respawn in new position
			Froot.spawn(plane);
			Froot.touch = false;
		}
		output();	
		cout << "Score is " << Snake->size-1 << endl;		
		_sleep(350);															// wait to allow user to react
	}		
	system("CLS");																
	cout << "Game Over" << endl;
	return 0;																	// end
}

int user(Snek *Snake){
	while(Snake->alive == true){												// while snake is alive accept input
	direction = getche();		
	}
	return 0;
}

void build(){																	// build the plane
	for (int j = 0; j < 15; j++){												// place -1 is all spaces to symbolize empty space							
		for (int i = 0; i < 45;i++){
			plane[j][i] = -1;
		}
	}
}

void output(){
	for (int g = 0; g< 47; g++){												// outputs top boundary
		if (g == 0){
			cout << char(201);
		}
		else if(g == 46){
			cout << char(187);
		}
		else{
			cout << char(205);
		}
	}
	cout << endl;
	for (int j = 0; j < 15; j++){												//outputs snake, fruit, empty sapce  depending on integer value
		cout << char(186);														// output left boundary				
		for(int i = 0; i < 45; i++){
														
			if (plane[j][i] == -1){
				cout << char(176);												// output space
			}
			else if (plane[j][i] > 0){
				cout << char(219);												// output snake
			}
			else if (plane[j][i] == 0){											// output fruit
				cout << "@";
			}
		}
		cout << char(186) << endl;												// output right boundary
	}
	for (int g = 0; g< 47; g++){												// output bottom boundary
		if (g == 0){
			cout << char(200);
		}
		else if(g == 46){
			cout << char(188);
		}
		else{
			cout << char(205);
		}
	}
	cout << endl;
}
