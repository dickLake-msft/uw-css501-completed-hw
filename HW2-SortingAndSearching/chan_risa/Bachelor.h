/* Risa Chan
 * October 11, 2018
 * CSS501 HW2: Searching and Sorting
 *
 * Bachelor.h
 *
 * This is the header file of the bachelor object.
 * Each Bachelor has a name, an attractiveness Score, and
 * a Bachelor pointer to a previous and next Bachelor.
 *
 */

#ifndef BACHELOR_H_
#define BACHELOR_H_

#include <stdio.h>
#include <iostream>

using namespace std;


class Bachelor {
public:
	string name;
	int attractScore;
	Bachelor* next;
	Bachelor* previous;

	Bachelor(string name, int attractScore);
};

#endif /* BACHELOR_H_ */
