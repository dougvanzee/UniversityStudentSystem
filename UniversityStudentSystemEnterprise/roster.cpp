#include "roster.h"
#include <iostream>
#include <ios>
#include <iomanip>

Roster::Roster()
{

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	classRosterArray.push_back(new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram));
}

void Roster::remove(string studentID)
{
	bool bStudentIdFound = false;

	// Find student ID in Vector
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		if (classRosterArray.at(i)->getStudentId() == studentID)
		{
			// If found, delete student and break from loop
			classRosterArray.erase(classRosterArray.begin() + i);
			bStudentIdFound = true;
			break;
		}
	}

	// Output message
	if (bStudentIdFound)
	{
		// Output success message
		cout << "Student successfully removed from roster." << endl;
	}
	else
	{
		// Output error message
		cout << "Error: Student ID was not located in roster." << endl;
	}

	// Additional newline for spacing
	cout << endl;
}

void Roster::printAll()
{
	// Print each student's information
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		classRosterArray.at(i)->print();
	}

	// Add extra newline for spacing
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	int studentIndex = -1; // Student index that was found

	// Find student ID in Vector
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		if (classRosterArray.at(i)->getStudentId() == studentID)
		{
			// If found, delete student and break from loop
			classRosterArray.erase(classRosterArray.begin() + i);
			studentIndex = i;
			break;
		}
	}

	// If student found, output average days in course. Else output error message.
	if (studentIndex != -1)
	{
		int* daysToCompleteEachCourse = classRosterArray.at(studentIndex)->getDaysToCompleteEachCourse();

		int totalDaysInCourses = daysToCompleteEachCourse[0] + daysToCompleteEachCourse[1] + daysToCompleteEachCourse[2];
		double averageDays = static_cast<double>(totalDaysInCourses) / 3.0;

		cout << setprecision(2) << "The student's average number of days in each course is: " << averageDays << endl;
	}
	else
	{
		// Output error message
		cout << "Error: Student ID was not located in roster." << endl;
	}
}

void Roster::printInvalidEmails()
{

}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	// Find each student with degree program and print their info
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		if (classRosterArray.at(i)->getDegreeProgram() == degreeProgram)
		{
			// If found, print student's info
			classRosterArray.at(i)->print();
		}
	}

	// Add extra newline for spacing
	cout << endl;
}
