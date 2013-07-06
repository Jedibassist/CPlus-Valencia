#pragma once
#include <iostream>

class Celsius
{
public:
	Celsius(void);
	~Celsius(void);

	double Celsius::celsiusToFahrenheit(double temp);
	double Celsius::celsiusToKelvin(double temp);
};
