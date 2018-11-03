#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    Node(string _word);
    ~Node();
    string getWord();
    void setNext(Node* node);
    Node* getNext();
private:
    string word;
    Node* next;
};

class List {
    friend ostream& operator<<(ostream &outStream, const List &list);

public:
    List();
    List(const List &original);
    ~List();
    void add(Node* node);
    Node* getAt(int index);
    int getCount();
    Node* remove(int index);
    void reversePrintI();
    void reversePrintR();
    string toString() const;
private:
    void _reversePrintR(Node* current);
    Node* head;
    int count;
};

#endif