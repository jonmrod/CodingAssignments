/*
Program name: max.c
Purpose: determine greatest value of 3 given command line parameteres
Date: 2/16/16
Input: Three numbers (ex: ./a.out 1 2 3)
Output: Greatest value out of 3 numbers
*/

#include <stdio.h>
#include <stdlib.h> //atoi
#include <ctype.h> //isdigit
#include <stdbool.h> //boolean

int checkDigit (int argument, char *argv[]) {
	int counter = 1; //argument counter
	int max = 0; //max value
	bool wrong = false; //boolean for wrong/right value input
	bool correct = false;
	int whichWrong = 0; //which index is wrong


	//go through each argument value
	while (counter < argument) {
		//check if letter or numbers
		int value = *argv[counter];
		//if its a letter
		if (!isdigit(value)) {
			wrong = true;
			whichWrong = counter;
		}
		//if its a number
		else {
			correct = true;
			//calculate max
			if (value > max) {
				max = atoi(argv[counter]);
			}
		}
		counter++;
	}
	//if its wrong input
	if (wrong) {
		printf("max: invalid input %s\n", argv[whichWrong]);
		exit(0);
	}
	//if its correct input
	if (correct) {
		printf("The maximum value is %d\n", max);
		exit(0);
	}
	return 0;
}

int main(int argc, char *argv[]) {
	//start checking after argument 1 because of filename
	//check if exactly 3 values
	if (argc == 4) {
		checkDigit(argc, argv);
	}
	//if not 3 values
	else {
		printf("Usage: max num1 num2 num3\n");
	}
}