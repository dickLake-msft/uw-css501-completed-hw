/* 
 * File:   strList.h
 * Author: PNewland
 *
 * Created on October 17, 2018, 7:25 PM
 */

#ifndef STRLIST_H
#define STRLIST_H

#include <iostream>
#include "strNode.h"

using namespace std;

class strList {
public:
    strList();
    strList(string text);
    virtual ~strList();
    strList(const strList &old);
    
    void addString(string text);
    void revPrintI();//prints the list in reverse order iteratively
    void revPrintR(const strNode* val); //prints the list in reverse order recursively
    void Print();//prints the list from head to tail for testing.
    
    strNode* getFirst() const;
    int getSize() const;
    
private:
     strNode* head;
    int size;
};

#endif /* STRLIST_H */

