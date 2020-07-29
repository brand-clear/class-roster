#pragma once
#include "student.h"
using namespace std;


class Roster
{
private:
	int lastIndex;
	int maxRosterSize;
	Student** classRosterArray;

public:
	Roster(int rosterSize);
	Student* getStudentAtIndex(int index);
	void add(string studentID, string firstName, string lastName, 
		string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
		int daysInCourse3, DegreeProgram degreeProgram);
	void parseThenAdd(string row);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};