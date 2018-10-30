/*
Eric Schmidt
HW0: Hello World
CSS 501, Fall 2018
2018-09-26

I'm interested in applying machine learning to natural language.
For example, I'm curious about sentiment analysis, intent analysis,
speech transcription, synthetic speech; the field of computational
linguistics as a whole.

*/
#include <iostream>

using namespace std;

int calculateExponent(int base, int power);

int main(int argc, const char * argv[]) {

    int base = 1;
    // The maximum size of an integer in C++ is 2147483647.
    // Set arbitrary limits to base and power
    // to prevent going over the maximum int size.
    const int MAXIMUM_POWER = 10;
    const int MAXIMUM_BASE = 8;

    while (base != 0) {

        cout << "Would you like to calculate an exponent?" << endl;
        cout << "Give me a base [Enter '0' to exit]: ";
        cin >> base;

        // Automatically quit the loop if the user enters 0 for the base.
        if (base == 0) {
            break;
        }

        int power;
        cout << "Give me a power: ";
        cin >> power;

        if ((base <= MAXIMUM_BASE) && (power <= MAXIMUM_POWER)) {

            cout << base << " ^ " << power << " = ";

            // If power is negative, convert to positive value
            // for calculation.
            bool isPowerNegative = power < 0;
            if (isPowerNegative) {
                power *= -1;
            }

            int exponentResult = calculateExponent(base, power);

            // For negative powers, return a floating point number.
            if (isPowerNegative) {
                cout << 1.0 / exponentResult << endl;
            } else {
                cout << exponentResult << endl;
            }
        } else {
            cout << "Select a base less than 8 ";
            cout << "and a power less than 10." << endl;
        }
    }
    cout << "Okay, then. Good bye!" << endl;
    return 0;
}

// Calculates an exponential value with the specified base and power.
// Recursive.
int calculateExponent(int base, int power) {
    if (power == 0) {
        return 0;
    } else if (power == 1) {
        return base;
    }
    return base * calculateExponent(base, --power);
}