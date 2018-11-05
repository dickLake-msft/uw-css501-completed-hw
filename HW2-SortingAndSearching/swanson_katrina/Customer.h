#ifndef CUSTOMER_H
#define CUSTOMER_H
//-------------------------------------------------------------------------------------------------
// Filename: Customer.h
// Title: CSS 501 Homework 2 - Sorting and Searching
// Programmer: Katrina Swanson
// Date Completed: 10/14/2018
// Description: This .h file contains the definition of the Customer class.
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0.
//-------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------------------
// Class: Customer
// Data Members:
//		string name
//		int customerNumber
// Methods:
//		Customer() - default constructor
//		Customer(string nm, int num) - custom constructor. Sets name and customer number.
//		~Customer() - destructor
//		string getName() - accessor for name property
//		int getCustomerNumber() - accessor for customer number property
//		bool setName(string nm) - sets the name property. Invariants enforced: cannot assign 
//			name to be empty string
//		bool setCustomerNumber - sets the customer number property. Invariants enforced: can
//			assign only positive ints.
//-------------------------------------------------------------------------------------------------
class Customer {
public:
	//Constructors & destructor
	Customer();
	Customer(string nm, int num);
	~Customer() {}

	//Access & mutate
	string getName() { return name; }
	int getCustomerNumber() { return customerNumber; }
	
	bool setName(string nm);
	bool setCustomerNumber(int num);

private:
	string name;
	int customerNumber;
};

#endif // !CUSTOMER_H