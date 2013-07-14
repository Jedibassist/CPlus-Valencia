#ifndef SECOND_H
#define SECOND_H

#include "First.h"

class Second : public First
{
public:
	Second();
	Second(int a, int b);

	virtual void eat();
	//void hello();

	void setVars();

};

#endif