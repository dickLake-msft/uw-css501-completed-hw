#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Node {
public:
    Node();
    Node(Player* player);
    ~Node();
    Node* child;
    Node* parent;
    Player* value;
};

enum LinkedListSortDirection {
    Ascending, Descending
};

class LinkedList {
public:
    LinkedList();
    LinkedList(Node* head);
    ~LinkedList();
    string toString(bool isInReverseOrder = false);
    void insert(Player* player);
    void insert(Node* node);
    Node* get(int index);
    Node* remove(int index);
    int getCount();
    int findNumber(int number);
    int findLastName(string lastName);
    void sort(LinkedListSortDirection direction = Ascending);
private:
    Node* head;
    Node* tail;
    int count;
    void sortAscending();
    void sortDescending();
    void moveToFrontAscending(Node* node, Node* start);
    void moveToFrontDescending(Node* node, Node* start);
};



#endif