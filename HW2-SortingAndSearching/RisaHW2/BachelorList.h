/* Risa Chan
 * October 11, 2018
 * CSS501 HW2: Searching and Sorting
 *
 * BachelorList.h
 *
 * This is the header file of the Bachelor List. A Bachelor List is expected to have a beginning(head)
 * and end(tail) of a list and can add, remove, search, sort (via bubble sort) in ascending or descending
 * order, and print the bachelor lists.
 */

#ifndef BACHELORLIST_H_
#define BACHELORLIST_H_

#include "Bachelor.h"

class BachelorList {
public:
	Bachelor* head;
	Bachelor* tail;

	BachelorList();
	void add(string name, int attractScore);
	void remove(string name);
	void ascendingSort();
	void descendingSort();
	void search(string name);
	void print();
};

#endif /* BACHELORLIST_H_ */
