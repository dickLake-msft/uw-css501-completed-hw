/* Risa Chan
 * HW 3
 * October 18, 2018
 *
 * Node.cpp
 */


#include "Node.h"

//constructor implementation for node
Node::Node() {
	this-> next = NULL;
}

Node::Node(string word) {
	this->word = word;
	this->next = NULL;
}

