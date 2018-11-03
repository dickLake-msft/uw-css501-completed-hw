/*
# Big-O Analysis

The copy constructor, List(const List &original),
has a worst-case time complexity of O(n), where
`n` is the number of items in the original list. The
constructor touches each item in the list once to
create the copy list.

It has a space complexity of O(1), since it does not
call any methods recursively.

The iterative reverse print, List.reversePrintI(),
has a worst-case time complexity of O(n^2). It uses
a for loop to access each element in the list and, for
each iteration, it iterates over each item from the front
of the list to the item being printed.

Iterative reverse print has a constant space complexity,
O(1), because it doesn't call any methods recursively.

The recurse reverse print, List.reversePrintR(), has
a worst-case time complexity of O(n). It recursively
touches each item in the list, but does not contain
any inner loop.

The recursive reverse print has a space complexity of
O(n), because it calls itself once for each item in the
list.
*/
#include "List.h"

Node::Node(string _word) {
    this->word = _word;
    this->next = NULL;
}

Node::~Node() {
    if (this->next) {
        delete this->next;
    }
}

string Node::getWord() {
    return this->word;
}

void Node::setNext(Node* node) {
    this->next = node;
}

Node* Node::getNext() {
    return this->next;
}

List::List() : head(NULL), count(0) {
}

List::List(const List &original) : head(NULL), count(0) {
    if (!original.head) return;

    Node* current = original.head;
    while (current) {
        Node* nextNode = new Node(current->getWord());
        this->add(nextNode);
        current = current->getNext();
    }
}

List::~List() {
    if (this->head) {
        delete this->head;
    }
}

void List::add(Node* node) {
    this->count++;
    if (!this->head) {
        this->head = node;
        return;
    }

    Node* current = this->head;
    while(current->getNext()) {
        current = current->getNext();
    }

    current->setNext(node);
    return;
}

int List::getCount() {
    return this->count;
}

// Gets the Node at the specified index using iteration.
// NOTE: this has a time complexity of O(n).
Node* List::getAt(int index) {
    if (!this->head) return NULL;

    // Keep the caller from going beyond the list.
    if (index >= this->count) return NULL;

    // No negative indices.
    if (index < 0) return NULL;

    Node* current = this->head;
    int i = 0;

    // This should work since we check that we already
    // checked that we're not going beyond the list.
    while (i < index) {
        current = current->getNext();
        i++;
    }
    return current;
}

Node* List::remove(int index) {
    if (!this->head) return NULL;

    if (index >= this->count) return NULL;

    if (index < 0) return NULL;

    Node* current = this->head;
    int c = 0;

    // Traverse the list to the parent
    // of the node to remove.
    while (c < index - 1) {
        current = current->getNext();
        c++;
    }

    Node* removed = current->getNext();
    current->setNext(removed->getNext());
    this->count--;
    return removed;
}

void List::reversePrintI() {
    for (int i = this->count - 1; i >= 0; i--) {
        cout << this->getAt(i)->getWord() << endl;
    }
}

void List::reversePrintR() {
    if (this->head) {
        this->_reversePrintR(this->head);
    }
}

void List::_reversePrintR(Node* current) {
    if (current->getNext()) {
        this->_reversePrintR(current->getNext());
    }
    cout << current->getWord() << endl;
}

string List::toString() const {
    string output = "";
    if (!this->head) {
        return "Empty list";
    }

    Node* current = this->head;
    while (current) {
        output += current->getWord() + "\n";
        current = current->getNext();
    }

    return output;
}

ostream& operator<<(ostream &outStream, const List &list)
{
    outStream << list.toString();
    return outStream;
}