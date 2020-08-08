#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;


int main() {

	// Satisfy F.1 requirement
	cout << "***Course: Scripting & Programming - Applications" << endl;
	cout << "***Language Used: C++" << endl;
	cout << "***Student: Brandon McCleary 001453149" << endl << endl;

	// Initialize studentData Table as array
	const int studentCount = 5;
	const string studentData[studentCount] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,10,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,59,40,SECURITY",
		"A5,Brandon,McCleary,bmccl47@wgu.edu,34,12,15,19,SOFTWARE"
	};

	// Create an instance of roster named classRoster per requirement F.2
	Roster * classRoster = new Roster(studentCount);

	for (int i = 0; i < studentCount; i++) {
		// Add each student to classRoster per requirement F.3
		classRoster->parseThenAdd(studentData[i]);
	}

	// Convert pseudo code to complete main function per requirement F.4
	classRoster->printAll();
	classRoster->printInvalidEmails();

	cout << endl;

	string tempID;
	for (int i = 0; i < 5; i++)	{
		tempID = classRoster->getStudentAtIndex(i)->getStudentID();
		classRoster->printAverageDaysInCourse(tempID);
	}

	cout << endl;

	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");

	cout << endl;

	classRoster->~Roster();

	return 0;
}