//-------------------------------------------------------------------------------------------------
// Filename: BattleCreatures.cpp
// Title: CSS 501 Homework 1 - Operator Overloading
// Programmer: Katrina Swanson
// Date Completed: 10/06/2018
// Description: This .cpp file contains a driver for the BattleCreatures class. 
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0 (must use g++ -std=c++11). 
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Creatures.h"
using namespace std;

//Function prototypes
void getInput(int* option, int minOption, int maxOption);
void clearBuffer();
void printEquality(bool equal);

//Option bounds
#define COLOR_MIN 0
#define COLOR_MAX 5
#define POWER_MIN 0
#define POWER_MAX 5
#define STRENGTH_MIN 1
#define STRENGTH_MAX 10

//-------------------------------------------------------------------------------------------------
// Function: main()
// Description: Allows the user to make, manage, and manipulate Battle Creatures. Loops the given
//		menu options until 0 to quit is entered. 
// Calls:	void printMenu()
//			void getInput(int*, int, int)
//			void executeInput(int)
//			void printEquality(bool equal)
//-------------------------------------------------------------------------------------------------
int main()
{
	string creatureName = "";
	int creatureColor = -1;
	int creaturePower = -1;
	int creatureStrength = -1;

	cout << "Welcome to BATTLE CREATURES!" << endl << endl;

	//Test the default constructor
	cout << "A new default Battle Creature is being created." << endl;
	cout << "The default creature looks like: " << endl;
	BattleCreature creature1;
	cout << creature1 << endl;

	//Test the explicit (custom) constructor
	cout << "Create a new custom creature. Give it a name: ";
	cin >> creatureName;
	cout << "What color is your creature? Options: " << endl
		<< "0. Red" << endl
		<< "1. Blue" << endl
		<< "2. Yellow" << endl
		<< "3. Green" << endl
		<< "4. Purple" << endl
		<< "5. Orange" << endl;
	cout << "Enter color choice: ";
	getInput(&creatureColor, COLOR_MIN, COLOR_MAX);
	cout << "What kind of power does your creature have? Options: " << endl
		<< "0. Fire" << endl
		<< "1. Water" << endl
		<< "2. Air" << endl
		<< "3. Fighting" << endl
		<< "4. Psychic" << endl
		<< "5. Electric" << endl;
	cout << "Enter power choice: ";
	getInput(&creaturePower, POWER_MIN, POWER_MAX);
	cout << "How strong is your creature? New creatures have strengths from 1-10: ";
	getInput(&creatureStrength, STRENGTH_MIN, STRENGTH_MAX);
	BattleCreature creature2(creatureName, creatureColor, creaturePower, creatureStrength);
	cout << endl;
	cout << "Your new creature is: " << endl << endl << creature2 << endl;

	//Make another creature
	cout << "Create a different creature. Give it a name: ";
	cin >> creatureName;
	cout << "What color is your creature? Options: " << endl
		<< "0. Red" << endl
		<< "1. Blue" << endl
		<< "2. Yellow" << endl
		<< "3. Green" << endl
		<< "4. Purple" << endl
		<< "5. Orange" << endl;
	cout << "Enter color choice: ";
	getInput(&creatureColor, COLOR_MIN, COLOR_MAX);
	cout << "What kind of power does your creature have? Options: " << endl
		<< "0. Fire" << endl
		<< "1. Water" << endl
		<< "2. Air" << endl
		<< "3. Fighting" << endl
		<< "4. Psychic" << endl
		<< "5. Electric" << endl;
	cout << "Enter power choice: ";
	getInput(&creaturePower, POWER_MIN, POWER_MAX);
	cout << "How strong is your creature? New creatures have strengths from 1-10: ";
	getInput(&creatureStrength, STRENGTH_MIN, STRENGTH_MAX);
	BattleCreature creature3(creatureName, creatureColor, creaturePower, creatureStrength);
	cout << endl;
	cout << "Your new creature is: " << endl << endl << creature3 << endl;

	//test the comparison operators
	cout << "Let's compare creatures! Creatures are equal if they have the same strength, "
		<< "color, and power type. " << endl;
	cout << "Comparing the default creature to your first creature: " << endl;
	printEquality(creature1 == creature2);
	cout << endl;

	cout << "Comparing the default creature to your second creature: " << endl;
	printEquality(creature1 == creature3);
	cout << endl;

	cout << "Comparing your first and second creatures to each other: " << endl;
	printEquality(creature2 == creature3);
	cout << endl;

	//test an arithmetic operator by combining creatures
	cout << "Now combining your first and second creatures into a higher-level creature!" << endl;
	cout << "High-level creatures have the combined strengths of both parents, and the" << endl
		<< "color and power type of their strongest parent." << endl << endl;

	//this will call the destructor when the temporary object created by operator+ goes out of scope
	//(but only for Windows. G++ apparently optimizes the copy away. Fascinating). 
	BattleCreature creature4 = creature2 + creature3;

	cout << "The new creature is: " << endl << endl;
	cout << creature4;
	cout << endl;

	//test a compound operator by uncombining a creature
	cout << "Now subtracting a low-level creature from a high-level creature. Creatures " << endl
		<< "retain their powers and colors but their strength and level are adjusted." << endl << endl;

	cout << "Subtracting creature " << creature2.getName() << " from creature " << creature4.getName()
		<< endl << endl;
	cout << "The new lower-level creature is: " << endl << endl;
	creature4 -= creature2;
	cout << creature4 << endl << endl;

	cin.get();
	cin.get();
	return 0;
}

//-------------------------------------------------------------------------------------------------
// Function: void getInput(int*, int, int) 
// Description: sets the option int within a defined range.
// Calls: clearBuffer()
//-------------------------------------------------------------------------------------------------
void getInput(int* option, int minOption, int maxOption)
{
	bool goodInput = false;

	//loop until input is good
	while (!goodInput)
	{
		if (cin >> (*option) &&
			((*option) >= minOption && (*option) <= maxOption))
		{
			goodInput = true;
			clearBuffer();
		}
		else
		{
			clearBuffer();
			cout << "\nI'm sorry, that wasn't a valid entry. "
				<< "Please enter an integer " << minOption << "-" << maxOption << ": ";
		}
	}
}

//-------------------------------------------------------------------------------------------------
// Function: void clearBuffer()
// Description: clears junk out of the cin input buffer
//-------------------------------------------------------------------------------------------------
void clearBuffer()
{
	cin.clear();
	while (cin.peek() != '\n')
	{
		cin.ignore();
	}
}

//-------------------------------------------------------------------------------------------------
// Function: void printEquality(bool equal)
// Description: prints a message describing the in/equality of creatures
//-------------------------------------------------------------------------------------------------
void printEquality(bool equal)
{
	if (equal)
		cout << "These creatures are equal to each other!" << endl;
	else
		cout << "These creatures are not equal to each other." << endl;
}