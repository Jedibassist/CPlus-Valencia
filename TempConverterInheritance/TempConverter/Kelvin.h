#pragma once
#ifndef KELVIN_H
#define KELVIN_H

class Kelvin
{
public:
	Kelvin(void);
	~Kelvin(void);

	double Kelvin::kelvinToFahrenheit(double temp);
	double Kelvin::kelvinToCelsius(double temp);
};

#endif