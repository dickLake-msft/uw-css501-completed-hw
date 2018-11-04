//-------------------------------------------------------------------------------------------------
// Filename: List.cpp
// Title: CSS 501 Homework 3 - String Reversal
// Programmer: Katrina Swanson
// Date Completed: 10/18/2018
// Description: This .cpp file contains the implementation of the List class.
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0.
//-------------------------------------------------------------------------------------------------
#include "List.h"
#include <string>
#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: List(const List& lt)
// Parameters:
//		const List& lt - reference of list to copy
// Description: Copy constructor. Creates a new list using a reference to an existing one.
// O(n): If this list is already empty, it moves through the original list n number of times, and 
//		calls push, which itself has complexity O(n). This gives a worst-case complexity of O(n^2).
//		If the list is *not* already empty, an additional traversal will be required to empty it, 
//		possibly increasing n, but this is still a complexity of O(n). 
//-------------------------------------------------------------------------------------------------
List::List(const List& lt) : head(nullptr), size(0) {
	//clean out anything that's already in here
	while (head != nullptr)
		pop(); 
	//now copy the old one over
	Node* marker = lt.head;
	while (marker != nullptr) {
		push(marker->word);
		marker = marker->next;
	}
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: void push(string wd)
// Parameters:
//		string wd - word to add to the list
// Description: Pushes a new node containing the specified word to the back of the list.
//-------------------------------------------------------------------------------------------------
void List::push(string wd) {
	Node* newNode = new Node(wd);
	if (size == 0) { //first node in the list
		head = newNode;
	}
	else { //list already had something in it
		Node* marker = head;
		while (marker->getNext() != nullptr)
			marker = marker->getNext();
		marker->setNext(newNode);
	}
	size++;
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: string pop()
// Parameters:
//		n/a
// Description: Pops a node from the front of the list and returns the word that was in it.
//-------------------------------------------------------------------------------------------------
string List::pop() {
	Node* temp = head;
	string theWord = temp->word;

	if (head->next != nullptr) {
		head = head->next;
		delete temp;
		size--;
	}
	else {
		delete head;
		head = nullptr;
		size = 0;
	}
	return theWord;
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: ostream& reversePrintRecurse(ostream& sout, Node* node2print)
// Parameters:
//		ostream& sout - ostream to print to
//		Node* node2Print - node to print (or move on to next from)
// Description: Prints a list from the end recursively
// O(n): The execution of this function performs 1 or 2 actions n number of times, and as such 
//		has a worst-case time complexity of O(n). 
//-------------------------------------------------------------------------------------------------
ostream& List::reversePrintRecurse(ostream& sout, Node* node2print) {
	if (node2print->getNext() != nullptr)
		reversePrintRecurse(sout, node2print->getNext());
	sout << node2print->getWord() << endl;
	return sout;
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: ostream& reversePrintIterate(ostream& sout, Node* node2print)
// Parameters:
//		ostream& sout - ostream to print to
//		Node* node2Print - node to print (or move on to next from)
// Description: Prints a list from the end iteratively
// O(n): This function performs 2 discrete actions, one n-while loop, then one close-to-n while
//		loop inside another close-to-n while loop. I estimate the worst-case time complexity of 
//		this function to be somewhere on the order of n+n^2, which would simplify to O(n^2).
//-------------------------------------------------------------------------------------------------
ostream& List::reversePrintIterate(ostream& sout, Node* node2print) {
	Node* marker = node2print; //assign a pointer to the head
	Node* lastPrinted; //keep track of what you've already printed
	
	//to start with, go find the end of the list
	while (marker->getNext() != nullptr) 
		marker = marker->getNext();

	do {
		sout << marker->getWord() << endl; //print the word
		lastPrinted = marker; //set the lastprinted pointer
		marker = node2print; //move marker back to the head
		while (marker!= lastPrinted && marker->getNext() != lastPrinted)
			marker = marker->getNext();

	} while (marker != lastPrinted); 

	return sout;
}

//-------------------------------------------------------------------------------------------------
// Class: List
// Method: ostream& printAddresses(ostream& sout, Node* node2print)
// Parameters:
//		ostream& sout - ostream to print to
//		Node* node2Print - node to print (or move on to next from)
// Description: Prints a list by node, with addresses.
//-------------------------------------------------------------------------------------------------
ostream& List::printAddresses(ostream& sout) {
	Node* marker = head;
	if (size > 0)
	{
		do {
			sout << "Word: " << marker->word << "\t\tAddress: " << marker << endl;
			marker = marker->next;
		} while (marker != nullptr);
	}
	else {
		sout << "Empty list, nothing to print." << endl;
	}
	return sout;
}