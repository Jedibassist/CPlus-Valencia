#include "Kelvin.h"

Kelvin::Kelvin(void)
{
	std::cout << "Kelvin Class Created" << std::endl;
}

Kelvin::~Kelvin(void)
{
}

double Kelvin::kelvinToFahrenheit(double temp){
	return ((temp - 273.15) * 1.8) + 32;
}

double Kelvin::kelvinToCelsius(double temp){
	return temp - 273.15;
}