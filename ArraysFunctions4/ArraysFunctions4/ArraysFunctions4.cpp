// ArraysFunctions4.cpp : Defines the entry point for the console application.
/* Jed Gravelin, June 2013
 * 
 * Part 1 Answers:
 * 1 : If a variable is declared within the paramaters of a function, that variable is NOT available in main
 * 2 : If a variable is declared within a function itself, that variable is NOT available in main
 * 3 : If a variable is declared in main, that variable can be accessed by the function as long as the reference
 *     to the function's memory location is passed in to the function.
 * 4 : If a global variable is defined, that can be used within any functions or main. If a variable is instantiated
 *     within a class, that variable can be accessed by functions of that class if it is passed by reference.
 *
*/

// Test

#include "stdafx.h"
#include <iostream>

using namespace std;
// The number of items on the menu
#define MENU_ITEMS 9

// Define an item
typedef struct {
	char name[20];
	double price;
}item;

// Prototype all the Functions
double sum(int a, int b);
double sum(double a, double b);
double sum(int a, double b);

void printMenu();
double swapMenuItems(char* oldItem, char* newItem);
double superSize(double mealTotal);
double addTaxes(double mealTotal);

double bigMacMeal();
double fishFiletMeal();
double chickenNuggetsMeal();
double hamburgerMeal();

// Creating the 9 Menu items as structs and putting them into an array
item menuitems[MENU_ITEMS] = {"BigMac", 3.49, "FishFilet", 3.89, "Hamburger", .79, "ChickenNuggets", 3.53,
								"Fries", 1.89, "SuperFries", 2.89, "Drink", 1.10, "SuperDrink", 2.52, "Tax", .065};

void main()
{
	// Set precision of cout
	cout.precision(3);

	cout << "Testing..." << endl;
	cout << sum(5, 6) << endl;
	cout << sum(5.3, 6.4) << endl;
	cout << sum(5, 8.5) << endl << endl;

	int choice = 0;
	double mealTotal = 0;

	cout << "Welcome to McDonalds!" << endl;
	printMenu();

	// Get input and validate.
	while(true) {
	  cin >> choice;

	  if((cin) && (choice > 0) && (choice < 5))
		  break;

	  cin.clear();
	  cin.ignore( 1000, '\n' );
	  cout << "That is not a valid menu selection. Please choose again." << endl;
	}

	//while(!(cin >> choice)){
	//	cout << "That is not a valid menu selection. Please choose again." << endl;
	//	cin >> choice;
	//}

	switch(choice){
		case 1:
			mealTotal = bigMacMeal();
			cout << "After Tax, your Big Mac Meal Comes to $";
			if(int(mealTotal * 100) % 10 == 0){
				cout << mealTotal << "0" << endl << endl;
			}else{
				cout << mealTotal << endl << endl;
			}
			break;
		case 2:
			mealTotal = fishFiletMeal();
			cout << "After Tax, your Fish o Filet Meal Comes to $";
			if(int(mealTotal * 100) % 10 == 0){
				cout << mealTotal << "0" << endl << endl;
			}else{
				cout << mealTotal << endl << endl;
			}
			break;
		case 3:
			mealTotal = chickenNuggetsMeal();
			cout << "After Tax, your Chicken Nuggets Meal Comes to $";
			if(int(mealTotal * 100) % 10 == 0){
				cout << mealTotal << "0" << endl << endl;
			}else{
				cout << mealTotal << endl << endl;
			}
			break;
		case 4:
			mealTotal = hamburgerMeal();
			cout << "After Tax, your Hamburger Meal Comes to $";
			if(int(mealTotal * 100) % 10 == 0){
				cout << mealTotal << "0" << endl << endl;
			}else{
				cout << mealTotal << endl << endl;
			}
			break;
		default:
			break;
		}
	system("pause");
}

// Sum test A
double sum(int a, int b){
	return ((double) a + b);
}
// Sum test B
double sum(double a, double b){
	return a + b;
}
// Sum test C
double sum(int a, double b){
	return ((double) a) + b;
}

// Prints the Menu and prompts for choice
void printMenu(){
	cout << "Please select a choice from the following Menu:" << endl;
	cout << "1. Big Mac Meal - $6.48" << endl;
	cout << "2. Fish o Filet Meal - $6.88" << endl;
	cout << "3. Chicken Nugget Meal - $6.52" << endl;
	cout << "4. Hamburger Meal - $3.78" << endl << endl;
}

// Will Swap Menu items in a Meal, and Update the total cost
double swapMenuItems(char* oldItem, char* newItem){
	double cost = 0;
	int i;
	for(i = 0;i < MENU_ITEMS;i++){
		if(strcmp(oldItem, menuitems[i].name) == 0){
			cost -= menuitems[i].price;
		}
		if(strcmp(newItem, menuitems[i].name) == 0){
			cost += menuitems[i].price;
		}
	}

	return cost;
}

// Asks for Drink and Fries SuperSize upgrades
// Takes in beginning total, Returns Modified total
double superSize(double mealTotal){
	double total = mealTotal;
	char choice;
	// SuperSize Drink ?
	cout << "Would you like to SuperSize your Drink? (y/n)";
	cin >> choice;
	if(choice == 'y'){
		total += swapMenuItems("Drink", "SuperDrink");
		cout << "You have chosen to SuperSize your Drink." << endl;
		if(int(total * 100) % 10 == 0){
			cout << "Your new total is $" << total << "0" << endl << endl;
		}else{
			cout << "Your new total is $" << total << endl << endl;
		}
	}else{
		cout << "You have chosen not to SuperSize." << endl << endl;
	}
	// SuperSize Fries ?
	cout << "Would you like to SuperSize your Fries? (y/n)";
	cin >> choice;
	if(choice == 'y'){
		total += swapMenuItems("Fries", "SuperFries");
		cout << "You have chosen to SuperSize your Fries." << endl;
		if(int(total * 100) % 10 == 0){
			cout << "Your new total is $" << total << "0" << endl << endl;
		}else{
			cout << "Your new total is $" << total << endl << endl;
		}
	}else{
		cout << "You have chosen not to SuperSize." << endl << endl;
	}
	return total;
}

// Will return the total plus 6.5% tax
double addTaxes(double mealTotal){
	return mealTotal + (mealTotal * menuitems[8].price);
}

// Will run the program for a Big Mac Meal
double bigMacMeal(){
	double mealTotal = 6.48;
	cout << "You have chosen the Big Mac Meal - $6.48" << endl;
	return addTaxes(superSize(mealTotal));
}

// Will run the program for a Fish o Filet Meal
double fishFiletMeal(){
	double mealTotal = 6.88;
	cout << "You have chosen the Fish o Filet Meal - $6.88" << endl;
	return addTaxes(superSize(mealTotal));
}

// Will run the program for a Chicken Nuggets Meal
double chickenNuggetsMeal(){
	double mealTotal = 6.52;
	cout << "You have chosen the Chicken Nuggets Meal - $6.52" << endl;
	return addTaxes(superSize(mealTotal));
}

// Will run the program for a Hamburger Meal
double hamburgerMeal(){
	double mealTotal = 3.78;
	cout << "You have chosen the Hamburger Meal - $3.78" << endl;
	return addTaxes(superSize(mealTotal));
}

