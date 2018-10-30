/*
# Big-O Analysis

LinkedList.findNumber() and LinkedList.findLastName()
both have a worst-case runtime complexity of O(n), where
`n` is the number of items in the linked list. Both methods
search the list item by item, starting from the head node.

LinkedList.sortAscending() has a worst-case runtime complexity of
O(n^2) because it uses the insertion sort algorithm. With insertion
sort, you iterate over each item in the list and within each iteration,
you may need to iterate over each item in the list in reverse.

LinkedList.sortDescending() also uses the insertion sort algorithm, and
so thus also has a runtime complexity of O(n^2).

*/
#include "List.h"

Node::Node() {
    this->value = NULL;
    this->child = NULL;
    this->parent = NULL;
}

Node::Node(Player* player) {
    this->value = player;
    this->child = NULL;
    this->parent = NULL;
}

Node::~Node() {
}

LinkedList::LinkedList() {
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

LinkedList::LinkedList(Node* node) {
    this->head = node;
    this->tail = node;
    this->count = 1;
}

LinkedList::~LinkedList() {
}

void LinkedList::insert(Player* player) {
    Node* node = new Node(player);
    insert(node);
}

void LinkedList::insert(Node* node) {
    if (this->head == NULL) {
        this->head = node;
        this->tail = node;
        return;
    }

    node->parent = this->tail;
    this->tail->child = node;
    this->tail = node;
    this->count++;
}

int LinkedList::getCount() {
    return this->count;
}

Node* LinkedList::get(int index) {
    if (!this->head) return NULL;

    // Return NULL if the requested index is
    // outside of the bounds of the list.
    if (index >= this->count) return NULL;

    Node* current = this->head;
    int count = 0;
    while (current && count < index) {
        current = current->child;
        count++;
    }

    return current;
}

Node* LinkedList::remove(int index) {
    if (!this->head) return NULL;

    // Return NULL if the requested index is
    // outside of the bounds of the list.
    if (index >= this->count) return NULL;

    Node* nodeToRemove = this->get(index);
    Node* parent = nodeToRemove->parent;
    Node* child = nodeToRemove->child;

    // Case 1: Node has both parent & child
    if (parent && child) {
        parent->child = child;
        child->parent = parent;

    // Case 2: Node is the head (no parent)
    } else if (!parent) {
        child->parent = NULL;
        this->head = child;

    // Case 3: Node is the tail (no child)
    } else {
        parent->child = NULL;
        this->tail = parent;
    }

    this->count--;
    return nodeToRemove;
}

int LinkedList::findNumber(int number) {
    if (!this->head) return -1;

    Node* current = this->head;
    int count = 0;
    while(current) {
        if (current->value->getNumber() == number) {
            return count;
        }
        current = current->child;
        count++;
    }
    return -1;
}

int LinkedList::findLastName(string lastName) {
    if (!this->head) return -1;

    Node* current = this->head;
    int count = 0;
    while(current) {
        if (current->value->getLastName().find(lastName) != string::npos) {
            return count;
        }
        current = current->child;
        count++;
    }
    return -1;
}

void LinkedList::sort(LinkedListSortDirection direction) {
    if (direction == Ascending) {
        sortAscending();
    } else {
        sortDescending();
    }
}

void LinkedList::sortAscending() {
    if (!this->head) return;

    Node* current = this->head;
    Node* tmp;
    while (current && current->child) {
        if (*current->value > *current->child->value) {
            tmp = new Node(current->child->value);
            current->child = current->child->child;
            if (current->child) {
                current->child->parent = current;
            } else {
                // Current is now the tail node.
                this->tail = current;
            }
            moveToFrontAscending(tmp, current);
        } else {
            current = current->child;
        }
    }
}

void LinkedList::moveToFrontAscending(Node* node, Node* start) {

    Node* current = start;
    while (current->parent
           && *current->parent->value >= *node->value) {
        current = current->parent;
    }

    // Case 1: Front of the list; insert a new head node.
    if (!current->parent) {
        this->head->parent = node;
        node->child = this->head;
        this->head = node;
    // Case 2: Found the insertion point; splice in the node.
    } else {
        node->child = current;
        node->parent = current->parent;
        node->parent->child = node;
        node->child->parent = node;
    }
}

void LinkedList::sortDescending() {
    if (!this->head) return;

    Node* current = this->head;
    Node* tmp;
    while (current && current->child) {
        if (*current->value < *current->child->value) {
            tmp = new Node(current->child->value);
            current->child = current->child->child;
            if (current->child) {
                current->child->parent = current;
            } else {
                // Current is now the tail node
                this->tail = current;
            }
            moveToFrontDescending(tmp, current);
        } else {
            current = current->child;
        }
    }
}

void LinkedList::moveToFrontDescending(Node* node, Node* start) {

    Node* current = start;
    while (current->parent
           && *current->parent->value <= *node->value) {
        current = current->parent;
    }

    // Case 1: Front of the list; insert a new head node.
    if (!current->parent) {
        this->head->parent = node;
        node->child = this->head;
        this->head = node;
    // Case 2: Found the insertion point; splice in the node.
    } else {
        node->child = current;
        node->parent = current->parent;
        node->parent->child = node;
        node->child->parent = node;
    }
}

string LinkedList::toString(bool isInReverseOrder) {
    if (!this->head) {
        return "Empty";
    }

    string output = "";
    Node* current = isInReverseOrder ? this->tail : this->head;
    while(current) {
        output += current->value->toString() + "\n";
        current = isInReverseOrder ? current->parent : current->child;
    }
    return output;
}