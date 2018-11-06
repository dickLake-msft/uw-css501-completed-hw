/**
 * Node class
 * HW2
 * @Author: Roger Robertson Jr.
 */
#include "Node.h"

Node::Node(int newData) {
    data = newData;
    next = nullptr;
    prev = nullptr;
}
Node::~Node() {

}