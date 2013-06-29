// Jed Gravelin - June 24th, 2013
// C++ Programming, Valencia College, Summer 2013

#include "stdafx.h"
// Other relevant includes are in header file

using namespace std;


// Set input and output files
	ofstream myOutputFile;
	ifstream myInputFile;

// Struct for a Student
// Each Student has a VID and a name
struct student{
	string name;
	int VID;
};

// Struct for a Course
// Each course has 3 Students and a Name
struct course{
	student students[3];
	string name; // I felt the course needed a name.
};

// Function Prototypes
void printToFile(course coursesToPrint[], int size);
void printToConsole();

void main (){
	course courses[2]; // Set Array of Courses

	// Set Course Names
	courses[0].name = "C++ Programming";
	courses[1].name = "Data Analysis";

	// Create array of Students and Populate
	student students[3];
	students[0].name = "Jed";
	students[0].VID = 12345;

	students[1].name = "Betty";
	students[1].VID = 67894;

	students[2].name = "Jimmy";
	students[2].VID = 65432;

	int i, j;

	// Add students to the structs
	for(i = 0; i < sizeof(courses)/sizeof(*courses); i++){
		for(j = 0; j < sizeof(courses[i].students)/sizeof(*courses[i].students); j++){
			courses[i].students[j] = students[j];
		}
	}

	// Print out the courses with enrolled student VID's and names
	/*
	for(i = 0; i < sizeof(courses)/sizeof(*courses); i++){
		cout << courses[i].name << " students:" << endl;
		for(j = 0; j < sizeof(courses[i].students)/sizeof(*courses[i].students); j++){
			cout << "Student VID :" << courses[i].students[j].VID << "\t"
				<< "Student Name :" << courses[i].students[j].name << endl;
		}
		cout << endl;
	}
	*/

	printToFile(courses, sizeof(courses)/sizeof(*courses));

	printToConsole();

	system("pause");
}

// Pushing the Array data over to a file *pre-formatted
void printToFile(course coursesToPrint[], int size){
	myOutputFile.open("C://CourseEnrollment.txt");

	int i, j;
	for(i = 0; i < size; i++){
		myOutputFile << coursesToPrint[i].name << " students:" << endl;
		for(j = 0; j < sizeof(coursesToPrint[i].students)/sizeof(*coursesToPrint[i].students); j++){
			myOutputFile << "Student VID :" << coursesToPrint[i].students[j].VID << "\t"
				<< "Student Name :" << coursesToPrint[i].students[j].name << endl;
		}
		myOutputFile << endl;
	}
	myOutputFile.close();
}

// Printing the contents of the file to the console
void printToConsole(){
	myInputFile.open("C://CourseEnrollment.txt");

	if(myInputFile.is_open()){
		while(!myInputFile.eof()){
			string myLine;
			getline(myInputFile, myLine);
			cout << myLine << endl;
		}
		myInputFile.close();
	}else{
		cout << "FAILURE" << endl;
	}
}