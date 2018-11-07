/*Risa Chan
 * CSS501: HW 4
 * String Compression
 *
 * main.cpp
 */

#include "CompressedString.h"
#include <iostream>
using namespace std;


int main() {
	string s1 = "abc";
	string s2 = "aaaaacceeeeeddde";
	CompressedString* shortString = new CompressedString(s1);
	CompressedString* longString = new CompressedString(s2);

	cout << "Decompressed of short string: " << endl;
	shortString->decompress(shortString->compressed);
	cout << shortString->decompressed << endl;

	cout << "Decompressed of long string: " << endl;
	longString->decompress(longString->compressed);
	cout << longString->decompressed << endl;

}


