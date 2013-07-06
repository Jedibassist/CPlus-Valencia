#include "Converter.h"

int startingTempChoice();
int endingTempChoice();
double getTempToConvert(int tempType);
double convertTemperature(int startingType, int endingType, double temp,
						  Fahrenheit *fConverter, Celsius *cConverter, Kelvin *kConverter);

void main(){
	Fahrenheit FahrenheitConverter;
	Celsius CelsiusConverter;
	Kelvin KelvinConverter;

	int startingTempType, endingTempType;
	double tempToConvert, convertedTemp;
	char loop;

	cout << endl << "Welcome to the Temperature Converter Program!" << endl;

	while(true){
		startingTempType = startingTempChoice();
		endingTempType = endingTempChoice();

		if(startingTempType == endingTempType){
			cout << "Well that's silly isn't it? We don't need to convert that!" << endl;
		}else{
			tempToConvert = getTempToConvert(startingTempType);

			convertedTemp = convertTemperature(startingTempType, endingTempType, tempToConvert,
												&FahrenheitConverter, &CelsiusConverter, &KelvinConverter);

			cout << endl << "Your final converted Temperature is: " << convertedTemp << " Degrees "; 
			if(endingTempType == 1)
				cout << "Fahrenheit";
			if(endingTempType == 2)
				cout << "Celsius";
			if(endingTempType == 3)
				cout << "Kelvin";
			cout << endl << endl;

			cout << "Would you like to convert another temperature? (y/n) ";
			cin >> loop;

			if(!(loop == 'y')){
				cout << "Have a nice day!" << endl;
				break;
			}
		}
	}

	system("pause");
}

// Get starting Temp Type
int startingTempChoice(){
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
int endingTempChoice(){
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
double getTempToConvert(int tempType){
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

double convertTemperature(int startingType, int endingType, double temp,
						  Fahrenheit *fConverter, Celsius *cConverter, Kelvin *kConverter){
	double converted;

	if(startingType == 1){
		if(endingType == 2)
			converted = fConverter->fahrenheitToCelsius(temp);
		if(endingType == 3)
			converted = fConverter->fahrenheitToKelvin(temp);
	}else if(startingType == 2){
		if(endingType == 1)
			converted = cConverter->celsiusToFahrenheit(temp);
		if(endingType == 3)
			converted = cConverter->celsiusToKelvin(temp);
	}else{
		if(endingType == 1)
			converted = kConverter->kelvinToFahrenheit(temp);
		if(endingType == 2)
			converted = kConverter->kelvinToCelsius(temp);
	}
	
	return converted;
}