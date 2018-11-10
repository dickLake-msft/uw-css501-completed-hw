#ifndef LIST_H_
#define LIST_H_
#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class List
{
private:
	Node<T> * _head;
	int index;
	bool isEmpty() const;
	Node<T> * getPointerTo(int & index) const;
public:
	List();
	~List();
	List(const List<T>& aList);
	bool add(const T& newVal);
	bool contains(const T& valToSearchFor) const;
	int getSize() const;
	Node<T>* getHead() const;
	void print();
	void printReverseRecursive(Node<T> * head);
	void printReverseIterative();
};

/*
	Purpose: Test to see if the list is empty or not
	@param NONE
	@return true/fasle : bool.  Returns 'true' if the list has a value stored.
*/
template<class T>
bool List<T>::isEmpty() const
{
	if (_head == nullptr)
		return true;
	else
		return false;
}

template<class T>
Node<T> * List<T>::getPointerTo(int & index) const
{
	Node<T> * currentPtr = _head;
	for (int i = 0; i < index; i++) {
		currentPtr = currentPtr->_next;
	}
	return currentPtr;
}

/*
	Purpose: Default constructor that initializes the list's head and tail to nulptr
	@param NONE
	@return NONE
*/
template<class T>
List<T>::List() : _head(nullptr) {
	index = 0;
}

/*
	Purpose: Destructor that cleans up any dangling pointers
	@param NONE
	@return NONE
*/
template<class T>
List<T>::~List()
{
	if (!isEmpty()) {
		Node<T> * currentPtr = _head;
		Node<T> * tempPtr;
		while (currentPtr != nullptr)
		{
			tempPtr = currentPtr;
			currentPtr = currentPtr->_next;
			delete tempPtr;
		}
	}
}

//Copy constructor
template<class T>
List<T>::List(const List<T>& aList) {
	std::cout << "Someone called the copy constructor!" << std::endl;
	index = aList.index;
	Node<T>* origChainPtr = aList._head;

	if (origChainPtr == nullptr)
		_head = nullptr;
	else {
		//Copy first Node
		_head = new Node<T>();
		_head->_data = origChainPtr->_data;

		//Copy remaining nodes
		Node<T>* newChainPtr = _head;
		origChainPtr = origChainPtr->_next;
		while (origChainPtr != nullptr) {
			//Get next item from original chain
			T nextItem = origChainPtr->_data;

			//Create a new node containing the next item
			Node<T>* newNodePtr = new Node<T>(nextItem);

			//Link new node to end of new chain
			newChainPtr->_next = newNodePtr;

			//Advance pointers
			newChainPtr = newChainPtr->_next;
			origChainPtr = origChainPtr->_next;
		}
		newChainPtr->_next = nullptr;
	}

}

/*
	Purpose: Add a value of type T to the list
	@param DataType T
	@return true/fasle : bool.  Returns 'true' if the value is stored
*/
template <class T>
bool List<T>::add(const T& newVal) {
	Node<T> *newPtr = new Node<T>(newVal);
	if (isEmpty())
	{
		_head =  newPtr;
		index = 0;
		return true;
	}
	else
	{
		newPtr->_next = _head;
		_head = newPtr;
		index++;
		return true;
	}
	return false;
}

/*
	Purpose: Test to see if the list contains a given value
	@param DataType T
	@return true/fasle : bool.  Returns 'true' if the list has a value that is equal == to the provided value
*/
template<class T>
bool List<T>::contains(const T & valToSearchFor) const
{
	if (isEmpty())
		return false;
	else {
		Node<T> * currentPtr = _head;
		while (currentPtr)
		{
			if (currentPtr->getData() == valToSearchFor)
				return true;
			else {
				currentPtr = currentPtr->getNext();
			}
		}
	}
	return false;
}

/*
	Purpose: Get the size of the list
	@param NONE
	@return index : int.  Returns the value of index.
*/
template<class T>
int List<T>::getSize() const { return index; }

/*
	Purpose: Get the head of the list pre merge
	@param NONE
	@return _head : Node<T>*.  Returns the head of the list
*/
template<class T>
Node<T> * List<T>::getHead() const { return _head; }

/*
	Purpose: Print the list in the current order of the list
	@param head : Node<T> HEAD of the list
	@return VOID.  Prints the list (as is) to cout
*/
template<class T>
void List<T>::print()
{
	//if (isEmpty())
	if (isEmpty())
	{
		std::cout << "List is empty." << std::endl;
	}

	else
	{
		Node<T> * currentPtr = _head;
		while (currentPtr != nullptr) {
			std::cout << currentPtr->_data << " " << std::endl;
			currentPtr = currentPtr->_next;
		}
	}
	std::cout << std::endl;

}

template<class T>
void List<T>::printReverseRecursive(Node<T> * head)
{
	if (head == nullptr)
		return;
	printReverseRecursive(head->_next);
	std::cout << head->_data << std::endl;
}

template<class T>
void List<T>::printReverseIterative()
{
	for (int i = index; i >= 0; i--) {
		std::cout << getPointerTo(i)->_data << std::endl;
	}
}



#endif // !LIST_H_
