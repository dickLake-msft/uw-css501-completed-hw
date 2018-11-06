/**
 * Linked List header file
 * HW2
 * @Author: Roger Robertson Jr.
 */
#include "Node.h"

class LinkedList {

    public:
    LinkedList();
    LinkedList(int theData);
    ~LinkedList();
    void add(int newData);
    bool find(int theData);
    bool remove(int theData);
    LinkedList radixSort();
    LinkedList selectionSort();
    int size();
    void print();
    LinkedList ascendingSort();
    LinkedList descendingSort();


    private:
    Node* head;
    Node* tail;
    void remove(Node* theNode);
    Node* findMin();
};