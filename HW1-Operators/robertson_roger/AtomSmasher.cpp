/**
 * THE ATOM SMASHER
 * @Author: Roger Robertson Jr.
 */
#include "Atom.h"
#include <iostream>

int main () {

cout << "INSTANTIATION AND EQUALITY" << endl;
cout << endl;
Atom* atom1 = new Atom();
Atom* atom2 = new Atom();
cout << "Atom 1 : " + atom1->getSymbol() << " " << atom1->getNumber() << endl;
cout << "Atom 2 : " + atom2->getSymbol() << " " << atom2->getNumber() << endl;
*atom1 == *atom2;
cout << endl;
cout << "ADDITION" << endl;
*atom1 + *atom2;
cout << "Atom 1 : " + atom1->getSymbol() << " " << atom1->getNumber() << endl;
cout << endl;
cout << "ADD TO SUM, AKA ATOM SMASH" << endl;
cout << endl;
Atom* atom3 = new Atom("H", 2);
*atom1 += *atom3;
cout << "Atom 1 : " + atom1->getSymbol() << " " << atom1->getNumber() << endl;
Atom* atom4 = new Atom();
cout << "ERROR MESSAGES FOR + AND +=" << endl;
*atom1 + *atom4;
*atom1 += *atom4;

return 0;
}
