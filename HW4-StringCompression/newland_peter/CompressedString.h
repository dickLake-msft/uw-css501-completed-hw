/*
* File:   CompressedString.h
* Author: PNewland
*
* Created on October 25, 2018
*/

#ifndef COMPRESSEDSTRING_H
#define COMPRESSEDSTRING_H

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;


class CompressedString {
  public:
    CompressedString(string input);

    friend ostream& operator<<(ostream &outstr, const CompressedString &store);
    string decompress() const;

  private:
    void compress(const string &pass);


    vector<char> mashed;
};
#endif /* COMPRESSEDSTRING_H */
