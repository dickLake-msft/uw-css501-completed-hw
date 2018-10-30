#ifndef DRIVER_H
#define DRIVER_H

#include <cassert>
#include <iostream>

#include "Player.h"
#include "List.h"

class Driver {
public:
    int main();
private:
    void testPlayer();
    void testNode();
    void testList();
    void testListSearch();
    void testListSort();
    static LinkedList* createList();
};

#endif