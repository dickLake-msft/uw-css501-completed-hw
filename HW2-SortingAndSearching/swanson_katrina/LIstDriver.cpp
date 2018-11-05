//-------------------------------------------------------------------------------------------------
// Filename: ListDriver.cpp
// Title: CSS 501 Homework 2 - Sorting and Searching
// Programmer: Katrina Swanson
// Date Completed: 10/14/2018
// Description: This .cpp file contains a driver for the List class (and by extension, the 
//		Customer class). 
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0 (must use g++ -std=c++11). 
//-------------------------------------------------------------------------------------------------
#include "Customer.h"
#include "List.h"
#include <iostream>
#include <string>
#define LIST_SIZE 10
using namespace std;

//Function prototype
void clearBuffer();

//-------------------------------------------------------------------------------------------------
// Function: main()
// Description: Allows the user to store customer information in a list. 
// Calls:	void clearBuffer()
//-------------------------------------------------------------------------------------------------
int main()
{
	List myList;
	cout << "Enter data for " << LIST_SIZE << " customers." << endl;

	//Loop until the list is filled
	for (int i = 0; i < LIST_SIZE; i++)
	{
		//Add a customer to the list
		Customer theCustomer;
		string name = "";
		int id_number = 0;

		cout << "Enter customer name: ";
		cin >> name;
		theCustomer.setName(name);
		
		bool success; 
		do {
			//if you give this a huge number it will just set it to int_max and move on
			cout << "Enter customer ID number (nonnegative int): ";
			cin >> id_number;
			success = theCustomer.setCustomerNumber(id_number);
			clearBuffer();
			cin.get();
		} while (!success);
		
		myList.push_back(theCustomer);
	}
	cout << endl;

	cout << "The ascending-sorted list is: " << endl;
	myList.sortAscending();
	myList.print(cout);
	cout << endl;

	cout << "The descending-sorted list is: " << endl;
	myList.sortDescending();
	myList.print(cout);
	cout << endl;

	int searchKey;
	Customer foundCustomer;

	cout << "Enter an ID number to search for: ";
	cin >> searchKey;
	bool found = myList.searchList(searchKey, foundCustomer);
	if (found)
	{
		cout << "That customer ID belongs to at least on customer in the list." << endl;
		cout << "The first customer with ID number " << searchKey 
			<< " is " << foundCustomer.getName();
	}
	else 
	{
		cout << "That customer ID is not in the list yet.";
	}

	cin.get();
	cin.get();
	return 0;
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