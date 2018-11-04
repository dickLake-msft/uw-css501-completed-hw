//-------------------------------------------------------------------------------------------------
// Filename: HW0_KS.cpp
// Title: CSS 501 Homework 0 - Hello World
// Programmer: Katrina Swanson
// Date Completed: 09/30/2018
// Description: This console program allows a user to calculate a specified base number to a 
//		specified power, within a given range. 
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0.
//-------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------------------
// Functions: 
//		getInput(int* value) - accepts and validates user input from stdin
//		clearBuffer() - clears garbage input from the cin buffer
//		double calculateResult(int base, int exponent) - calculates the result of (base) to 
//			(exponent)
//-------------------------------------------------------------------------------------------------
void getInput(int* value);
void clearBuffer(void);
double calculateResult(int base, int exponent);

//-------------------------------------------------------------------------------------------------
// MIN_INT and MAX_INT have been defined as -100 and 100, respectively, because the outer limits
//		of calculation (ie 100^100, 100^-100, etc) fall safely within the limits represented by
//		DBL_MIN and DBL_MAX for the tested systems, and because 100 is a pleasingly round number :)
//-------------------------------------------------------------------------------------------------
#define MIN_INT -100
#define MAX_INT 100

//-------------------------------------------------------------------------------------------------
// Function: main()
// Calls: getInput(int*), calculateResult(int, int)
// Comments: In the near future, I want to see technology associated with space travel improve. I
//		want to live to see humans send probes or (better yet) colonists to our first exoplanet. 
//		I'm a space nerd. I like space. 
//-------------------------------------------------------------------------------------------------
int main(int argc, const char* argv[]) {
	int userDefinedBase = 0;
	int userDefinedPower = 0;

	cout << "This program allows you to calculate a base number to a specified power." << endl;
	
	while (1) //loop forever
	{
		//get base from user
		cout << "\nEnter an integer base "
			<< "(min " << MIN_INT << ", max " << MAX_INT << ", 0 to quit): ";
		getInput(&userDefinedBase);
		cout << "The base is: " << userDefinedBase << endl;

		//break if user entered 0 to quit
		if (userDefinedBase == 0)
		{ break; }

		//get exponent from user
		cout << "Enter an integer power "
			<< "(min " << MIN_INT << ", max " << MAX_INT << "): ";
		getInput(&userDefinedPower);
		cout << "The exponent is: " << userDefinedPower << endl;

		//calculate and display the result
		cout << "\n" << userDefinedBase << " to the power of " 
			<< userDefinedPower << " is: "
			<< calculateResult(userDefinedBase, userDefinedPower) << endl;
	}

	return 0;
}

//-------------------------------------------------------------------------------------------------
// Function: void getInput(int* value)
// Description: accepts input from user and validates. Reprompts the user until input is good. 
//		Assigns good input to *value.
// Calls: clearBuffer()
//-------------------------------------------------------------------------------------------------
void getInput(int* value)
{
	bool goodInput = false;

	while (!goodInput)
	{	
		if (cin >> (*value) && 
			((*value) >= MIN_INT && (*value) <= MAX_INT))
		{
			goodInput = true;
			clearBuffer();
		}
		else
		{
			clearBuffer();
			cout << "\nI'm sorry, that wasn't a valid entry. "
				<< "Please enter an integer "
				<< "(min " << MIN_INT << " max " << MAX_INT << "): ";
		}
	}
}

//-------------------------------------------------------------------------------------------------
// Function: void clearBuffer()
// Description: clears garbage input out of the cin buffer.
//-------------------------------------------------------------------------------------------------
void clearBuffer()
{
	cin.clear();
	while (cin.peek() != '\n')
	{ cin.ignore(); }
}

//-------------------------------------------------------------------------------------------------
// Function: double calculateResult(int base, int exponent)
// Description: calculates base^exponent. 
//-------------------------------------------------------------------------------------------------
double calculateResult(int base, int exponent)
{
	double inverseBase = 0.0f;
	double calculatedResult = 1.0f;

	//negative nonzero exponents
	if (exponent < 0)
	{
		inverseBase = (1.0 / base);
		for (int counter = 0; counter > exponent; counter--)
		{
			calculatedResult *= inverseBase;
		}
	}

	//positive nonzero exponents
	else if (exponent > 0)
	{
		for (int counter = 0; counter < exponent; counter++)
		{
			calculatedResult *= base;
		}
	}

	//default is exponent of 0, which always gives a result of 1
	return calculatedResult;
}