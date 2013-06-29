#include "stdafx.h"
#include <string>

int main(){

	ofstream myOutputFile;
	ifstream myInputFile;

	myOutputFile.open("C://text.txt");
	myOutputFile << "Writing a test output line \n";
	myOutputFile.close();

	myOutputFile.open("C://text.txt", ios_base::app);

	if(myOutputFile.is_open()){
		myOutputFile << "Add another line to the file" << endl;
		myOutputFile.close();
	}else{
		cout << "NOPE" << endl;
	}

	myInputFile.open("C://text.txt");

	if(myInputFile.is_open()){
		while(!myInputFile.eof()){
			string myLine;
			getline(myInputFile, myLine);
			cout << myLine << endl;
		}
		myInputFile.close();
	}else{
		cout << "NOPE AGAIN" << endl;
	}	

	system("pause");
	return 0;
}