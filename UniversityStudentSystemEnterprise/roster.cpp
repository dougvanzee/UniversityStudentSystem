#include "roster.h"
#include <iostream>
#include <ios>
#include <iomanip>

Roster::Roster()
{

}

Roster::~Roster()
{
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		delete classRosterArray[i];
	}
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

	if (bStudentIdFound)
	{
		// Output success message
		cout << "Student with ID '" << studentID << "' successfully removed from roster." << endl;
	}
	else
	{
		// Output error message
		cout << "Error: Student with ID '" << studentID << "' was not located in roster." << endl;
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
	// Student index that was found
	int studentIndex = -1; 

	// Find student ID in Vector
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		if (classRosterArray.at(i)->getStudentId() == studentID)
		{
			// If found, delete student and break from loop
			// classRosterArray.erase(classRosterArray.begin() + i);
			studentIndex = i;
			break;
		}
	}

	// If student found, output average days in course. Else output error message.
	if (studentIndex != -1)
	{
		// Get days in courses
		int* daysToCompleteEachCourse = classRosterArray.at(studentIndex)->getDaysToCompleteEachCourse();

		// Add all days
		int totalDaysInCourses = daysToCompleteEachCourse[0] + daysToCompleteEachCourse[1] + daysToCompleteEachCourse[2];

		// Average days
		double averageDays = static_cast<double>(totalDaysInCourses) / 3.0;

		// Output average
		cout << setprecision(2) << studentID << "'s average days in course: " << averageDays << endl;
	}
	else
	{
		// Output error message
		cout << "Error: Student ID was not located in roster." << endl;
	}
}

void Roster::printInvalidEmails()
{
	// Whether any invalid emails were outputted.
	bool bOutputtedInvalidEmail = false; 

	// Prints invalid email header
	cout << "Invalid Emails:" << endl;

	// Loop through each student
	for (int i = 0; i < classRosterArray.size(); i++)
	{
		// Gets student email address
		string emailAddress = classRosterArray.at(i)->getEmailAddress(); 
		// Whether this students email is valid
		bool bCorrectFormat = true; 

		// Get index of @, if it exists
		int atSymbolIndex = emailAddress.find('@');

		// If @ index has no position or if space found, correct format is false
		if (atSymbolIndex == string::npos  || emailAddress.find(' ') != string::npos)
		{
			bCorrectFormat = false;
		}
		else
		{
			// substring after the @ symbol
			string subString = emailAddress.substr(atSymbolIndex); 

			// If substring doesn't have a period, it is incorrectly formatted
			if (subString.find('.') == string::npos)
			{
				bCorrectFormat = false;
			}
		}
		
		// Output email if invalid
		if (!bCorrectFormat)
		{
			bOutputtedInvalidEmail = true;
			cout << emailAddress << endl;
		}
	}

	// Output message if all emails correct
	if (!bOutputtedInvalidEmail)
	{
		cout << "No invalid emails found." << endl;
	}

	// Add extra newline for spacing
	cout << endl;
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
