#ifndef FIRST_H
#define FIRST_H

#include <iostream>

class First
{
	int a;
	int b;

public:
	First();
	First(int a, int b);

	virtual void eat();
	void hello();

	friend class Second;
};

#endif