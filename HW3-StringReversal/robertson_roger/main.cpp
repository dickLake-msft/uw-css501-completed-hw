/*
** Roger Robertson Jr.
** HW3
** File description:
** Driver
*/
#include "Node.h"
#include "LinkedList.h"
#include <iostream>
int main(int argc, char const *argv[]){
    cout << "BUILDING LIST:" << endl << endl;
    LinkedList* list = new LinkedList();
    list->add("hello");
    list->add("world");
    list->add("the");
    list->add("quick");
    list->add("brown");
    list->add("fox");
    list->add("jumped");
    list->add("over");
    list->add("the");
    list->add("lazy");
    list->add("dog");
    list->print();
    cout << endl << "INVARIANT CHECK" << endl;
    list->add("");
    cout << endl;
    cout << "DEEP COPY AND REPRINT:" << endl;
    LinkedList otherList(*list);
    otherList.print();
    delete list;
    cout << "ITERATIVE REVERSE PRINT:" << endl << endl;
    otherList.reversePrintI();
    cout << endl;
    cout << "RECURSIVE REVERSE PRINT:" << endl << endl;
    otherList.reversePrintR(otherList.getHead());

    return 0;
}


