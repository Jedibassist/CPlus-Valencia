#include "Second.h"

Second::Second()
{
	std::cout << "I've been constructed" << std::endl;
}

void Second::eat()
{
	std::cout << "The second class is eating" << std::endl;
}

void Second::setVars()
{
	a = 10;
	b = 20;
}