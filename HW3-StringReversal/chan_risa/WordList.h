/* Risa Chan
 * HW 3
 *
 * October 18, 2018
 * WordList.h
*/

#ifndef WORDLIST_H_
#define WORDLIST_H_

#include "Node.h"

class WordList {
public:
	Node* head;

	WordList();
	WordList(const WordList &list);
	~WordList();
	void add (const Node* node);
	void rReversePrint(Node* head);
	void iReversePrint(Node* head);
	void print();
	void clear();
};

#endif /* WORDLIST_H_ */
