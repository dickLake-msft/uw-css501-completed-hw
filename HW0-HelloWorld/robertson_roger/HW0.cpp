/*
 * I want to see a free, open internet that respects the privacy of individuals!
 *
 *  Created on: Sep 27, 2018
 *      Author: Roger Robertson Jr.
 */
#include <iostream>
using namespace std;

int main() {

	int base;
	int power;
	double result = 0;

	while (base != 0) {

		// Get user input from console
		cout << "Welcome to the Personal Power Program!" << endl;
		cout << "Please enter an integer as a base number (or 0 to exit):";
		cin >> base;
		// Exit condition
		if (base == 0) {
			cout << "Goodbye." << endl;
			return 0;
		}
		cout << endl;
		cout << "Now enter an integer for the power:";
		cin >> power;
		cout << endl;

		// If power is negative
		if (power < 0) {
			int denom = base;
			while (power != -1) {
				denom *= base;
				power++;
			}
			result = 1.0 / denom;

		}
		// If power is 0
		else if (power == 0) {
			result = 1;
		}
		// If power is 1
		else if (power == 1) {
			result = base;
		}
		// If power is positive
		else {
			result = base;
			while (power != 1) {
				result *= base;
				power--;
			}

		}
			cout << "Result: " << result << endl;
			result = 0;
	}

	return 0;

}
