/*
 * Risa Chan
 * CSS501A HW0: Hello World
 * September 27, 2018
 *
 * This program prompts the user for an integer base (may be negative or positive)
 * and an integer power (may be negative, 0, or positive) and calculates
 * the result of the base number raised to that power. This program assumes only
 * integer entry.
 */

#include <iostream>
using namespace std;

//This function calculates the result of a base raised to a positive power
int posPower (int baseNum, int exponent) {
	int resultPP = 1;
	for (int i= 1; i <= exponent; i++) {
		resultPP *= baseNum;
	}
	return resultPP;
}

/* I'd like to see technology help us communicate with foreigners in foreign languages
 * without either party having to learn the other language!
 */

int main() {
	int base;
	int power;

	while (base != 0) { //continues to prompt user to enter integers

	//prompts user for a base number
		cout << "Please enter a base integer (Enter 0 to quit): ";
		cin >> base;

		if (base == 0)  {    //ends the program
			break;
		}

		//prompts user for a power
		cout << "Please enter a power integer: ";
		cin >> power;

		//case 1: if power = 0, result is always 1
		if (power == 0) {
			cout << 1 << endl;
		}

		//case 2: if power = 1, result is always the base integer
		if (power == 1) {
			cout << base << endl;
		}

		//case 3: positive powers > 1
		if (power > 1) {
			cout << posPower(base, power) << endl;
		}

		//case 4: negative powers
		if (power < 0) {
			cout << (double) 1 / posPower(base, power * -1) << endl;
		}
	}

	cout << "Goodbye! "; //end message

	return 0;

}
