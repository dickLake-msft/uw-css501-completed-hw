/**
 * THE ATOM SMASHER
 * @Author: Roger Robertson Jr.
 */

#include "Atom.h"

/** default constructor; creates hydrogen */
Atom::Atom() {
    symbol = "H";
    number = 1;
}
/** overloaded constructor; can create other elements. */
Atom::Atom(string newSymbol, int newNumber) {
    symbol = newSymbol;
    number = newNumber;
}
/**default destructor; still learning what to include here */
Atom::~Atom() {

}
/**get atomic symbol */
string Atom::getSymbol() const{
    return symbol;
}
/**get atomic number */
int Atom::getNumber() const {
    return number;
}
/**set atomic symbol */
void Atom::setSymbol(const string& newSymbol) {
    symbol = newSymbol;
}
/**set atomic number */
void Atom::setNumber(const int& newNumber) {
    number = newNumber;
}
/**overloaded equals; returns true if symbol and number both match */
bool Atom::operator==(const Atom& otherAtom) const {
    if ((symbol == otherAtom.getSymbol()) && number == otherAtom.getNumber()) {
        cout << "These atoms are equal." << endl;
        return true;
    } else {
        cout << "These atoms are not equal." << endl;
        return false;
    }
}
/**overloaded add; can only combine H1 and H1. should return H2 or error message */
Atom Atom::operator+(Atom& otherAtom) {
    if (symbol == "H" && otherAtom.getSymbol() == "H") {
        if (number == 1 && otherAtom.getNumber() == 1) {
            cout << "Atoms combine!" << endl;
            this->setNumber(2);
            delete &otherAtom;
            return *this;
        } else {
            cout << "Too many atoms; cannot combine! Other atom flies off." << endl;
            return *this;
        }
    } else {
        cout << "I can only combine single hydrogen atoms. Your atom remains." << endl;
        return *this;
    }
}
/**overloaded add to sum; combines H2 and H2 to make He4 */
Atom Atom::operator+=(Atom& otherAtom) {
    if (symbol == "H" && otherAtom.getSymbol() == "H") {
        if (number + otherAtom.getNumber() == 4) {
            cout << "*SMASH* You've created helium!" << endl;
            this->setSymbol("He");
            this->setNumber(4);
            delete &otherAtom;
            return *this;
        } else {
            cout << "Must have atomic number totalling 4; use + to add atoms." << endl;
            cout << "Atoms remain uncombined." << endl;
            return *this;
        }
    } else {
        cout << "Atom is too large already! Can only combine hydrogen to create helium!" << endl;
        cout << "Atoms remain uncombined." << endl;
        return *this;
    }   
}
