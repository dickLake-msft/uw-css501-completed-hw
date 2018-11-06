/**
 * THE ATOM SMASHER
 * @Author: Roger Roberton Jr
 * 
 */

#ifndef ATOM_
#define ATOM_
#include <string>
#include <iostream>
using namespace std;

class Atom {

private:
  string symbol;
  int number;

public:
  // default constructor
  Atom();

  //overloaded constructor
  Atom(string newSymbol, int newNumber);

  // overloaded equals
  bool operator==(const Atom& otherAtom) const;

  // overloaded add
  Atom operator+(Atom& otherAtom) ;

  //overloaded add to sum
  Atom operator+=(Atom& otherAtom);

  //Getters & Setters
  string getSymbol() const;

  int getNumber() const;

  void setSymbol(const string& newSymbol);

  void setNumber(const int& newNumber);

  // destructor
  ~Atom();


};
#endif
