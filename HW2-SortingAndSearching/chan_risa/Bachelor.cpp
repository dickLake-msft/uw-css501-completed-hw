/* Risa Chan
 * October 11, 2018
 * CSS501 HW2: Searching and Sorting
 *
 * Bachelor.cpp
 * This is the source file of the bachelor object.
 * The Bachelor constructor must take two parameters to set his
 * name and attractiveness score. Previous and next pointers are set
 * to null by default until put in the list.
 */


#include "Bachelor.h"

//constructor: creates bachelor & sets the bachelor's name and attractScore
Bachelor:: Bachelor(string name, int attractScore) {
	this-> name = name;
	this-> attractScore = attractScore;
	this-> previous = NULL;
	this-> next = NULL;
}
