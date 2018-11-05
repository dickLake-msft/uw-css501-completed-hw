/*
** Roger Robertson Jr.
** HW3 (Workspace)
** File description:
** Node class
*/

#include "Node.h"
#include <string>
#include <iostream>

Node::Node(string word){
   theWord = word;
    next = nullptr;
}

Node::~Node(){
    cout << "Node is destroyed." << endl;
}



string Node::getString() const {
    return theWord;
}
