// StructsAssignment6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

struct student{
	string name;
	int VID;
};

struct course{
	student students[3];
};

void main (){
	course courses[2];

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

	// Print out the students VID's
	for(i = 0; i < sizeof(courses)/sizeof(*courses); i++){
		cout << "Course " << i + 1 << " student VID's:" << endl;
		for(j = 0; j < sizeof(courses[i].students)/sizeof(*courses[i].students); j++){
			cout << courses[i].students[j].VID << endl;
		}
		cout << endl;
	}

	system("pause");
}

