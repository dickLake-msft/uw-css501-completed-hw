/*
HW4: CompressedString class

@author: Eric Schmidt
@version: 2018-10-25

# Big-O Analysis

The the CompressedString.compress() function has
a worst case time complexity of O(n), where n
is the size of the string being compressed. This
is because the function has only a single for loop
that iterates over each character in the string.

Similarly, the CompressedString.decompress() function
has a worst case time complexity of O(n), where
n is the size of the string originally compressed.
The function iterates over each item stored in the
compressedStr vector field stored in the instance.
In a situation where there are no runs of duplicate
characters, the function will iterate once for each
character in the original string.

*/
#include "CompressedString.h"

ostream& operator<<(ostream &outstream,
    const CompressedString &compressedString) {

    outstream << compressedString.decompress();
    return outstream;
}

CompressedString::CompressedString(string str) {
    if (str != "") {
        vector<char> cStr(str.begin(), str.end());
        this->compressedStr = new vector<char>();
        compress(cStr);
    }
}

CompressedString::~CompressedString() {
    if (this->compressedStr) delete this->compressedStr;
}

void CompressedString::compress(vector<char> &str) {
    int originalSize = str.size();
    cout << "Original size: " << originalSize << endl;

    vector<char> temp;
    temp.push_back(str.front());

    for (vector<char>::iterator it = str.begin() + 1; it != str.end(); it++) {
        // Found a match
        if (*it == temp.back()) {
            // Keep track in the temp vector
            temp.push_back(*it);
        // Found a new character
        } else {
            // Dump temp into compressedStr
            if (temp.size() > 1) {
                // Handle case where char counts are more than one digit?
                this->compressedStr->push_back('0' + temp.size());
            }
            this->compressedStr->push_back(temp.back());

            // Clear temp and add new character.
            temp.clear();
            temp.push_back(*it);
        }
    }

    if (temp.size() > 1) {
        this->compressedStr->push_back('0' + temp.size());
    }
    this->compressedStr->push_back(temp.back());
    this->print();
    cout << "Compressed size: " << this->compressedStr->size() << endl;
    double percentage = (0.0 + this->compressedStr->size()) / originalSize;
    cout << "Compression percentage: " << percentage << endl;
}

string CompressedString::decompress() const {
    string output;
    vector<char>::iterator it;
    vector<char> tmp;
    for (it = this->compressedStr->begin();
        it != this->compressedStr->end(); it++) {
        if (isdigit(*it)) {
            tmp.push_back(*it);
        } else {
            int numChar = 1;
            if (tmp.size() > 0) {
                string countStr(tmp.begin(), tmp.end());
                numChar = stoi(countStr);
            }
            for (int i = 0; i < numChar; i++) {
                output += *it;
            }
            tmp.clear();
        }
    }
    return output;
}

int CompressedString::size() {
    return this->compressedStr->size();
}

// For debugging compress() method.
void CompressedString::print() {
    vector<char>::iterator it;
    for (it = this->compressedStr->begin();
        it != this->compressedStr->end(); it++) {
        printf("%c\n", *it);
    }
}