/*
Part 3.cpp
Michael Seveigny
10/30/2025
Description:
A run is a sequence of adjacent repeated values. Using an array, write a program that generates a sequence of
20 random six-sided die tosses, determines whether or not a run is present and prints out this information, and
prints all the die values, marking the runs by including them in parentheses, as shown in this example run:
no run: 1 2 3 4 3 2 6 4 5 3 2 3 1 3 4 5 6 2 1 3
has run: 1 2 (5 5) 3 1 2 4 3 (2 2 2 2) 3 6 (5 5) 6 3 1
To do this, you are to implement the following functions:
void displayRun( int values[], int size )
This function receives an array of die values and prints out the values in order, encapsulating the runs within
parentheses such that there is no space between the left parenthesis and the first value within a run, and no
space between the last value within a run and the right parenthesis.

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int sizeMax = 20;
void displayRun(int values[], int size);

int main(void) {
	// Declares variables
	int dieValues = sizeMax;
	int values[sizeMax];

	// Seed random number generator
	srand(unsigned(time(0)));

	// Creat array (random values) and display without runs
	cout << "No run: ";
	for (int i = 0; i < dieValues; i++) {
		values[i] = (rand() % 6) + 1; // Random number between 1 and 6
		cout << values[i] << " ";
	}
	cout << endl;

	// Display array with runs
	cout << "Has run: ";
	displayRun(values, dieValues);
	return 0;
}

void displayRun(int values[], int size) {
	bool inRun = false;
	for (int i = 0; i < size; i++) {
		// Check for start of a run
		if (i < size - 1 && values[i] == values[i + 1] && !inRun) {
			cout << "(" << values[i] << " ";
			inRun = true;
		}
		// Check for end of a run
		else if (inRun && (i == size - 1 || values[i] != values[i + 1])) {
			cout << values[i] << ") ";
			inRun = false;
		}
		// Normal value
		else {
			cout << values[i] << " ";
		}
	}
	cout << endl;
}