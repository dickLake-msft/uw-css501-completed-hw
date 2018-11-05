/*
** Roger Robertson Jr.
** HW3 (Workspace)
** File description:
** Singly Linked List
*/


#ifndef LINKEDLIST_H_
	#define LINKEDLIST_H_
    #include <string>
    #include "Node.h"
    using namespace std;
    class LinkedList {

        public:
        LinkedList();
        LinkedList(const LinkedList &otherList);
        ~LinkedList();
        void add(string word);
        void print();
        Node* getHead();
        void reversePrintI();
        void reversePrintR(Node* head);

        private: 
        Node* head;
        void add(Node* node);
        int count();
        


    };


#endif /* !LINKEDLIST_H_ */
