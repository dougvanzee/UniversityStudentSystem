#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student
{
public:

	// Constructor
	Student(string studentId, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

private:

	// Student private information
	string studentId = "";
	string firstName = "";
	string lastName = "";
	string emailAddress = "";
	int studentAge = -1;
	int daysToCompleteEachCourse[3];
	DegreeProgram degreeProgram = DegreeProgram::SECURITY;

public:

	// Student ID name get/set
	string getStudentId() { return studentId; }
	void setStudentId(string studentId) { this->studentId = studentId; }

	// First Name get/set
	string getFirstName() { return firstName; }
	void setFirstName(string firstName) { this->firstName = firstName; }

	// Last Name get/set
	string getLastName() { return lastName; }
	void setLastName(string lastName) { this->lastName = lastName; }

	// Email get/set
	string getEmailAddress() { return emailAddress; }
	void setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }

	// Age get/set
	int getStudentAge() { return studentAge; }
	void setStudentAge(int studentAge) { this->studentAge = studentAge; }

	// Days to Complete Course Get
	int* getDaysToCompleteEachCourse() { return daysToCompleteEachCourse; }
	// Days to Complete Course Set
	void setDaysToCompleteEachCourse(int daysToCompleteEachCourse[3]);

	// Print specific information about the student
	void print();

};

