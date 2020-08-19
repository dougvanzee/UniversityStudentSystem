#include "student.h"
#include <iostream>

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	// Set student info
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->daysToCompleteEachCourse[0] = daysInCourse1;
	this->daysToCompleteEachCourse[1] = daysInCourse2;
	this->daysToCompleteEachCourse[2] = daysInCourse3;
	this->degreeProgram = degreeProgram;
}


void Student::setDaysToCompleteEachCourse(int daysToCompleteEachCourse[3])
{
	// Set the days to complete each course var
	for (int i = 0; i < 3; i++)
	{
		this->daysToCompleteEachCourse[i] = daysToCompleteEachCourse[i];
	}
}


void Student::print()
{
	// Print student info to the console
	cout << studentId << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Age: " << studentAge << "\t";
	cout << "daysInCourse: {" << daysToCompleteEachCourse[0] << ", " << daysToCompleteEachCourse[1] << ", " << daysToCompleteEachCourse[2] << "} ";
	cout << "Degree Program: ";

	// Print the designated degree program to console
	switch (degreeProgram)
	{
	case DegreeProgram::SECURITY:
		cout << "Security" << endl;
		break;

	case DegreeProgram::NETWORK:
		cout << "Network" << endl;
		break;

	case DegreeProgram::SOFTWARE:
		cout << "Software" << endl;
		break;

	default:
		cout << "N/A" << endl;
		break;

	}
}
