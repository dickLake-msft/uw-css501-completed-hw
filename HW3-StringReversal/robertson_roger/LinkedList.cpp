/*
** Roger Robertson Jr.
** HW3 (Workspace)
** File description:
** Singly Linked List
*/

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
    head = nullptr;
}

// copy constructor
// Big O: Time - O(n)   Space - O(n)
LinkedList::LinkedList(const LinkedList &otherList) {
    if (otherList.head == nullptr) {
        head = nullptr;
    } else {
        head = new Node(otherList.head->getString());
        Node* listNext;
       listNext = otherList.head->next;
       while (listNext != nullptr) {
           Node* newNode = new Node(listNext->getString());
           add(newNode);
           listNext = listNext->next;
       }
    }
}

LinkedList::~LinkedList(){
    
    cout << "List is destroyed." << endl;
}

Node* LinkedList::getHead() {
    return head;
}

// adds at end of list
// takes a string as input and creates a node
void LinkedList::add(string word) {
    if (word.empty()) {
        cout << "Input cannot be null or empty! Try again." << endl;
    } else {
        Node* newNode = new Node(word);
        Node* current = head;
        if (head == nullptr) {
            head = newNode;
        } else {
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}

// adds at end of list
// takes a node as input
void LinkedList::add(Node* newNode) {
    Node* current = head;
    if (head == nullptr) {
        head = current;
    } else {
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// normal iterative print function
void LinkedList::print() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->getString() << endl;
        current = current->next;
    }
}

// count nodes
int LinkedList::count() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        current = current->next;
        count++;
    }
    return count;
}

// iterative reverse print
// Big O : Time - O(n^2)    Space - O(1)
void LinkedList::reversePrintI() {
    for (int nodeCount = count(); nodeCount > 0; nodeCount--) {
        Node* current = head;
        int step = 1;
        while (step != nodeCount) {
            current = current->next;
            step++;
        }
        cout << current->getString() << endl;
    }

}

// recursive reverse print
// Big O: Time - O(n)   Space - O(n) 
void LinkedList::reversePrintR(Node* node) {
    if (node == nullptr) {
        return;
    } else {
        reversePrintR(node->next);
        cout << node->getString() << endl;
    }
}
