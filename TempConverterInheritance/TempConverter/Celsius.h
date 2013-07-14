#pragma once
#ifndef CELSIUS_H
#define CELSIUS_H

class Celsius
{
public:
	Celsius(void);
	~Celsius(void);

	double Celsius::celsiusToFahrenheit(double temp);
	double Celsius::celsiusToKelvin(double temp);
};

#endif