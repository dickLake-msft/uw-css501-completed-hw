//-------------------------------------------------------------------------------------------------
// Filename: Customer.cpp
// Title: CSS 501 Homework 2 - Sorting and Searching
// Programmer: Katrina Swanson
// Date Completed: 10/14/2018
// Description: This .cpp file contains the implementation of the Customer class.
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0.
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include "Customer.h"
using namespace std;

//-------------------------------------------------------------------------------------------------
// Class: Customer
// Method: Customer() - default constructor
// Description: assigns default values to a new Customer object - "" (empty string) to the name
//		property, and 0 to the customer number property
//-------------------------------------------------------------------------------------------------
Customer::Customer()
{
	//Assigns default values
	name = "";
	customerNumber = 0;
}

//-------------------------------------------------------------------------------------------------
// Class: Customer
// Method: Customer(string nm, int num) - custom constructor
// Parameters: 
//		string nm - Customer name to set
//		int num - Customer number to set
// Description: assigns given values to a Customer object - nm to name, num to customerNumber.
//-------------------------------------------------------------------------------------------------
Customer::Customer(string nm, int num)
{
	//Assigns values passed to constructor
	name = nm;
	customerNumber = num;
}

//-------------------------------------------------------------------------------------------------
// Class: Customer
// Method: bool setName(string nm)
// Parameters:
//		string nm - Customer name to set
// Description: Mutator for name property of Customer objects. Assigns string value to name 
//		property provided string is not empty. Returns bool indicating whether or not assignment
//		was successful.
//-------------------------------------------------------------------------------------------------
bool Customer::setName(string nm)
{
	bool success = false;
	//Cannot assign name to be an empty string
	if (nm != "")
	{
		name = nm;
		success = true;
	}
	return success;
}

//-------------------------------------------------------------------------------------------------
// Class: Customer
// Method: bool setCustomerNumber(int num)
// Parameters:
//		int num - Customer number to set
// Description: Mutator for customer number property of Customer objects. Assigns int value to 
//		customer number property provided int is positive. Returns bool indicating whether or not 
//		assignment was successful.
//-------------------------------------------------------------------------------------------------
bool Customer::setCustomerNumber(int num)
{
	bool success = false;
	//Customer number must be set to a positive int
	if (num > 0)
	{
		customerNumber = num;
		success = true;
	}
	return success;
}