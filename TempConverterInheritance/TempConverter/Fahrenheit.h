#pragma once
#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H

class Fahrenheit
{
public:
	Fahrenheit(void);		 
	~Fahrenheit(void);

	double Fahrenheit::fahrenheitToCelsius(double temp);
	double Fahrenheit::fahrenheitToKelvin(double temp);
};

#endif