/**
 * Driver function for HW2
 * @Author: Roger Robertson Jr.
 */
#include "LinkedList.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList(17);
    //add 10 items
    list->add(25);
    list->add(945);
    list->add(42);
    list->add(9);
    list->add(222);
    list->add(9923);
    list->add(21);
    list->add(453);
    list->add(2343459);
    list->add(923);
    list->add(111);
    cout << "SEARCH FUNCTION" << endl;
    cout << "---------------------" << endl;
    list->find(456);
    list->find(9);
    cout << endl;
    cout << "ORIGINAL LIST" << endl;
    cout << "---------------------" << endl;
    list->print();
    cout << endl;
    cout << "REMOVE FUNCTION" << endl;
    cout << "---------------------" << endl;
    cout << list->remove(42) << endl;
    cout << "New List" << endl;
    cout << "---------------------" << endl;
    list->print();
    cout << endl;
    cout << "SELECTION SORT" << endl;
    cout << "---------------------" << endl;
    LinkedList sortedList = list->selectionSort();
    sortedList.print();
    delete list;
    cout << endl;
    cout << "RADIX SORT" << endl;
    cout << "---------------------" << endl;
    //list->radixSort();
    cout << endl;
    cout << "ASCENDING SORT" << endl;
    cout << "---------------------" << endl;
    sortedList.ascendingSort();
    cout << endl;
    cout << "DESCENDING SORT" << endl;
    cout << "----------------------" << endl;
    sortedList.descendingSort();
    cout << endl;
    cout << "BIG O ANALYSIS:" << endl;
    cout << "Find: O(n)" << endl;
    cout << "Selection Sort: O(n^2)" << endl;
    cout << "Radix Sort: O(kn) supposedly" << endl;
    cout << "Ascending Sort: O(n) or O(n^2) with print function" << endl;
    cout << "Descending Sort: O(n) or O(n^2) with print function" << endl;
    return 0;
}
