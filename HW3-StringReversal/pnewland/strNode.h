/* 
 * File:   strNode.h
 * Author: PNewland
 *
 * Created on October 17, 2018, 7:24 PM
 */

#ifndef STRNODE_H
#define STRNODE_H

#include <cstdlib>
#include <string>
using namespace std;

class strNode {
public:
    strNode* next;
    string data;
};

#endif /* STRNODE_H */

