/* Risa Chan
 * October 11, 2018
 * CSS501 HW2: Searching and Sorting
 *
 * BachelorList.cpp
 *
 * This is the source file of the Bachelor List. A Bachelor List is expected to have a beginning(head)
 * and end(tail) of a list and can add, remove, search, sort (via bubble sort) in ascending or descending
 * order, and print the bachelor lists.
 */

#include <iostream>
using namespace std;

#include "BachelorList.h"

//creates an empty BachelorList, setting head and tail to null
BachelorList::BachelorList() {
	this-> head = NULL;
	this-> tail = NULL;
}

//adds a bachelor into the list
void BachelorList::add(string name, int attractScore) {
	//uses the parameters to create a new bachelor
	Bachelor* bachelor = new Bachelor(name, attractScore);

	//if empty list, make first bachelor the head and tail
	if (head == NULL) {
		head = bachelor;
		tail = bachelor;
	}
	//if list is not empty, add the new bachelor to the end of the list and make new bachelor the tail
	else {
		tail->next = bachelor;
		bachelor->previous = tail;
		tail = bachelor;
	}
}

//removes a particular bachelor from the Bachelor List
void BachelorList::remove(string name) {
	//This pointer will be used to traverse the list
	Bachelor* ptr = head;
	bool found = false;

	//searches until the end of the list
	while (ptr != NULL && found == false) {

		//if the bachelor is found
		if (ptr->name == name) {

			//Case 1- if the bachelor is at the start of the list(is the head)
			if (ptr->previous == NULL) {
				this->head = this->head->next;
				string badBachelor = this->head->previous->name;
				delete this->head->previous;
				this->head->previous = NULL;
				cout << badBachelor << " removed!" << endl;
			}

			//Case 2- if the bachelor is in the middle of the list
			else if (ptr->previous != NULL && ptr->next != NULL) {
				Bachelor* removePtr = ptr; //set deletePtr to bachelor to delete
				string badBachelor = removePtr->name;
				removePtr->next-> previous = removePtr->previous;
				removePtr->previous->next = removePtr->next;
				delete removePtr;
				cout << badBachelor << " removed!" <<endl;
			}

			//Case 3- if the bachelor is at the end of the list (is the tail)
			else if (ptr->next == NULL) {
				this->tail = this->tail->previous;
				string badBachelor = this->tail->next->name;
				delete this->tail->next;
				this->tail->next = NULL;
				cout << badBachelor << " removed!" << endl;
			}
			found = true;
		}

		//bachelor not yet found, so continues to traverse the list
		ptr = ptr->next;
	}
	if (found == false) {
		cout << "Bachelor " << name << " not found. Sorry. " << endl;
	}
}

/*Sorts the list in an ascending order comparing their attractScores using bubble sort
 *
 * Big-O: 2 + 2n * 8n = 2n * 8n = O(N^2)
 */
void BachelorList::ascendingSort() {
	Bachelor* ptr1 = head; //ptr to make sure Bachelor node exists, O(1)
	Bachelor* ptr2 = head; //ptr for transversing the list, O(1)

	while(ptr1 != NULL) { //O(N)
		while (ptr2-> next != NULL) { //O(N)
			if (ptr2->next->attractScore < ptr2->attractScore) { //O(1)
				string tempName = ptr2->name; //O(1)
				int tempScore = ptr2->attractScore; //O(1)
				ptr2->name = ptr2->next->name; //O(1)
				ptr2->attractScore = ptr2->next->attractScore; //O(1)
				ptr2->next->name = tempName; //O(1)
				ptr2->next->attractScore = tempScore; //O(1)
			}
			ptr2 = ptr2->next; //O(1)
		}
		ptr2 = head; //traverse again from the beginning, O(1)
		ptr1 = ptr1->next; //keeps moving till reaches the end of the list, O(1)
	}
}

/*Sorts list in descending order comparing attractScores via bubble sort
 *
 * Big-O: 2 + 2n * 8n = 2n * 8n = O(N^2)
 *
 */
void BachelorList::descendingSort() {
	Bachelor* ptr1 = head; //ptr to make sure Bachelor node exists, O(1)
	Bachelor* ptr2 = head; //ptr for transversing the list, O(1)

	while(ptr1 != NULL) { //O(N)
		while (ptr2-> next != NULL) { //(O(N)
			if (ptr2->next->attractScore > ptr2->attractScore) { //O(1)
				string tempName = ptr2->name; //O(1)
				int tempScore = ptr2->attractScore; //O(1)
				ptr2->name = ptr2->next->name; //O(1)
				ptr2->attractScore = ptr2->next->attractScore; //O(1)
				ptr2->next->name = tempName; //O(1)
				ptr2->next->attractScore = tempScore; //O(1)
			}
			ptr2 = ptr2->next; //O(1)
		}
		ptr2 = head; //traverse again from the beginning , O(1)
		ptr1 = ptr1->next; //keeps moving till reaches the end of the list, O(1)
	}

}

/*searches the list for a particular bachelor and outputs the bachelor's name and attractScore
Big-O: 4 + 5n -> 5n -> O(N)
*/
void BachelorList::search(string name) {
	Bachelor* p = head; //O(1)
	bool found = false; //O(1)
	while (p-> next != NULL) { //O(N)

		//bachelor found in the list
		if (p->name == name) { //O(1)
			cout << name << " Found. Attractiveness Score is: " << p->attractScore << endl; //O(1)
			found = true; //O(1)
			break; //O(1)
		}
			p = p->next; //O(1)
	}

	//bachelor not found in the list
	if (found == false) { //O(1)
		cout << name << " not found. Sorry." << endl; //O(1)
	}
}

//prints the whole Bachelor list
void BachelorList::print() {
	Bachelor* ptr = head;
	while(ptr != NULL) {
		cout << "Bachelor Name: " << ptr->name << " Attractiveness Score: " << ptr-> attractScore << endl;
		ptr = ptr->next;
	}
}

