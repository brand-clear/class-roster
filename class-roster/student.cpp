#include <iostream>
#include <cstdio>
#include <algorithm>
#include "student.h"
using namespace std;


// Construct the Student object per requirement D.2.d
Student::Student(string studentID, string firstName, string lastName, 
	string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
	int daysInCourse3, DegreeProgram degreeProgram) {
	// Map parameters to member variables
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDaysInCourses(daysInCourse1, daysInCourse2, daysInCourse3);
	setDegreeProgram(degreeProgram);
};


// Assign inputs to member array per requirement D.2.b
void Student::setDaysInCourses(int daysInCourse1, int daysInCourse2, 
	int daysInCourse3) {
	daysInCourses[0] = daysInCourse1;
	daysInCourses[1] = daysInCourse2;
	daysInCourses[2] = daysInCourse3;
}


// Print specific student data to standard output per requirement D.2.e
void Student::print() {
	/* 
	Transform degreeProgram text to have only the first letter
	capitalized per requirement E.3.c.
	*/
	string program = degreeProgramStrings[degreeProgram];
	for_each(program.begin(), program.end(), [](char& c){c = tolower(c);});
	program[0] = toupper(program[0]);

	printf(
		"%s\tFirst Name: %s\tLast Name: %s\tAge: %d\tdaysInCourse: {%d, %d, %d} Degree Program: %s\n", 
		studentID.c_str(), firstName.c_str(), lastName.c_str(), age, 
		daysInCourses[0], daysInCourses[1], daysInCourses[2], program.c_str()
	);
}