/**
 * Node header file
 * HW2
 * @Author: Roger Robertson Jr.
 */

using namespace std;

class Node {

    public: 
    // Constructors and Destructors
    Node(int newData);
    ~Node();
    //pointers
    Node* next;
    Node* prev;
    int data;
};
