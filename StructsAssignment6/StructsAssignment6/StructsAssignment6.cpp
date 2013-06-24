// Jed Gravelin - June 24th, 2013
// C++ Programming, Valencia College, Summer 2013

#include "stdafx.h"
using namespace std;

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
	for(i = 0; i < sizeof(courses)/sizeof(*courses); i++){
		cout << courses[i].name << " students:" << endl;
		for(j = 0; j < sizeof(courses[i].students)/sizeof(*courses[i].students); j++){
			cout << "Student VID :" << courses[i].students[j].VID << "\t"
				<< "Student Name :" << courses[i].students[j].name << endl;
		}
		cout << endl;
	}

	system("pause");
}

