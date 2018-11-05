//-------------------------------------------------------------------------------------------------
// Filename: Driver.cpp
// Title: CSS 501 Homework 3 - String Reversal
// Programmer: Katrina Swanson
// Date Completed: 10/18/2018
// Description: This .cpp file contains a driver for the List class.
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0 (g++ must use -std=c++11).
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "List.h"
#define LIST_SIZE 10
using namespace std;

//-------------------------------------------------------------------------------------------------
// Function: main()
// Description: Allows the user to store strings in a list, then prints the lists for examination.
//-------------------------------------------------------------------------------------------------
int main() {
	List myList;
	cout << "Enter " << LIST_SIZE << " strings." << endl << endl;

	//Loop until the list is filled
	for (int i = 0; i < LIST_SIZE; i++)
	{
		cout << "Enter string " << i + 1 << ": ";
		string temp = "";
		cin >> temp;
		myList.push(temp);
	}
	
	cout << "Printing the list in reverse order (recursively): " << endl;
	myList.reversePrintRecurse(cout, myList.begin());
	cout << endl;

	cout << "Printing the list in reverse order (iteratively): " << endl;
	myList.reversePrintIterate(cout, myList.begin());
	cout << endl;

	cout << "Now creating a copy of the list. The original list looks like: " << endl;
	myList.printAddresses(cout);
	cout << endl;
	
	List copyList(myList);

	cout << "The copied list looks like: " << endl;
	copyList.printAddresses(cout);
	cout << endl;

	cin.get();
	cin.get();
	return 0;
}