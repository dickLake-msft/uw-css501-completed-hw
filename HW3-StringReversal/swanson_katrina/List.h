#ifndef LIST_H
#define LIST_H
//-------------------------------------------------------------------------------------------------
// Filename: List.h
// Title: CSS 501 Homework 3 - String Reversal
// Programmer: Katrina Swanson
// Date Completed: 10/18/2018
// Description: This .h file contains the definition of the List class.
//
// Compiles: For Microsoft Visual Studio Enterprise 2017 under Windows 10
//		and g++ under Ubuntu 5.4.0.
//-------------------------------------------------------------------------------------------------
#include <string>
#include <iostream>
using namespace std;

//-------------------------------------------------------------------------------------------------
// Class: List
// Data Members:
//		Node* head
//		int size
// Methods:
//		List() - default constructor. Creates an empty List.
//		~List - destructor. Calls pop() while List is not empty to deallocate memory.
//		void push(string wd) - adds a new Node to the end of the list with the specified word
//		Customer pop() - pops a node off the front of the List and returns its word
//		ostream& reversePrintRecurse(ostream& sout, Node* node2Print) - prints a list, recursively
//		ostream& reversePrintRecurse(ostream& sout, Node* node2Print) - prints a list, iteratively
//		ostream& printAddresses(ostream& sout) - prints a list, complete with node addresses
//		Node* begin() - gets the head of the list
//
// Subclass: Node
// Data Members: 
//		string word
//		Node* next
// Methods: 
//		Node() - default constructor. Creates an empty node.
//		Node(string wd) - custom constructor. Creates a node with a specified word. 
//		~Node() - default destructor
//		void setWord(string wd) - sets the word property of a node
//		string getWord() - gets the word from a node
//		void setNext(Node* nxt) - sets a node's next pointer to a specified node
//		Node* getNext() - gets the next node to this node
//-------------------------------------------------------------------------------------------------
class List {
	//Forward declaration
	class Node;

public:
	List() : head(nullptr), size(0) {}
	List(const List& lt);
	~List() { while (head != nullptr) pop(); }
	
	void push(string wd); //push back
	string pop(); //pop front
	ostream& reversePrintRecurse(ostream& sout, Node* node2print);
	ostream& reversePrintIterate(ostream& sout, Node* node2print);
	ostream& printAddresses(ostream& sout);

	Node* begin() { return head; }

private:
	Node* head;
	int size;

	//Nested node class
	class Node {
	public:
		Node() : word("") {}
		Node(string wd) { 
			next = nullptr;
			word = wd; 
		}
		~Node() {}

		void setWord(string wd) { if (wd != "") word = wd; }
		string getWord() { return word; }
		void setNext(Node* nxt) { next = nxt; }
		Node* getNext() { return next; }

		Node* next;
		string word;
	};
};
#endif // !LIST_H
