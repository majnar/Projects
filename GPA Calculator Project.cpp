#include <stdlib.h>
#include <iostream>

using namespace std;

void display(); // Function declaration
void calculateGPA(); // Calculates & displays GPA
void calculateCGPA(); // Calculates & displays cumulative GPA
void equation(); // Displays Eq

int main()
{
	char input = NULL; // Input for user action

	sub:
	display(); // Display main menu

	cout << "Please Enter Your Choice: ";
	cin >> input;

	input = toupper(input);

	switch (input)
	{
	case 'A':
		calculateGPA();
		break;

	//case 2:
	//	calculateCGPA();
	//	break;

	//case 3:
	//	equation();
	//	break;

	case 'D':
		exit(0);
		break;

	default:
		cout << "Please enter valid input and try again" << endl;
		goto sub;
		break;
	}

	return 0;
}

void display() // Function to display main menu for user to choose what to do
{
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
	cout << "\t" << "Main Menu:" << endl;
	cout << "\t" << "A. Calculate Grade Point Average" << endl;
	cout << "\t" << "B. Calculate Cumulative Grade Point Average" << endl;
	cout << "\t" << "C. Display Method Used to Find Averages" << endl;
	cout << "\t" << "D. Exit Program" << endl << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
}

void calculateGPA() // Function to calculate GPA over the course of 1 semester
{
	int numClasses = 0;
	float creditValue;
	float gradeValue;


	system("cls");

	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
	cout << "\tGPA Calculation:" << endl << endl;

	cout << "\tPlease enter the number of classes you took in the last semester: ";
	cin >> numClasses;
	cout << endl;



	string grades[num];


	for (int i = 0; i < numClasses; i++)
	{

	}
}