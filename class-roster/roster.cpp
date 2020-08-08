#include "roster.h"
#include <iostream>
#include <vector>
#include <sstream>


// Constructor
Roster::Roster(int rosterSize) {
	lastIndex = -1; // Indicates an empty array
	maxRosterSize = rosterSize;
	classRosterArray = new Student* [maxRosterSize];
}


// Return the Student object at a given index.
Student* Roster::getStudentAtIndex(int index) {
	return classRosterArray[index];
}


// Extract student information from string and add Student to roster.
// row is assumed to be a string of comma-separated values.
void Roster::parseThenAdd(string row) {
	vector<string> result;
	stringstream rowStream(row);
	while (rowStream.good()) {
		string subString;
		getline(rowStream, subString, ',');
		result.push_back(subString);  // Append value to result vector
	}

	string studentID, firstName, lastName, emailAddress, degreeProgramString;
	int age, daysInCourse1, daysInCourse2, daysInCourse3;
	DegreeProgram degreeProgram{};

	// Map values to Student attribute fields.
	studentID = result[0];
	firstName = result[1];
	lastName = result[2];
	emailAddress = result[3];
	age = stoi(result[4]);
	daysInCourse1 = stoi(result[5]);
	daysInCourse2 = stoi(result[6]);
	daysInCourse3 = stoi(result[7]);
	degreeProgramString = result[8];

	// Assume for this application that degreeProgramString 
	// meets one of these conditions.
	if (degreeProgramString == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (degreeProgramString == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (degreeProgramString == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, 
		daysInCourse2, daysInCourse3, degreeProgram);
}


// Append a Student object to the roster.
void Roster::add(string studentID, string firstName, string lastName, 
	string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
	int daysInCourse3, DegreeProgram degreeProgram) {
	lastIndex++;
	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName,
		emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3,
		degreeProgram);
}


// Call print function from each student instance per requirement E.3.c
void Roster::printAll(){
	for (int i = 0; i <= lastIndex; i++)
	{
		classRosterArray[i]->print();
	};
	cout << endl;
}


// Remove a student from the roster per requirement E.3.b
void Roster::remove(string studentID) {
	bool studentFound = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			studentFound = true;
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[lastIndex];
			lastIndex--;
		}
	}

	if (studentFound == false) {
		cout << "Student with ID: " << studentID << " not found." << endl;
	}
	else {
		cout << "Student " << studentID << " removed successfully.";
		cout << endl  << endl;
	}
}


// Print emails that do not conform to requirement E.3.e
void Roster::printInvalidEmails() {
	cout << "Invalid emails:" << endl;
	string invalidEmailString;
	string email;
	
	for (int i = 0; i <= lastIndex; i++) {
		email = classRosterArray[i]->getEmailAddress();
		if (email.find('@') == string::npos) {
			invalidEmailString += email + "\n";
			continue;
		}
		else if (email.find('.') == string::npos) {
			invalidEmailString += email + "\n";
			continue;
		}
		else if (email.find(' ') != string::npos) {
			invalidEmailString += email + "\n";
		}
	}
	cout << invalidEmailString;
}


// Print student information by degree program per requirement E.3.f
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

// Print the average number of days per course a student has left 
// per requirement E.3.d
void Roster::printAverageDaysInCourse(string studentID) {
	Student* student;
	for (int i = 0; i <= lastIndex; i++) {
		student = classRosterArray[i];
		if (student->getStudentID() == studentID) {
			const int* days = student->getDaysInCourses();
			cout << "The average number of days left in each course for ";
			cout << "student " << studentID << " is ";
			cout << (double)days[0] + (double)days[1] + days[2] / 3.0 << endl;
		}
	}
}


// Implement destructor to release dynamically allocated memory per
// requirement F.5
Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}