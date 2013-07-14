#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"

#include <iostream>
#include <string>

using namespace std;

class Converter : public Celsius, Kelvin, Fahrenheit
{
public:
	Converter();
	~Converter();

	int startingTempChoice();
	int endingTempChoice();
	double getTempToConvert(int tempType);
	double convertTemperature(int startingType, int endingType, double temp, Converter *tConverter);

};