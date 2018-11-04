//-------------------------------------------------------------------------------------------------
// Filename: List.cpp
// Title: CSS 501 Homework 2 - Sorting and Searching
// Programmer: Katrina Swanson
// Date Completed: 10/14/2018
// Description: This .cpp file contains the implementation of the List class.
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0.
//-------------------------------------------------------------------------------------------------
#include "List.h"
#include "Customer.h"
#include <string>
using namespace std;

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: void push_back(Customer cst)
// Parameters:
//		Customer cst - Customer data to add to list
// Description: Takes a customer object and adds it to the list by creating a new node and 
//		storing the customer data in it, then appending the node to the tail of the list. 
//-------------------------------------------------------------------------------------------------
void List::push_back(Customer cst)
{
	Node* node = new Node(cst, nullptr, nullptr);
	
	if (tail != nullptr) //list was not empty
	{
		tail->next = node;
		node->previous = tail;
		tail = node;
	}
	else //list was empty
	{
		head = node;
		tail = node;
	}
	size++;
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: Customer pop_back()
// Description: Extracts the customer data from the last node in a list, deletes that node, and
//		returns the retrieved customer data.
//-------------------------------------------------------------------------------------------------
Customer List::pop_back()
{
	if (tail != nullptr)
	{
		//get tail data and move the tail pointer
		Customer tailData = tail->getCustomer();
		if (head != tail) //more than one element left
		{
			tail = tail->previous;
			delete tail->next;
			tail->next = nullptr;
			size--;
		}
		else //this is the last element
		{
			delete tail;
			head = nullptr;
			tail = nullptr;
			size = 0;
		}
		return tailData;
	}
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: void print(ostream& sout)
// Description: Prints the customer data from each node in a list to an ostream object. 
//-------------------------------------------------------------------------------------------------
void List::print(ostream& sout)
{
	Node* printNode = head;
	sout << "The list contains: " << endl;
	while (printNode != nullptr)
	{
		sout << "Customer name: " << printNode->getCustomer().getName() << endl;
		sout << "Customer ID number: " << printNode->getCustomer().getCustomerNumber() << endl;
		printNode = printNode->next;
	}
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: void sortAscending()
// Description: Sorts customers in a list in order of ascending customer ID number. Implementation
//		of bubble sort.
// This method performs n swaps n times, and as such has worst-case O(n^2) complexity. 
//-------------------------------------------------------------------------------------------------
void List::sortAscending()
{
	Node* currentNode;
	bool swapped;

	if (head != nullptr)
	{
		do {
			//at the beginning of the pass nothing has been moved yet, start at the head
			swapped = false;
			currentNode = head;
			//pass through the list
			while (currentNode->next != nullptr)
			{
				if ((currentNode->getCustomer().getCustomerNumber())
					> (currentNode->next->getCustomer().getCustomerNumber()))
				{
					swapped = true;
					//swap them
					Customer temp = currentNode->m_customer;
					currentNode->m_customer = currentNode->next->m_customer;
					currentNode->next->m_customer = temp;
				}
				currentNode = currentNode->next;
			}
		} while (swapped);
	}
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: void sortDescending()
// Description: Sorts customers in a list in order of descending customer ID number. Implementation
//		of bubble sort.
// This method performs n swaps n times, and as such has worst-case O(n^2) complexity. 
//-------------------------------------------------------------------------------------------------
void List::sortDescending()
{
	Node* currentNode;
	bool swapped;

	if (head != nullptr)
	{
		do {
			//at the beginning of the pass nothing has been moved yet, start at the head
			swapped = false;
			currentNode = head;
			//pass through the list
			while (currentNode->next != nullptr)
			{
				if ((currentNode->getCustomer().getCustomerNumber())
					< (currentNode->next->getCustomer().getCustomerNumber()))
				{
					swapped = true;
					//swap them
					Customer temp = currentNode->m_customer;
					currentNode->m_customer = currentNode->next->m_customer;
					currentNode->next->m_customer = temp;
				}
				currentNode = currentNode->next;
			}
		} while (swapped);
	}
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: bool searchList(int key)
// Description: Searches List for a specified int key (customer number). Returns a bool indicating
//		whether or not the key was found.
// This method moves linearly through the list once, and as such has worst-case O(n) complexity.
//-------------------------------------------------------------------------------------------------
bool List::searchList(int key, Customer& cst)
{
	bool found = false;
	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		int idNumber = currentNode->getCustomer().getCustomerNumber();
		if (idNumber == key)
		{
			cst = currentNode->getCustomer();
			found = true;
			break;
		}
		currentNode = currentNode->next;
	}
	return found;
}