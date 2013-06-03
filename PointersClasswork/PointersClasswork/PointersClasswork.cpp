// PointersClasswork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int myInt = 5;

int main()
{
	//delcare an int variable
	
	
	//declare a pointer.  This represents that myRefAddress now points to an int
	int *myRefAddress;
	
	//set the pointer to reference the memory address of myInt
	myRefAddress = &myInt;
	
	//use the * to update the memory address that is stored.  It will put a new vale at that address
	*myRefAddress = 10;
	
	//myInt has a new value because the address it is referencing has an updated value
	cout << myInt << endl;
	
	//short cut: int *myRefAddress = &myInt;
	
	//declare another int variable
	int total = 15;
	
	//make sum and total reference the same place in memory
	int& sum = total;
	
	//change sum
	sum = 18;
	
	//it updates total
	cout << total << endl;
	
	//change total
	total = 21;
	
	//it updates sum
	cout << sum << endl;
	
	system("pause");

	return 0;
}