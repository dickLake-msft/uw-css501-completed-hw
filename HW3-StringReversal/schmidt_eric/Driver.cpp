#include "Driver.h"

// Returns a pointer to dynamically-allocated memory.
List* Driver::createList() {
    List* myList = new List();
    myList->add(new Node("Sing"));
    myList->add(new Node("about"));
    myList->add(new Node("wrath,"));
    myList->add(new Node("O"));
    myList->add(new Node("Goddess,"));
    myList->add(new Node("the"));
    myList->add(new Node("wrath"));
    myList->add(new Node("of"));
    myList->add(new Node("Peleus'"));
    myList->add(new Node("son,"));
    myList->add(new Node("Achilles"));
    return myList;
}

Driver::Driver() {}

void Driver::testList() {
    cout << "Start List class tests" << endl;
    cout << endl;

    List* list = createList();

    cout << "It adds new nodes in sequential order and ";
    cout << "overrides output stream operator ..." << endl;
    string output = list->toString();
    cout << *list << endl;
    int word1Pos = output.find("Sing");
    int word2Pos = output.find("son");
    assert(word1Pos < word2Pos);
    cout << "PASS" << endl;

    cout << "It can get the node at a specific index... ";
    Node* node3 = list->getAt(2);
    assert(node3->getWord().find("wrath") != string::npos);
    cout << "PASS" << endl;

    cout << "It can remove the node at a specified index... ";
    int originalSize = list->getCount();
    Node* removedNode = list->remove(2);
    assert(removedNode->getWord().find("wrath") != string::npos);
    assert(originalSize - 1 == list->getCount());
    assert(removedNode != list->getAt(2));
    cout << "PASS" << endl;

    delete list;
}

void Driver::testCopyConstructor() {
    cout << "Start copy constructor tests" << endl;
    cout << endl;
    List* list = createList();

    cout << "It creates a copy list with a different memory address... " << endl;
    List* list2 = new List(*list);
    cout << "Original list location: " << list << endl;
    cout << "Copy list location: " << list2 << endl;
    assert(list != list2);
    cout << "PASS" << endl;

    cout << "It creates a copy of the same size... " << endl;
    int size1 = list->getCount();
    int size2 = list2->getCount();
    cout << "Original list size: " << size1 << endl;
    cout << "Copy list size: " << size2 << endl;
    assert(size1 == size2);
    cout << "PASS" << endl;

    cout << "It creates a copy of each node in the original... " << endl;
    for(int i = 0; i < size1; i++) {
        cout << "Node #" << i << endl;
        Node* origNode = list->getAt(i);
        Node* copyNode = list2->getAt(i);
        cout << "\tOriginal location: " << origNode << endl;
        cout << "\tCopy location: " << copyNode << endl;
        cout << "\tOriginal value: " << origNode->getWord()<< endl;
        cout << "\tCopy value: " << copyNode->getWord() << endl;
        assert(origNode != copyNode);
        assert(origNode->getWord().find(copyNode->getWord()) != string::npos);
    }
    cout << "PASS" << endl;

    delete list;
    delete list2;
}

void Driver::testReverseString() {
    cout << "Start string reversal tests" << endl;
    cout << endl;
    List* list = createList();

    cout << "It prints out the words in reverse (iteratively)... " << endl;
    list->reversePrintI();
    cout << "PASS" << endl;

    cout << "It prints out the words in reverse (recursively)... " << endl;
    list->reversePrintR();
    cout << "PASS" << endl;

    delete list;
}

int Driver::main() {
    cout << "Start HW3 tests" << endl;
    cout << endl;
    testList();
    cout << endl;
    testCopyConstructor();
    cout << endl;
    testReverseString();
    cout << endl;
    return 0;
}