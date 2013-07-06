#include "Celsius.h"

Celsius::Celsius(void)
{
	std::cout << "Celsius Class Created" << std::endl;
}

Celsius::~Celsius(void)
{
}

double Celsius::celsiusToFahrenheit(double temp){
	return ((temp) * (9.0 / 5.0)) + 32.0;
}

double Celsius::celsiusToKelvin(double temp){
	return temp + 273.15;
}