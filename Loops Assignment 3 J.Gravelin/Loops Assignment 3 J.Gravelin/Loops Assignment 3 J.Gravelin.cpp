/* Loops Assignment 3 J.Gravelin.cpp : Defines the entry point for the console application.
 *
 * For Loops - (setup;test;increment){}
 *	The for loop will test prior to running, and continue to loop through until the test condition
 *	is met, or the code hits a break statement.
 *
 * While Loop - (test){}
 *	The while loop will text prior to running, and continue to loop through until the test condition
 *	is met, or the code hits a break statement. Similar to the for loop, but a different fundamental setup
 *
 * Do-While Loop - {}(test)
 *	The do-while loop is a bit special in that it will run through the code block before performing the test.
 *	This allows the code to run even if the test would break the code before it has a chance to run.
 *
*/
#include "stdafx.h"

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void main(){

	int sum = 0, counter = 1;

	while(counter < 1){
		sum++;
		counter++;
	};
	
	cout << "The value of sum is " << sum << endl;

	sum = 0, counter = 1;

	do{
		sum++;
		counter++;
	}while(counter < 1);

	cout << "The value of sum is " << sum << endl << endl;

	/*
	 * As explained above, the while and do-while loops are a bit different, in that the do-while
	 * Loop will always run at least once. This is why you see the variable sum increasing, even 
	 * though the test condition fails at the end of the loop.
	 *
	*/

	int winningNumber, i, guess;

	srand(time(NULL)); // Seeding Rand - I know you told us to use 42, but that was too boring!!!

	winningNumber = rand() % 100;
	cout << "I have chosen a number between 1 and 100, try and guess!" << endl;

	for(i = 0;i < 10;i++){
		cin >> guess;
		if(guess == winningNumber){
			cout << "That was it, you win!" << endl << endl;
			break;
		}else if(guess > winningNumber){
			cout << "That was a bit too high, try again." << endl
				<< "You have " << (9 - i) << " guesses left. Good Luck!"  << endl;
		}else{
			cout << "That was a bit too low, try again." << endl
				<< "You have " << (9 - i) << " guesses left. Good Luck!"  << endl;
		}
	}

	cout << "Guess		: " << guess << endl
		<< "Winning number	: " << winningNumber << endl;

	system("pause");
}
