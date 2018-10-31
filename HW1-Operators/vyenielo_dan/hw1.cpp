/*
The following is a driver for the particle class. Four particle objects are 
instantiated a, b, c, and sum_ab. Particle a is instantiated by default 
construction a(0,0). Particle b is inistantiated by param construction b(1,1).
Parcicle c is instantiated by copy construction from b, c(1,1). operator+(),
operator+=(), and operator==() are verified.
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include <iostream>
#include "particle.h"

int main()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Test object instantiation functions" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	particle a;	
	std::cout << " successful." << std::endl;
	std::cout << "Verify default construction invariant: " << std::endl;
	std::cout << "a == { mass(0 == " << a.get_mass() << ") && volume(0 == " 
		<< a.get_volume() << ") }";
	if (a.get_mass() == 0 && a.get_volume() == 0) {
		std::cout << " successful." << std::endl;
	} else {
		std::cout << " unsuccessful." << std::endl;
	}
	
	std::cout << "---------------------------------------------" << std::endl;
	particle b(1, 1);
	std::cout << " successful." << std::endl;
	std::cout << "Verify param construction: " << std::endl;
	std::cout << "b == { mass(1 == " << b.get_mass() << ") && volume(1 == "
		<< b.get_volume() << ") }";
	if (b.get_mass() == 1 && b.get_volume() == 1) {
		std::cout << " successful." << std::endl;
	}
	else {
		std::cout << " unsuccessful." << std::endl;
	}
	
	std::cout << "---------------------------------------------" << std::endl;
	particle c(b);
	std::cout << " successful." << std::endl;
	std::cout << "c == b" << std::endl;
	
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Assignment, operator=() : a.operator=(b)" << std::endl;
	a.operator=(b);
	std::cout << "Verify operator=() with operator==(): " << std::endl;
	std::cout << "a == b : ";
	if (a == b)	//comparison operator
		std::cout << "True." << std::endl;
	else
		std::cout << "False." << std::endl;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Arithmetic operator: sum = a.operator+(b)" << std::endl;
	particle sum_ab; 
	sum_ab = a.operator+(b);	// arithmetic operator & assignment
	std::cout << "Verify a.operator+(b) : " << std::endl;
	std::cout << "sum_ab = a + b == { mass(2 == " << sum_ab.get_mass() 
		<< ") && volume(2 == " << sum_ab.get_volume() << ") }" << std::endl;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Compound operator: c += a" << std::endl;
	c += a;	//compound operand
	std::cout << "Verify c.operator+=(a) : " << std::endl;
	std::cout << "c += a == { mass(2 == " << c.get_mass()
		<< ") && volume(2 == " << c.get_volume() << ") }" << std::endl;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Destruction (destroy: a, b, c, sum_ab)" << std::endl;
	//note that I do not explicitly call the destructors here
	//I could, with a.~particle(); but if I do, then the compiler attempts
	//to delete these at the end of the scope, and double deletes cause errors.
	//Instead, I print out from ~particle() to show that it is called. See
	//particle.cpp.
}