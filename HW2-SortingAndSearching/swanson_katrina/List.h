#ifndef LIST_H
#define LIST_H
//-------------------------------------------------------------------------------------------------
// Filename: List.h
// Title: CSS 501 Homework 2 - Sorting and Searching
// Programmer: Katrina Swanson
// Date Completed: 10/14/2018
// Description: This .h file contains the definition of the List class.
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0.
//-------------------------------------------------------------------------------------------------
#include <iostream>
#include "Customer.h"
using namespace std;

//-------------------------------------------------------------------------------------------------
// Class: Customer
// Data Members:
//		Node* head
//		Node* tail
//		int size
// Methods:
//		List() - default constructor. Creates an empty List.
//		~List - destructor. Calls pop_back() while List is not empty to deallocate memory.
//		bool push_back(Customer cst) - adds another Customer to the end of the List.
//		Customer pop_back() - pops a node off the back of the List and returns its Customer data.
//		void sortAscending() - sorts the List in order of ascending Customer number
//		void sortDescending() - sorts the List in order of descending Customer number
//		bool searchList(int key) - searches the List for a particular Customer number. Returns a 
//			bool indicating whether that number was found.
//
// Subclass: Node
// Data Members: 
//		Customer m_customer
//		Node* next
//		Node* previous
// Methods: 
//		Node(Customer cst, Node* nxt, Node* prv) - custom constructor. Assigns given values to the
//			Node properties. 
//		~Node() - default destructor
//		bool setCustomer(Customer cs) - sets the Customer property.
//		Customer getCustomer() - accessor for the Customer property. 
//-------------------------------------------------------------------------------------------------
class List {
public:
	//Forward declaration
	class Node;

	//Constructors & destructor
	List() : head(nullptr), tail(nullptr), size(0) {}
	~List() { while (head != nullptr) pop_back(); }

	void push_back(Customer cst);
	Customer pop_back();
	void print(ostream& sout);

	//Acccess
	int getSize() { return size; }

	void sortAscending();
	void sortDescending();
	bool searchList(int key, Customer& cst);

private:
	Node* head;
	Node* tail;
	int size;
	
public:
	//Nested Node class
	class Node {
		
	public:
		//Constructors & destructor
		Node(Customer cst, Node* nxt, Node* prv) :
			m_customer(cst), next(nxt), previous(prv) {}
		~Node() {}

		//Access & mutate
		bool setCustomer(Customer cs)
			{ m_customer = cs; }
		Customer getCustomer() { return m_customer; }
		
		//Data members
		Customer m_customer;
		Node* next;
		Node* previous;
	};
};
#endif // !LIST_H