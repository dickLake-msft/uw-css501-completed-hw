/*
The following is a solution to HW0 titled Hello World for CSS501 at the
University of Washington Bothell (UWB). 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
//#include "pch.h"
#include <iostream>
#include <limits>
#include <cmath>

namespace dvnlo {	//my namespace, Dan Vyenielo
	/*
	Returns power of a base rased to exponent (base ^ exponent). Exponent
	arguments involving non-integer powers are not supported. Mirrors edge
	cases return values provided by std::pow().
	https://en.cppreference.com/w/cpp/numeric/math/pow
	https://en.cppreference.com/w/cpp/types/numeric_limits/infinity
	*/
	double pow(const double base, const int exponent) {
		if (base == 0) {
			if (exponent == 0)
				return 1;
			if (exponent < 0)
				//return +inf for double from <limits> 
				return std::numeric_limits<double>::infinity();
		}
		double power = 1;
		if (exponent >= 1) {
			for (int i = 0; i < exponent; i++) {
				power *= base;
			}
		}
		else if (exponent <= -1) {
			for (int i = 0; i > exponent; i--) {
				power /= base;
			}
		}
		return power;
	}
}

void welcome_prompt();
void base_prompt();
void exponent_prompt();

template <typename T>
T get_input(T in_type);

void invalid_input();
void result_prompt(const double base, const int power, const double res);
void exit_prompt();
void test();

/*
I wish to see further integration of technology into aspects of the political
system. Many governmental instirutions are chaired by individuals who
collaborate with industry personal to facilitate favorable economic
environments for their friends and collegues. I believe these conflicts of
interest undermine our constitution, in some cases amount to corruption, and,
at worst, treason. Integration of technology to promote greater transparency
in the political system will facilitate a more accountable republic, for the
people.
*/
int main()
{
	welcome_prompt();
	base_prompt();
	double base = 0;
	base = get_input(base);
	int exponent = 0;
	while (base != 0)
	{
		exponent_prompt();
		exponent = get_input(exponent);
		result_prompt(base, exponent, dvnlo::pow(base, exponent));
		base_prompt();
		base = get_input(base);
	}
	exit_prompt();
	//test();
}

void welcome_prompt() {
	std::cout << "------------------------------------------------------" 
		<< std::endl;
	std::cout << "Welcome to the power calculator. To begin, calculation" 
		<< std::endl;
	std::cout << "please provide a base and exponent. To exit, enter " 
		<< std::endl;
	std::cout << "base 0." << std::endl;
	std::cout << "------------------------------------------------------" 
		<< std::endl;
}

void base_prompt() {
	std::cout << "Provide a base (0 to exit): \n" << "> ";
}

void exponent_prompt() {
	std::cout << "Provide an integer exponent: \n" << "> ";
}

/*
Returns console input when std::cin successfully reads into in_type. If 
unsuccessful: invalid_input_prompt() is displayed, the std::cin error flags 
are cleared, and the remaining stream's input is ignored.
https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
*/
template <typename T>
T get_input(T in_type) {
	while (!(std::cin >> in_type)) {
		invalid_input();
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return in_type;
}

void invalid_input() {
	std::cout << "Invalid input. Provide a numerical base or integer exponent.\n> ";
}

void result_prompt(const double base, const int exponent, const double res) {
	std::cout << base << " ^ " << exponent << " == " << res << std::endl;
}

void exit_prompt() {
	char response;
	std::cout << "Are you sure (n to return)?\n";
	std::cin >> response;
	if (response == 'n' || response == 'N') {
		main();
	}
}


//a test function to guage accuracy of dvnlo::pow() compared to std::pow().
void test() {
	int lower_limit = -10;
	int upper_limit = 10;
	for (int i = lower_limit; i < upper_limit; i++) {
		for (int j = lower_limit; j < upper_limit; j++) {
			double my_pow = dvnlo::pow(i, j);
			double std_pow = std::pow(i, j);
			if (std::abs(my_pow - std_pow) > 0.0000000001) {
				std::cout << i << ' ' << j << ' ' << my_pow << ' ' << std_pow 
					<< std::endl;
			}
		}
	}
}
