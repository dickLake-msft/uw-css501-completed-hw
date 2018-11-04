/*
 * Risa Chan
 * October 2nd, 2018
 * CSS501 HW1: Operator Overloading
 * Object Design: Sandwich
 *
 * sandwich.cpp
 */

#include "sandwich.h"
#include <iostream>

using namespace std;

//default constructor
Sandwich :: Sandwich()
{
	numHam = 0;
	numCheese = 0;
	numLettuce = 0;
}

//constructor with parameters
Sandwich :: Sandwich(int ham, int cheese, int lettuce)
{
	//enforce invariants- can't have less than 0 ham, cheese, or lettuce in a sandwich!
	if (ham < 0 || cheese < 0 || lettuce < 0)
	{
		throw "Can't have less than 0 ingredients in a sandwich!";
	}
	numHam = ham;
	numCheese = cheese;
	numLettuce = lettuce;
}

//destructor
Sandwich::~Sandwich()
{
	cout << "Eaten! ";
}

//returns the number of hams in the Sandwich
int Sandwich::getHam() const
{
	return numHam;
}

//returns the number of cheese in the Sandwich
int Sandwich::getCheese() const
{
	return numCheese;
}

//returns the number of Lettuce in the Sandwich
int Sandwich::getLettuce() const
{
	return numLettuce;
}

//sets the number of Ham in the Sandwich
void Sandwich::setHam(int ham)
{
	//enforce invariants- can't have less than 0 hams in a sandwich!
	if (ham < 0)
	{
		throw "Can't have negative ham in a sandwich!";
	}
	numHam = ham;
}

//sets the number of Cheese in the Sandwich
void Sandwich::setCheese(int cheese)
{
	//enforce invariants- can't have less than 0 cheese in a sandwich!
	if (cheese < 0)
	{
		throw "Can't have negative cheese in a sandwich!";
	}
	numCheese = cheese;
}

//sets the number of lettuce in the Sandwich
void Sandwich::setLettuce(int lettuce)
{
	//enforce invariants- can't have less than 0 lettuce in a sandwich!
	if (lettuce < 0)
	{
		throw "Can't have negative lettuce in a sandwich!";
	}
	numLettuce = lettuce;
}

//prints the data for a sandwich including the # of hams, cheese, and lettuce
void Sandwich:: info()
{
	cout << "Hams: " << numHam <<" Cheese: " << numCheese << " Lettuce: " << numLettuce <<endl;
}

//displays result of comparison of two sandwiches on whether they are equal (definition: same # of ham, cheese, and lettuce) or not
void Sandwich::compare(Sandwich s)
{
	if (*this == s)
	{
		cout << "The sandwiches are equal!" << endl;
	}
	else
	{
		cout << "The sandwiches are not equal!" << endl;
	}
}

//operator overload (+) to add two sandwiches
Sandwich Sandwich::operator+(const Sandwich &s) const
{
	Sandwich megaSandwich;
	megaSandwich.numHam = numHam + s.numHam;
	megaSandwich.numCheese = numCheese + s.numCheese;
	megaSandwich.numLettuce = numLettuce + s.numLettuce;
	return megaSandwich;
}

//operator overload (+=) to compound two sandwiches
Sandwich& Sandwich::operator+=(const Sandwich &s)
{
	this->numHam += s.numHam;
	this->numCheese += s.numCheese;
	this->numLettuce += s.numLettuce;
	return *this;
}

//operator overload (==) to compare two sandwiches
bool Sandwich::operator==(const Sandwich &s) const
{
	return ((numHam == s.numHam) && (numCheese==s.numCheese) && (numLettuce==s.numLettuce));
}
