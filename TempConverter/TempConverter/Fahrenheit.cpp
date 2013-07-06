#include "Fahrenheit.h"

Fahrenheit::Fahrenheit(void)
{
	std::cout << "Fahrenheit Class Created" << std::endl;
}


Fahrenheit::~Fahrenheit(void)
{
}


double Fahrenheit::fahrenheitToCelsius(double temp){
	return (temp - 32.0)* (5.0 / 9.0);
}

double Fahrenheit::fahrenheitToKelvin(double temp){
	return ((temp - 32.0) * (5.0 / 9.0)) + 273.15;
}