#include "Calc.h"
using namespace std;

Calc<int> Calculate;

int chooseMathType();
int getFirstNumber();
int getSecondNumber();

void doMath(int type, int firstNum, int secondNum);

int main(){

	int mathType, firstNum, secondNum;
	bool proceed = true;
	char choice;

	do{
		mathType = chooseMathType();
		firstNum = getFirstNumber();
		secondNum = getSecondNumber();

		cout << "The answer is : ";
		doMath(mathType, firstNum, secondNum);
		cout << endl;

		cout << "Would you like to solve another equation? (y / n)" << endl;
		cin >> choice;
		if(choice != 'y')
			proceed = false;
	}while(proceed);

	cout << "Thank you for using this really simple program :P" << endl;

	system("pause");
	return 0;
}

int  chooseMathType(){
	cout << "What type of Arithmetic are we performing?" <<  endl;
	cout << "\t1: Addition\n\t2: Subtraction\n\t3: Multiplication\n\t4: Division" << endl;

	int choice;
	cin >> choice;

	return choice;
}

int getFirstNumber(){
	int number;

	do{
		try{
			cout << "What is the first Number : ";
			cin >> number;
			if(number < 0){
				throw 1;
			}
		}catch(int error){
			cout << "Negatives are not allowed ... Please try again." << endl;
		}
	}while(number < 0);

	return number;
}

int getSecondNumber(){
	int number;

	do{
		try{
			cout << "What is the second Number : ";
			cin >> number;
			if(number < 0){
				throw 1;
			}
		}catch(int error){
			cout << "Negatives are not allowed ... Please try again." << endl;
		}
	}while(number < 0);

	return number;
}

void doMath(int type, int firstNum, int secondNum){

	if(type == 1)
		cout << Calculate.Add(firstNum, secondNum) << endl;
	if(type == 2)
		cout << Calculate.Subtract(firstNum, secondNum) << endl;
	if(type == 3)
		cout << Calculate.Multiply(firstNum, secondNum) << endl;
	if(type == 4)
		cout << Calculate.Divide(firstNum, secondNum) << endl;

}