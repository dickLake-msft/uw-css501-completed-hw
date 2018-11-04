/*
 * Risa Chan
 * October 2nd, 2018
 * CSS501 HW1: Operator Overloading
 * Object Design: Sandwich
 *
 * This is the header file of Sandwich class. Each Sandwich contains a # of ham, cheese, and lettuce.
 * You can make a sandwich, display the info of the sandwich, set the number of each ingredient to
 * put in the sandwich, find out how much of each ingredient is in the sandwich, add two sandwiches,
 * compound one sandwich to another, and compare two sandwiches if they are equal or not equal to each other.
 * At the end, the sandwiches will all be eaten.
 *
 * sandwich.h
 */

#ifndef SANDWICH_H_
#define SANDWICH_H_

#include <iostream>

using namespace std;

class Sandwich
{

public:

	//Constructors and Destructor
	Sandwich();
	Sandwich(int ham, int cheese, int lettuce);
	~Sandwich();

	//to display info of the sandwich
	void info();

	//to compare two sandwiches and see if they are equal in # of ham, cheese, and lettuce
	void compare(Sandwich s2);

	//Getters
	int getHam() const;
	int getCheese() const;
	int getLettuce() const;

	//Setters
	void setHam(int ham);
	void setCheese(int cheese);
	void setLettuce(int lettuce);

	//Operator overloads
	Sandwich operator+(const Sandwich &s) const;
	Sandwich& operator+=(const Sandwich &s);
	bool operator==(const Sandwich &s) const;

	//Sandwich ingredients: These are kept private, can only access by getters
private:
	int numHam;
	int numCheese;
	int numLettuce;

};

#endif /* SANDWICH_H_ */
