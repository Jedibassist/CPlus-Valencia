#include "Converter.h"

void main(){
	Converter tempConverter;

	int startingTempType, endingTempType;
	double tempToConvert, convertedTemp;
	char loop;

	cout << endl << "Welcome to the Temperature Converter Program!" << endl;

	while(true){
		startingTempType = tempConverter.startingTempChoice();
		endingTempType = tempConverter.endingTempChoice();

		if(startingTempType == endingTempType){
			cout << "Well that's silly isn't it? We don't need to convert that!" << endl;
		}else{
			tempToConvert = tempConverter.getTempToConvert(startingTempType);

			convertedTemp = tempConverter.convertTemperature(startingTempType, endingTempType, tempToConvert,	&tempConverter);

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
