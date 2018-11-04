/*
 * Risa Chan
 * October 2nd, 2018
 * CSS501 HW1: Operator Overloading
 * Object Design: Sandwich
 *
 * This is the Driver. This creates 6 sandwiches, displays info on the sandwiches, adds two
 * sandwiches together, compounds one sandwich to another, and compares sandwiches, sets a sandwich's
 * ingredients and gets the ingredient quantities, and then the Sandwich objects are destroyed at the end.
 *
 * main.cpp
 */

#include <iostream>
#include "sandwich.h"

using namespace std;

int main()
{

	//Constructing 5 sandwiches
	Sandwich s0;
	Sandwich s1(2,2,2);
	Sandwich s2(3,3,2);
	Sandwich s3(5,2,1);
	Sandwich s4 = s1 + s2;
	Sandwich s5 = s4;

	//Display # of hams, cheese, and lettuce in the sandwiches
	cout << "It's Sandwich Time!" << endl;
	cout << "Sandwich 0: ";
	s0.info();
	cout << "Sandwich 1: ";
	s1.info();
	cout << "Sandwich 2: ";
	s2.info();
	cout << "Sandwich 3: ";
	s3.info();

	//Arithmetic operand (+) of Sandwich 1 and 2 into new Sandwich (s4)
	cout << "Sandwich 1 + 2 = ";
	s4.info();

	//Compound operand (+=) of Sandwich 3 and 1, adding Sandwich 1 into Sandwich 3
	s3 += s1;
	cout << "Sandwich 3 += 1 ";
	s3.info();

	//Comparison operand (==) of Sandwich 1 to Sandwich 2
	cout <<"Sandwich 1: ";
	s1.info();
	cout <<"Sandwich 2: ";
	s2.info();
	cout << "Is Sandwich 1 == Sandwich 2?" << endl;
	s1.compare(s2);

	//Comparison operand (==) of sandwich 4 and 5
	cout <<"Sandwich 4: ";
	s4.info();
	cout <<"Sandwich 5: ";
	s5.info();
	cout << "Is Sandwich 4 == Sandwich 5?" << endl;
	s4.compare(s5);

	//default constructor in Sandwich 0: 0 hams, cheese, and lettuce
	cout <<"Sandwich 0: ";
	s0.info();

	//using the setter functions to set the ham, cheese, and lettuce in Sandwich 0
	cout << "Adding 7 Hams" << endl;
	s0.setHam(7);
	cout << "Adding 7 Cheese" << endl;
	s0.setCheese(7);
	cout << "Adding 7 Lettuce" << endl;
	s0.setLettuce(7);

	//using the getter functions to show the # of ham, cheese, and lettuce after setting
	cout << "Sandwich 0: Hams: " << s0.getHam() << "Cheese: " << s0.getCheese() << "Lettuce: " << s0.getLettuce() << endl;

	//Destructor executed
	cout << "The sandwiches are ...." << endl;

	return 0;
}


