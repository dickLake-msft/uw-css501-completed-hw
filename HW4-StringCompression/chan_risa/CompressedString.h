/*Risa Chan
 * CSS501: HW 4
 * String Compression
 *
 * CompressedString.h
 */

#ifndef COMPRESSEDSTRING_H_
#define COMPRESSEDSTRING_H_
#include <iostream>
#include <vector>

using namespace std;

class CompressedString {
public:
	vector<char> compressed;
	string decompressed;
	CompressedString(string s);
	~CompressedString();
	string decompress(vector<char> v);
	friend ostream& operator<<(ostream& o, const CompressedString &c);
};

#endif /* COMPRESSEDSTRING_H_ */
