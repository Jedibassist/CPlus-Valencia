#pragma once
#include <iostream>

class Fahrenheit
{
public:
	Fahrenheit(void);		 
	~Fahrenheit(void);

	double Fahrenheit::fahrenheitToCelsius(double temp);
	double Fahrenheit::fahrenheitToKelvin(double temp);
};

