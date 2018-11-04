#ifndef DELIVERY_MANAGER_H
#define DELIVERY_MANAGER_H

#include <iostream>
#include <string>

#include "Package.h"

using namespace std;

class Node {
public:
    Node (Package* pkg) : package(pkg), next(NULL), prev(NULL) {};
    Node* next;
    Node* prev;
    Package* package;
    ~Node();
};

class DeliveryManager {
    // ADDED SINCE ORIGINAL SUBMISSION
    friend ostream& operator<<(ostream &out,
        const DeliveryManager &dm);
public:
    DeliveryManager();
    DeliveryManager(Package* pkg);

    ~DeliveryManager();
    void add(Package* pkg);
    int search(string desc);
    void sort();
    int getNumPackages() { return this->numPackages; }
    int getNumDrones() { return this->numDrones; }
private:
    Node* head;
    Node* tail;
    int numDrones;
    int numPackages;
    void swap(Node* larger, Node* smaller);
};

#endif