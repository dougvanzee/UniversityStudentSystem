#pragma once
#include <vector>
#include "student.h"

class Roster
{
public:
	
	Roster(); // Constructor

private:

	vector<Student*> classRosterArray; // Holds an array of pointers for all students


public:

	// Adds a student to the classRosterArray
	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram
	);

	// Removes a student from the classRosterArray by StudentID.
	// If more than one student has the same ID, the first one found will be removed.
	void remove(string studentID);

	// Prints information about all students in classRosterArray
	void printAll();

	// Prints the average days a student spends in their course using their studentID
	void printAverageDaysInCourse(string studentID);

	// Displays students with an improperly formatted email address
	void printInvalidEmails();

	// Prints out student information for all students in a particular degree
	void printByDegreeProgram(DegreeProgram degreeProgram);
};

