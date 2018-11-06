/**
 * Linked List
 * HW2
 * @Author: Roger Robertson Jr.
 */
#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

LinkedList::LinkedList(int theData) {
    Node* newNode = new Node(theData);
    this->head = newNode;
    this->tail = newNode;
}

LinkedList::~LinkedList() {

}


// add at end of list
void LinkedList::add(int newData) {
    Node* newNode = new Node(newData);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

// find data in list
bool LinkedList::find(int theData) {
   Node* current = head;
   while (current->next != nullptr) { 
       if (current->data == theData) {
           cout << "FOUND" << endl;
           return true;
       } else {
           current = current->next;
       }
   }
   cout << "NOT FOUND" << endl;
   return false;
}

// remove element from list
bool LinkedList::remove (int theData) {
    Node* current = head;
    while (current->next != nullptr) { 
        if (current->data == theData) {
            if (current->prev == nullptr) {
                head = current->next;
            } else {
            current->prev->next = current->next;
            }
            current->next->prev = current->prev;
            delete current;
            return true;
        } 
        current = current->next;
    }
    return false;
}
// radix sort (hopefully)
LinkedList LinkedList::radixSort() {
    //read linked list into array
    int* listArray = new int[this->size()];
    Node* current = this->head;
    for (int listCount = 0; listCount < this->size(); listCount++) {
        listArray[listCount] = current->data;
        cout << "LIST ITEM: " << listArray[listCount] << endl;
        current = current->next;
    }
    // find max value
    int max = listArray[0];
    for (int maxCount = 0; maxCount < this->size(); maxCount++) {
        if (listArray[maxCount] > max) {
            max = listArray[maxCount];
        }
    }
    cout << "MAX VALUE: " << max << endl;
    // loop for each decimal place
    // include a buffer array for reordering
    int exponent = 1;
    int* buffer = new int[this->size()];
    while (max / exponent > 0) {
        // create a holder to count occurances
        int decimalHolder[10];
        // count occurances
        for (int decimalCount = 0; decimalCount < this->size(); decimalCount++) {
            decimalHolder[listArray[decimalCount] / exponent % 10]++;
        }
        // not sure how to explain this step yet
        for (int orderCount = 0; orderCount < 10; orderCount++) {
            decimalHolder[orderCount] += decimalHolder[orderCount -1];
        }
        // reorder in temp array then overwrite original array
        for (int count = this->size() - 1; count >= 0; count--) {
            buffer[--decimalHolder[listArray[count]/ exponent % 10]] = listArray[count];
        }
        for (int count = 0; count < this->size(); count++) {
            listArray[count] = buffer[count];
        }
        // move exponent up
        exponent *= 10;
    }
    //create result list and add sorted values
    LinkedList* result = new LinkedList(listArray[0]);
    for (int count = 1; count < this->size(); count++) {
        result->add(listArray[count]);
    }
    result->print();
    return *result;
}

// well, radix is hard. try selection sort
LinkedList LinkedList::selectionSort() {
    // find min
    // intialize result with min
    //find new min
    //add to list until empty
    //return result
    LinkedList* og = this;
    LinkedList* result = new LinkedList();
    while (og->size() != 0) {
        result->add(og->findMin()->data);
        og->remove(og->findMin());
    }
    return *result;   
}

// size method
int LinkedList::size() {
    Node* current = head;
    int count = 0;
    if (current->next == nullptr) {
        return count;
    } else {
        while (current->next != nullptr) {
            current = current->next;
            count++;
        }
    }
    return count;
}

//print method
void LinkedList::print() {
    Node* current = head;
    while (current->next != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

// private overload of remove for nodes
void LinkedList::remove(Node *theNode) {
    if (theNode->prev == nullptr) {
        this->head = theNode->next;
        delete theNode;
    } else if (theNode->next == nullptr) {
        this->tail = theNode->prev;
        delete theNode;
    } else {
        theNode->prev->next = theNode->next;
        theNode->next->prev = theNode->prev;
        delete theNode;
    }
}

// ascending sort function
LinkedList LinkedList::ascendingSort() {
    LinkedList* result = new LinkedList();
    Node* current = this->head;
    while (current->next != nullptr) {
        result->add(current->data);
        current = current->next;
    }
    result->print();
    return *result;
}

//descending sort function
LinkedList LinkedList::descendingSort() {
    LinkedList* result = new LinkedList();
    Node* current = this->tail;
    while (current->prev != nullptr) {
        result->add(current->data);
        current = current->prev;
    }
    result->print();
    return *result;
}

Node* LinkedList::findMin() {
    Node* current = head;
    Node* min = current;
    while (current->next != nullptr) {
        if (min->data > current->data) {
            min = current;
        }
        current = current->next;
    }
    return min;
}

