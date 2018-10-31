/*
The following tests functionality of linked list class. Linked list objects 
a, b, c, d, e are instantiated via different construction methods, and 
destroyed with various methods. List a is sorted in ascending order, list b
is sorted in descending order, and object e is initialized with random particle
data then sorted ascending and descending. Output is printed to the console. 
Author: Dan Vyenielo(dvyenielo@gmail.com)
*/
#include <iostream>
#include "particle.h"
#include "linked_list.h"
#include <cstdlib>
#include <time.h>

void print(linked_list& list) {
	std::cout << "{ ";
	for (int i = 0; i < list.size(); i++) {
		std::cout << list.get(i);
	}
	std::cout << "}" << std::endl;
}

void test_ll() {
	const int LIST_LENGTH = 11;
	linked_list a;
	for (int i = 0; i < LIST_LENGTH; i++) {
		a.insert(particle(i + 1, i + 1), i);
	}
	std::cout << "print(a) == ";
	print(a);

	linked_list b;
	for (int i = 0; i < LIST_LENGTH; i++) {
		b.push_front(particle(i + 1, i + 1));
	}
	std::cout << "print(b) == ";
	print(b);

	linked_list c;
	for (int i = 0; i < LIST_LENGTH; i++) {
		c.push_back(particle(i + 1, i + 1));
	}
	std::cout << "print(c) == ";
	print(c);

	std::cout << "a.sort_descending() == ";
	a.sort_descending();
	print(a);
	std::cout << "b.sort_ascending() == ";
	b.sort_ascending();
	print(b);

	particle query(3, 3);
	std::cout << "query == " << query << std::endl;
	std::cout << "a.find_link(query) == " << a.find(query) << std::endl;

	std::cout << "pop_front all of a " << std::endl;
	while (!a.empty()) {
		a.pop_front();
		print(a);
	}

	std::cout << "pop_back all of b " << std::endl;
	while (!b.empty()) {
		b.pop_back();
		print(b);
	}

	std::cout << "linked_list d(c) == ";
	linked_list d(c);
	print(d);

	std::cout << "erase all of c " << std::endl;
	for (int i = 0; i < c.size();) {
		i = c.size() / 2;
		c.erase(i);
		print(c);
	}
	c.erase(0);
	print(c);

	linked_list e;
	srand(time(NULL));
	for (int i = 0; i < LIST_LENGTH; i++) {
		int j = rand() % LIST_LENGTH + 1;
		e.insert(particle(j, j), i);
	}
	std::cout << "print(e) == "; 
	print(e);
	std::cout << "e.sort_descending() == ";
	e.sort_descending();
	print(e);
	std::cout << "e.sort_ascending() == ";
	e.sort_ascending();
	print(e);

	std::cout << "destroy d & e" << std::endl;
}

int main()
{
	test_ll();
    std::cout << "HALT\n"; 
}

/*
Example Program output below:

print(a) == { [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 6 v == 6][m == 7 v == 7][m == 8 v == 8][m == 9 v == 9][m == 10 v == 10][m == 11 v == 11]}
print(b) == { [m == 11 v == 11][m == 10 v == 10][m == 9 v == 9][m == 8 v == 8][m == 7 v == 7][m == 6 v == 6][m == 5 v == 5][m == 4 v == 4][m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
print(c) == { [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 6 v == 6][m == 7 v == 7][m == 8 v == 8][m == 9 v == 9][m == 10 v == 10][m == 11 v == 11]}
a.sort_descending() == { [m == 11 v == 11][m == 10 v == 10][m == 9 v == 9][m == 8 v == 8][m == 7 v == 7][m == 6 v == 6][m == 5 v == 5][m == 4 v == 4][m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
b.sort_ascending() == { [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 6 v == 6][m == 7 v == 7][m == 8 v == 8][m == 9 v == 9][m == 10 v == 10][m == 11 v == 11]}
query == [m == 3 v == 3]
a.find_link(query) == -1
pop_front all of a
{ [m == 10 v == 10][m == 9 v == 9][m == 8 v == 8][m == 7 v == 7][m == 6 v == 6][m == 5 v == 5][m == 4 v == 4][m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
{ [m == 9 v == 9][m == 8 v == 8][m == 7 v == 7][m == 6 v == 6][m == 5 v == 5][m == 4 v == 4][m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
{ [m == 8 v == 8][m == 7 v == 7][m == 6 v == 6][m == 5 v == 5][m == 4 v == 4][m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
{ [m == 7 v == 7][m == 6 v == 6][m == 5 v == 5][m == 4 v == 4][m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
{ [m == 6 v == 6][m == 5 v == 5][m == 4 v == 4][m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
{ [m == 5 v == 5][m == 4 v == 4][m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
{ [m == 4 v == 4][m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
{ [m == 3 v == 3][m == 2 v == 2][m == 1 v == 1]}
{ [m == 2 v == 2][m == 1 v == 1]}
{ [m == 1 v == 1]}
{ }
pop_back all of b
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 6 v == 6][m == 7 v == 7][m == 8 v == 8][m == 9 v == 9][m == 10 v == 10]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 6 v == 6][m == 7 v == 7][m == 8 v == 8][m == 9 v == 9]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 6 v == 6][m == 7 v == 7][m == 8 v == 8]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 6 v == 6][m == 7 v == 7]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 6 v == 6]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3]}
{ [m == 1 v == 1][m == 2 v == 2]}
{ [m == 1 v == 1]}
{ }
linked_list d(c) == { [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 6 v == 6][m == 7 v == 7][m == 8 v == 8][m == 9 v == 9][m == 10 v == 10][m == 11 v == 11]}
erase all of c
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 7 v == 7][m == 8 v == 8][m == 9 v == 9][m == 10 v == 10][m == 11 v == 11]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 5 v == 5][m == 8 v == 8][m == 9 v == 9][m == 10 v == 10][m == 11 v == 11]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 8 v == 8][m == 9 v == 9][m == 10 v == 10][m == 11 v == 11]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 4 v == 4][m == 9 v == 9][m == 10 v == 10][m == 11 v == 11]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 9 v == 9][m == 10 v == 10][m == 11 v == 11]}
{ [m == 1 v == 1][m == 2 v == 2][m == 3 v == 3][m == 10 v == 10][m == 11 v == 11]}
{ [m == 1 v == 1][m == 2 v == 2][m == 10 v == 10][m == 11 v == 11]}
{ [m == 1 v == 1][m == 2 v == 2][m == 11 v == 11]}
{ [m == 1 v == 1][m == 11 v == 11]}
{ [m == 1 v == 1]}
{ }
print(e) == { [m == 11 v == 11][m == 2 v == 2][m == 6 v == 6][m == 1 v == 1][m == 1 v == 1][m == 6 v == 6][m == 9 v == 9][m == 9 v == 9][m == 10 v == 10][m == 10 v == 10][m == 7 v == 7]}
e.sort_descending() == { [m == 11 v == 11][m == 10 v == 10][m == 10 v == 10][m == 9 v == 9][m == 9 v == 9][m == 7 v == 7][m == 6 v == 6][m == 6 v == 6][m == 2 v == 2][m == 1 v == 1][m == 1 v == 1]}
e.sort_ascending() == { [m == 1 v == 1][m == 1 v == 1][m == 2 v == 2][m == 6 v == 6][m == 6 v == 6][m == 7 v == 7][m == 9 v == 9][m == 9 v == 9][m == 10 v == 10][m == 10 v == 10][m == 11 v == 11]}
destroy d & e
HALT

C:\Users\dvyen\Source\Repos\uwb_css_501\hw2_searching_and_sorting\Debug\hw2_searching_and_sorting.exe (process 7632) exited with code 0.
Press any key to close this window . . .

*/