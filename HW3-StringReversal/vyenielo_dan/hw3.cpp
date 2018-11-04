/*
The following is a solution to homework 3 string reversal for CSS501  at UWB. 
This program implements a forward linked list (fll) of links. A link is 
composed of a data string and a link pointer to the next node. Two invariants 
are maintained; 1) an empty list's head pointer is a nullptr, and 2) a 
non-empty list has a tail node whose next member is a nullptr. The driver, 
below, implements two print functions. print_iter(...) prints a link list's 
nodes iteratively. The second print function print_recur(...) prints a linked 
list's nodes recursively. A copy constructor is implemented for fll objects. 
BigO analysises are conducted in the comments for print_iter(...), 
print_recur(....), and the fll copy constructor (fll::fll(...)). 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include <iostream>
#include <string>
#include "fll.h"

/*
Big O Analysis :: print_iter()
1 initialize ptr
+ 
1 initialize node_count
+
N ptr checks
+
N node_count increments
+
N ptr increments
+
1 i initialization
+
N i checks
+
N ptr inctements
+
N*N j initialization
+
N*N j checks
+
N*N ptr increments
+
N*N j increments
+
N prints
+
N i decrements

== O(1 + 1 + N + N + N + 1 + N + N + N*N + N*N + N*N + N*N + N + N)
== O(3 + 7N + 4N^2)
== O(N^2)

print_iter(...) is O(N^2) where N is the number of links in the list.
*/
void print_iter(const fll& values) {
	link* ptr = values.front();
	int node_count = 0;
	while (ptr) {
		node_count++;
		ptr = ptr->next;
	}
	for (int i = node_count - 1; i >= 0; i--) {
		ptr = values.front();
		for (int j = 0; j < i; j++) {
			ptr = ptr->next;
		}
		std::cout << ptr->data << std::endl;
	}
}

/*
Big O Analysis print_recur(...)
N if checks
+
N print_recur calls
+
N prints

== O(3N) == O(N)

print_recur(...) is O(N) where N is the number of links in the list.
*/
void print_recur(const fll& values, link* root) {
	if (!root) {
		return;
	}
	print_recur(values, root->next);
	std::cout << root->data << std::endl;
}

int main()
{
	fll prompt;
	std::string words[12] = { "Strong", "minds", "discuss", "ideas,", 
		"average", "minds", "discuss", "events,", "weak", "minds", "discuss", 
		"people" };
	for (std::string word : words) {
		prompt.push_back(word);
	}
	std::cout << "print_iter(prompt.front());" << std::endl;
	print_iter(prompt);
	std::cout << std::endl;

	std::cout << "print_recur(prompt.front());" << std::endl;
	//print_recur(prompt.front());
	print_recur(prompt, prompt.front());
	std::cout << std::endl;

	std::cout << "fll copy(prompt);" << std::endl;
	fll copy(prompt);
	std::cout << "print_recur(copy.front());" << std::endl;
	//print_recur(copy.front());
	print_recur(copy, copy.front());
	std::cout << std::endl;
}
