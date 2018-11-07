/*
HW4: CompressedString class

@author: Eric Schmidt
@version: 2018-10-25

*/
#ifndef COMPRESSED_STRING_H
#define COMPRESSED_STRING_H

#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

class CompressedString {
    friend ostream& operator<<(ostream &output,
        const CompressedString &compressedString);
public:
    CompressedString(string str);
    ~CompressedString();
    int size();
private:
    vector<char>* compressedStr;
    void compress(vector<char> &str);
    string decompress() const;
    void print();
};
#endif