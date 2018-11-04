/* Risa Chan
 * HW 3
 * October 18, 2018
 *
 * main.cpp
 * Driver
 */
#include <stdio.h>
#include <iostream>

#include "Node.h"
#include "WordList.h"

using namespace std;


int main() {

	WordList* list = new WordList();

	list->add(new Node("Let's"));
	list->add(new Node("have"));
	list->add(new Node("a"));
	list->add(new Node("fun"));
	list->add(new Node("time"));
	list->add(new Node("coding"));
	list->add(new Node("and"));
	list->add(new Node("dancing"));
	list->add(new Node("now!"));
	list->add(new Node("Yay!"));
	list->add(new Node("Haha!"));

	cout << "Printing Original Linked List: " << endl;
	list->print();

	cout << "Reverse printing linked list using recursion: " << endl;
	list->rReversePrint(list->head);

	cout << "Reverse printing linked list using iteration: " << endl;
	list->iReversePrint(list->head);

	cout << "Making a Copy of List: " << endl;
	WordList* list2 = new WordList(*list);
	list2->print();

};
