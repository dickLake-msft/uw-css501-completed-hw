/*
HW4: Driver for CompressedString class

@author: Eric Schmidt
@version: 2018-10-25

*/
#include "Driver.h"

void Driver::testCompressedString() {
    cout << "Start CompressedString class tests" << endl;

    cout << "It creates an instance of the CompressedString class... " << endl;
    string testStr1 = "aaabbbbcddd";
    cout << "Original string: " << testStr1 << endl;
    CompressedString comStr1(testStr1);
    assert(comStr1.size() == 7);
    cout << "PASS" << endl;

    cout << "It outputs the decompressed string to cout... " << endl;
    ostringstream stream;
    stream << comStr1;
    cout << stream.str() << endl;
    assert(stream.str().size() == testStr1.size());
    cout << "PASS" << endl;

    cout << "It 'compresses' a short string with no repeated chars..." << endl;
    string testStr2 = "xyz";
    CompressedString comStr2(testStr2);
    assert(comStr2.size() == 3);
    ostringstream stream2;
    stream2 << comStr2;
    cout << stream2.str() << endl;
    assert(stream2.str().size() == testStr2.size());
    cout << "PASS" << endl;

    cout << "It compresses a really long string... " << endl;
    string testStr3 = "aaaaadddddeeeeffwwwwazwww";
    CompressedString comStr3(testStr3);
    assert(comStr3.size() == 14);
    ostringstream stream3;
    stream3 << comStr3;
    cout << stream3.str() << endl;
    assert(stream3.str().size() == testStr3.size());
    cout << "PASS" << endl;
}

int Driver::main() {
    cout << "Start HW4 tests" << endl;
    cout << endl;
    testCompressedString();
    cout << endl;
    cout << "All tests complete" << endl;
    return 0;
}