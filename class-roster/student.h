#pragma once
#include "degree.h"
using namespace std;


class Student {
private:
	// Create member variables per requirement D.1
	static const int COURSE_COUNT = 3;
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourses[COURSE_COUNT];
	DegreeProgram degreeProgram;

public:
	// Create constructor per requirement D.2.d
	Student(string studentID, string firstName, string lastName, 
		string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
		int daysInCourse3, DegreeProgram degreeProgram);

	// Create accessor functions per requirement D.2.a
	string getStudentID() const { return studentID; }
	string getFirstName() const { return firstName; }
	string getLastName() const { return lastName; }
	string getEmailAddress() const { return emailAddress; }
	int getAge() const { return age; }
	const int* getDaysInCourses() const { return daysInCourses; }
	DegreeProgram getDegreeProgram() const { return degreeProgram; }

	// Create mutator functions per requirement D.2.b
	void setStudentID(string ID) { studentID = ID; }
	void setFirstName(string name) { firstName = name; }
	void setLastName(string name) { lastName = name; }
	void setEmailAddress(string email) { emailAddress = email; }
	void setAge(int studentAge) { age = studentAge; }
	void setDaysInCourses(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void setDegreeProgram(DegreeProgram program) { degreeProgram = program; }

	// Create print function per requirement D.2.e
	void print();
};