#include "Driver.h"

LinkedList* Driver::createList() {
    Player* player = new Player("Britt", "Justin", 68);
    Player* player2 = new Player("Thomas", "Earl", 29);
    Player* player3 = new Player("Wright", "K. J.", 50);
    Player* player4 = new Player("Baldwin", "Doug", 89);
    Player* player5 = new Player("Wilson", "Russ", 3);
    Player* player6 = new Player("Lockett", "Tyler", 16);
    Player* player7 = new Player("Wagner", "Bobby", 54);
    Player* player8 = new Player("Reed", "Jarran", 90);
    Player* player9 = new Player("Carson", "Chris", 32);
    Player* player10 = new Player("Vannett", "Nick", 81);
    LinkedList* list = new LinkedList();
    list->insert(player);
    list->insert(player2);
    list->insert(player3);
    list->insert(player4);
    list->insert(player5);
    list->insert(player6);
    list->insert(player7);
    list->insert(player8);
    list->insert(player9);
    list->insert(player10);
    return list;
}

void Driver::testPlayer() {
    cout << "Start Player class tests" << endl;

    cout << "It creates a Player instance using a constructor... ";
    Player player;
    Player player2("Sherman", "Richard", 25);
    Player player3("Thomas", "Earl", 29);
    Player player4("Sherman", "Richard (again)", 25);
    Player player5("Wright", "K. J.", 50);
    assert(&player);
    assert(&player2);
    cout << "PASS" << endl;

    cout << "It can get the number of a player instance... ";
    int actual = player2.getNumber();
    assert(actual == 25);
    cout << "PASS" << endl;

    cout << "It can print out the contents of a player instance... " << endl;
    string actualToString = player2.toString();
    cout << actualToString << endl;
    assert(actualToString.find("25") != string::npos);
    assert(actualToString.find("Richard") != string::npos);
    assert(actualToString.find("Sherman") != string::npos);
    cout << "PASS" << endl;

    // Use the players' number to compare values.
    cout << "It can compare player instances using relational operators... ";
    assert(player2 == player2);
    assert(player2 == player4);
    assert(player2 < player3);
    assert(!(player3 < player2));
    assert(player5 > player2);
    assert(!(player2 > player5));
    assert(player2 <= player4);
    assert(player2 <= player5);
    assert(!(player5 <= player2));
    assert(player5 >= player5);
    assert(player5 >= player2);
    assert(!(player2 >= player5));
    cout << "PASS" << endl;
}

void Driver::testNode() {
    cout << "Start Node class tests" << endl;

    Player player("Sherman", "Richard", 25);
    Player player2("Thomas", "Earl", 29);
    Player player3("Wright", "K. J.", 50);

    cout << "It creates a node instance using a constructor...";
    Node node2(&player);
    Node node3(&player2);
    Node node4(&player3);
    assert(&node2);
    assert(&node3);
    assert(&node4);
    cout << "PASS" << endl;

    cout << "It can store references to a parent node and a child node...";
    node3.parent = &node2;
    node3.child = &node4;
    assert(node3.parent->value == &player);
    assert(node3.child->value == &player3);
    cout << "PASS" << endl;

}

void Driver::testList() {
    cout << "Start LinkedList class tests" << endl;

    Player player("Sherman", "Richard", 25);
    Player player2("Thomas", "Earl", 29);
    Player player3("Wright", "K. J.", 50);
    Player player4("Baldwin", "Doug", 89);
    Player player5("Wilson", "Russ", 3);
    Player player6("Lockett", "Tyler", 16);
    Player player7("Wagner", "Bobby", 54);
    Player player8("Carson", "Chris", 32);
    Player player9("Vannett", "Nick", 81);
    Player player10("Reed", "Jarran", 90);
    Node node(&player);
    Node node2(&player2);

    cout << "It creates a list instance using a constructor...";
    LinkedList linkedList(&node);
    assert(&linkedList);
    cout << "PASS" << endl;

    cout << "It can insert new nodes and players..." << endl;
    linkedList.insert(&node2);
    linkedList.insert(&player3);
    linkedList.insert(&player4);
    linkedList.insert(&player5);
    linkedList.insert(&player6);
    linkedList.insert(&player7);
    linkedList.insert(&player8);
    linkedList.insert(&player9);
    linkedList.insert(&player10);
    cout << "Count of items is: " << linkedList.getCount() << endl;
    assert(linkedList.getCount() == 10);
    cout << "PASS" << endl;

    cout << "It can be traversed forward & backward (doubly-linked)..." << endl;
    string forwardPrint = linkedList.toString();
    string backwardPrint = linkedList.toString(true);
    cout << forwardPrint << endl;
    cout << backwardPrint << endl;
    int forwardsPlayer1Pos = forwardPrint.find("Sherman");
    int forwardsPlayer3Pos = forwardPrint.find("Wright");
    assert(forwardsPlayer1Pos < forwardsPlayer3Pos);
    int backwardsPlayer1Pos = backwardPrint.find("Sherman");
    int backwardsPlayer3Pos = backwardPrint.find("Wright");
    assert(backwardsPlayer1Pos > backwardsPlayer3Pos);
    cout << "PASS" << endl;

    cout << "It can access specific nodes in the list..." << endl;
    Node* firstNode = linkedList.get(0); // 25, Sherman
    Node* midNode = linkedList.get(5); // 16, Lockett
    Node* lastNode = linkedList.get(9); // 90, Reed
    cout << "Index #0 is number: ";
    cout << firstNode->value->getNumber() << endl;
    cout << "Index #5 is number: ";
    cout << midNode->value->getNumber() << endl;
    cout << "Index #9 is number: ";
    cout << lastNode->value->getNumber() << endl;
    assert(firstNode->value->getNumber() == 25);
    assert(midNode->value->getNumber() == 16);
    assert(lastNode->value->getNumber() == 90);
    cout << "PASS" << endl;

    cout << "It can remove specific nodes in the list..." << endl;
    Node* firstRemovedNode = linkedList.remove(0); // 25, Sherman
    Node* midRemovedNode = linkedList.remove(4); // 16, Lockett
    Node* lastRemovedNode = linkedList.remove(7); // 90, Reed
    cout << "Count is now: " << linkedList.getCount() << endl;
    cout << "Removed nodes are:" << endl;
    cout << firstRemovedNode->value->toString() << endl;
    cout << midRemovedNode->value->toString() << endl;
    cout << lastRemovedNode->value->toString() << endl;
    cout << "Remaining nodes are:" << endl;
    cout << linkedList.toString() << endl;
    assert(linkedList.getCount() == 7);
    assert(firstRemovedNode->value->toString().find("Sherman") != string::npos);
    assert(midRemovedNode->value->toString().find("Lockett") != string::npos);
    assert(lastRemovedNode->value->toString().find("Reed") != string::npos);
    cout << "PASS" << endl;
}

void Driver::testListSearch() {
    cout << "Start LinkedList class search methods tests" << endl;
    LinkedList* linkedListPtr = createList();
    LinkedList linkedList = *linkedListPtr;

    cout << "It can find a node by player's number..." << endl;
    int actualPlayer1Pos = linkedList.findNumber(50);
    cout << "#50 is at index " << actualPlayer1Pos << endl;
    assert(actualPlayer1Pos == 2);
    cout << "PASS" << endl;

    cout << "It returns -1 if a player's number isn't present..." << endl;
    int actualPlayerNoPos = linkedList.findNumber(76);
    cout << "#3 is at index " << actualPlayerNoPos << endl;
    assert(actualPlayerNoPos == -1);
    cout << "PASS" << endl;

    cout << "It can find a node by a player's last name..." << endl;
    int actualPlayer2Pos = linkedList.findLastName("Thomas");
    cout << "Thomas, Earl is at index " << actualPlayer2Pos << endl;
    assert(actualPlayer2Pos == 1);
    cout << "PASS" << endl;

    cout << "It returns -1 if a player's last name isn't present..." << endl;
    int actualNoPlayerPos = linkedList.findLastName("Chancellor");
    cout << "Chancellor, Kam is at index " << actualNoPlayerPos << endl;
    assert(actualNoPlayerPos == -1);
}

void Driver::testListSort() {
    cout << "Start LinkedList class sort methods tests" << endl;

    LinkedList* linkedListPtr = createList();
    LinkedList linkedList = *linkedListPtr;

    cout << "It sorts players by number in ascending order..." << endl;
    cout << "Before sort: " << endl;
    cout << linkedList.toString() << endl;
    cout << "After sort: " << endl;
    linkedList.sort();
    string actualListString = linkedList.toString();
    cout << actualListString << endl;
    int actualPosPlayer2 = actualListString.find("Wright");
    int actualPosPlayer5 = actualListString.find("Wilson");
    assert(actualPosPlayer2 > actualPosPlayer5);
    cout << "PASS" << endl;

    cout << "It sorts players by number in descending order..." << endl;
    LinkedList* linkedListPtr2 = createList();
    LinkedList linkedList2 = *linkedListPtr2;
    cout << "Before sort: " << endl;
    cout << linkedList2.toString() << endl;
    cout << "After sort: " << endl;
    linkedList2.sort(Descending);
    string actualListString2 = linkedList2.toString();
    cout << actualListString2 << endl;
    actualPosPlayer2 = actualListString2.find("Wright");
    actualPosPlayer5 = actualListString2.find("Wilson");
    assert(actualPosPlayer2 < actualPosPlayer5);
    cout << "PASS" << endl;

}

int Driver::main() {
    cout << "Start HW2 tests" << endl;
    cout << endl;
    testPlayer();
    cout << endl;
    testNode();
    cout << endl;
    testList();
    cout << endl;
    testListSearch();
    cout << endl;
    testListSort();
    cout << "All tests complete" << endl;
    return 0;
}