/*
HW4: Driver for CompressedString class

@author: Eric Schmidt
@version: 2018-10-25

*/
#ifndef DRIVER_H
#define DRIVER_H

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

#include "CompressedString.h"

using namespace std;

class Driver {
public:
    Driver() {};
    int main();
private:
    void testCompressedString();
};

#endif