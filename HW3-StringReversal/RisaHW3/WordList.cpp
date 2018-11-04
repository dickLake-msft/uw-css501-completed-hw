/* Risa Chan
 * HW 3
 * October 18, 2018
 *
 * WordList.cpp
 */

#include <iostream>
using namespace std;

#include "WordList.h"

//constructs an empty Word List
WordList::WordList() {
	this-> head = NULL;
}

//copy constructor:Big-O: O(N)
WordList::WordList(const WordList &list) {
	this-> head = NULL;  //O(1)
	Node* p = list.head; //O(1)
	while (p != NULL) { //O(N)
		add(p); //O(1)
		p = p->next; //O(1)
	}
	cout << "Copy Constructor Completed!" << endl; //O(1)
}

//Destructor
WordList::~WordList() {
	clear();
}

//adds a node to the word list
void WordList::add(const Node* node) {
	Node * p = new Node(node->word);
	if (head == NULL) {
		head = p;
	}
	else {
		Node * p2 = head;
		while (p2-> next != NULL) {
			p2 = p2->next;
		}
		p2->next = p;
	}
}


//prints the list in reverse order by using recursion. Big-O: O(N)
void WordList::rReversePrint(Node* head) {

	if (head != NULL) { //O(1)
		rReversePrint(head->next); //O(N)
		cout << head-> word << endl; // O(1)
	}
}

//prints the list in reverse order by iteration: Big-O: O(N^2)
void WordList::iReversePrint(Node* head) {
	Node* p = head; //O(1)
	int count = 0; //O(1)
	//finds out the size of the linked list
	while (p != NULL) { //O(N)
		count++; //O(1)
		p = p->next; //O(1)
	}
	p = head; //O(1)
	int index = count; //O(1)

	//O(N^2)
	for (int i = 1; i <= count; i++) { //O(N)
		for (int j = 1; j < index; j++) { //O(N)
			p = p-> next; //O(1)
		}
		cout << p->word << endl; //O(1)
		p = head; //O(1)
		index--; //O(1)
	}
}

//prints the list
void WordList::print() {
	Node* p = head;
	while (p != NULL) {
		cout << p->word << endl;
		p = p->next;
	}
}

//clears the list
void WordList::clear() {
	Node* p = head;
	Node* orig = head;
	while (p != NULL) {
		orig = p;
		p = p->next;
		delete orig;
	}
}
