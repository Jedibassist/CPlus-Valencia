#include "First.h"

First::First(){
	std::cout << "Build Me!" << std::endl;
};

First::First(int firstInt, int secondInt)
{	
	First::a = firstInt;
	First::b = secondInt;
}

void First::hello(){
	std::cout << "I am the first object" << std::endl;
}

void First::eat(){
	std::cout << "The first object is eating" << std::endl;
};