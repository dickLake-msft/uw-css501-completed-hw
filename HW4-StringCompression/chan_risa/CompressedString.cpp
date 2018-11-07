/*Risa Chan
 * CSS501: HW 4
 * String Compression
 *
 * CompressedString.cpp
 */

#include "CompressedString.h"
#include <ctype.h>

/*constructor that takes in a string and compresses it into a vector of chars.
 * Big-O of compression algorithm: O(N)
 */
CompressedString::CompressedString(string s) {
	//turns the string into a char vector
	vector<char>data(s.begin(), s.end()); //O(1)
	int count = 1; //O(1)
	char previous = data.at(0); //O(1)
	for (int i = 1; i < data.size(); i++) { //O(N)

		//if repeat character
		if (previous == data.at(i)) {
			count++;
		}
			else {
				//if more than 1 occurrence of the character, put in count
				if (count != 1) {
				compressed.push_back('0' + count);
				}
				compressed.push_back(previous);
				previous = data.at(i);
				count = 1; //reset for next character
			}
	}
	//for the end
	if (count != 1) { //O(1)
		compressed.push_back('0' + count); //O(1)
	}
	compressed.push_back(previous); //O(1)

	//Stats on how much shorter the "string" is after compression
	cout << "Original string is " <<  data.size() << " characters long. " << endl;
	cout << "Original string is: " << s << endl;
	cout << "Compressed string is " << compressed.size() << " characters long. " << endl;
	cout << "Compressed string (as a vector of chars) is: ";
	for (int i = 0; i < compressed.size(); i++) { //O(N)
		cout << compressed.at(i);
	}
	cout << endl; //O(1)
	int percentage = (1- ((double)compressed.size()/(double)data.size())) * 100; //O(1)
	cout << "String is compressed by " << percentage << "%. " << endl; //O(1)
 }

//Destructor
CompressedString::~CompressedString() {
	cout << "Destroyed";
}

//<< overload that shows the decompressed string
ostream& operator<<(ostream& o, const CompressedString& c) {
	o << c.decompressed;
	return o;
}

/*Takes a compressed vector of chars and decompresses it back into a string
 * Big-O: O(N^2)
 */
string CompressedString::decompress(vector<char> v) {
	string s = ""; //O(1)
	int count = 1; //O(1)
	for (int i = 0 ; i < v.size(); i++) { //O(N)
		//char is a number
		if (isdigit(v.at(i))) { //O(1)
			count = (v.at(i)) - '0'; //O(1)
		}
		//char is a letter
		else {
			for (int j = 0; j < count; j++) { //O(N)
				s+= v.at(i); //O(1)
			}
			count = 1; //O(1)
		}
	}
	decompressed = s; //O(1)
	return s; //O(1)
}
