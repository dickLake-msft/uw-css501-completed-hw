/*Risa Chan
 * HW 3
 * October 18, 2018
 *
 * Node.h
 * Each node contains a word and a pointer to next node
 */

#ifndef NODE_H_
#define NODE_H_

#include <stdio.h>
#include <iostream>

using namespace std;

class Node {
public:
	string word;
	Node* next;

	Node();
	Node(string word);

};

#endif /* NODE_H_ */
