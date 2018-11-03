#ifndef DRIVER_H
#define DRIVER_H

#include <cassert>
#include <iostream>
#include <string>
#include "List.h"

using namespace std;

class Driver {
public:
    Driver();
    int main();
private:
    List* createList();
    void testList();
    void testCopyConstructor();
    void testReverseString();
};

#endif