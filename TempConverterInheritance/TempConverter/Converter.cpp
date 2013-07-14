#include "Converter.h"

Converter::Converter(){
}

Converter::~Converter(){
	cout << "Deconstructing object." << endl;
}

// Get starting Temp Type
int Converter::startingTempChoice(){
	int choice;

	cout << "What temperature format are you starting with?" << endl
		<< "\t1: Fahrenheit\n\t2: Celsius\n\t3: Kelvin" << endl;

	// Get input and validate.
	while(true) {
		cin >> choice;

		if((cin) && (choice > 0) && (choice <= 3))
			break;

		cin.clear();
		cin.ignore( 1000, '\n' );
		cout << "That is not a valid selection. Please choose again." << endl;
	}

	return choice;
}

// Get temp type we are converting to
int Converter::endingTempChoice(){
	int choice;

	cout << "What temperature format are you converting to?" << endl
		<< "\t1: Fahrenheit\n\t2: Celsius\n\t3: Kelvin" << endl;

	// Get input and validate.
	while(true) {
		cin >> choice;

		if((cin) && (choice > 0) && (choice <= 3))
			break;

		cin.clear();
		cin.ignore( 1000, '\n' );
		cout << "That is not a valid Temperature. Try again." << endl;
	}

	return choice;
}

// Get temp type we are converting to
double Converter::getTempToConvert(int tempType){
	double choice;

	cout << "What temperature are we converting: ";

	// Get input and validate.
	while(true) {
		cin >> choice;

		if(tempType == 1){
			if((cin) && (choice >= -459.67))
				break;
		}else if(tempType == 2){
			if((cin) && (choice >= -273.15))
				break;
		}else{
			if((cin) && (choice >= 0))
				break;
		}

		cin.clear();
		cin.ignore( 1000, '\n' );
		cout << "That is not a valid selection. Please choose again." << endl;
	}

	return choice;
}

double Converter::convertTemperature(int startingType, int endingType, double temp,	Converter *tConverter)
{
	double converted;

	if(startingType == 1){
		if(endingType == 2)
			converted = tConverter->fahrenheitToCelsius(temp);
		if(endingType == 3)
			converted = tConverter->fahrenheitToKelvin(temp);
	}else if(startingType == 2){
		if(endingType == 1)
			converted = tConverter->celsiusToFahrenheit(temp);
		if(endingType == 3)
			converted = tConverter->celsiusToKelvin(temp);
	}else{
		if(endingType == 1)
			converted = tConverter->kelvinToFahrenheit(temp);
		if(endingType == 2)
			converted = tConverter->kelvinToCelsius(temp);
	}
	
	return converted;
}