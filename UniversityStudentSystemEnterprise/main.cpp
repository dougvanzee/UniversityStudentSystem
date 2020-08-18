/*
	The University Student System - Enterprise Edition, or USS Enterprise for short, is a program designed to create, edit, and track student records and academic progress.
	
	Written by Doug Van Zee
*/

#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

using namespace std;

int main()
{
	// Print out program information
	cout << "Course: Scripting and Programming - Applications – C867" << endl;
	cout << "Written in C++ by Doug Van Zee" << endl;
	cout << "Student ID #001470568" << endl;

	// Create a class roster
	Roster* classRoster = new Roster();

	// Student data imported from old system
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Doug,Van Zee,dmvanzee@gmail.com,30,7,1,2,SOFTWARE"
	};

	// Parses the student data into separate variables and creates a new student in the classRoster for each entry
	for (int i = 0; i < size(studentData); i++)
	{
		istringstream studentStream(studentData[i]);

		string studentID;
		getline(studentStream, studentID, ',');

		string firstName;
		getline(studentStream, firstName, ',');

		string lastName;
		getline(studentStream, lastName, ',');

		string emailAddress;
		getline(studentStream, emailAddress, ',');

		string studentAge;
		getline(studentStream, studentAge, ',');

		string daysInCourse1;
		getline(studentStream, daysInCourse1, ',');

		string daysInCourse2;
		getline(studentStream, daysInCourse2, ',');

		string daysInCourse3;
		getline(studentStream, daysInCourse3, ',');

		string degreeProgramString;
		getline(studentStream, degreeProgramString, ',');

		DegreeProgram degreeProgram;
		if (degreeProgramString == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		else if (degreeProgramString == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}
		else {
			degreeProgram = DegreeProgram::SOFTWARE;
		}

		classRoster->add(studentID, firstName, lastName, emailAddress, stoi(studentAge), stoi(daysInCourse1), stoi(daysInCourse2), stoi(daysInCourse3), degreeProgram);
	}

	// Print all student info
	classRoster->printAll();

	// Print invalid emails
	/////////////////////////////////////////////////////////////////////////////////////

	// Loop through classRosterArray and print average days in courses for all students
	/////////////////////////////////////////////////////////////////////////////////////

	// Print by degree program
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);

	// Remove studentID A3
	classRoster->remove("A3");

	// Print all student info
	classRoster->printAll();

	// Remove studentID A3
	classRoster->remove("A3");

	// Call Roster deconstructor
	delete classRoster;

	return 0;
}