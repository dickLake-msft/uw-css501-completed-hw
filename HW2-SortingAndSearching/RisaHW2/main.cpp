/* Risa Chan
 * October 11, 2018
 * CSS501 HW2: Searching and Sorting
 *
 * main.cpp
 *
 * Driver
 */

#include <stdio.h>
#include <iostream>
#include "Bachelor.h"
#include "BachelorList.h"

using namespace std;


int main() {

	BachelorList* list = new BachelorList();

	list->add("Cooper", 33);
	list->add("Stephen", 100);
	list->add("Daniel", 90);
	list->add("Nathan", 80);
	list->add("Jose", 45);
	list->add("David", 10);
	list->add("Justin", 13);
	list->add("Jordan", 0);
	list->add("Jorge", 82);
	list->add("Michael", 60);
	list->add("Jared", 15);
	list->add("Gangster", 0);
	list->add("Scary Man", 1);
	list->add("Ghost Man", 3);

	cout << "Original list: " << endl;
	list->print();

	cout << "Attempting to Remove a bachelor not in the list!" << endl;
	list->remove("Cow");

	cout << "Attempting to remove bachelor at the start of the list!" << endl;
	list->remove("Cooper");
	list->print();

	cout <<"Attempting to remove bachelor from the middle of the list!" << endl;
	list->remove("Jordan");
	list->print();

	cout <<"Attempting to remove bachelor from the end of the list!" <<endl;
	list->remove("Ghost Man");
	list->print();


	cout << "Ascending Sort Now!" << endl;
	list->ascendingSort();
	cout << "New ascending ordered Bachelor List!" << endl;
	list->print();

	cout << "Descending Sort Now!" << endl;
	list->descendingSort();
	cout << "New descending ordered Bachelor List!" << endl;
	list->print();

	cout << "Searching for Stephen!" << endl;
	list->search("Stephen");

	cout << "Searching for bachelor Yakuza not in the list!" << endl;
	list->search("Yakuza");

	delete list;
};
