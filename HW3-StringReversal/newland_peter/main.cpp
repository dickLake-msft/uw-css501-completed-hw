/* 
 * File:   main.cpp
 * Author: PNewland
 * HW3 - driver 
 * Created on October 17, 2018, 7:23 PM
 */

#include <cstdlib>
#include "strList.h"

using namespace std;

int main() {
    
    strList qlist;
    qlist.addString(string("this"));
    qlist.addString(string("is"));
    qlist.addString(string("several"));
    qlist.addString(string("strings"));
    qlist.addString(string("to"));
    qlist.addString(string("fill"));
    qlist.addString(string("up"));
    qlist.addString(string("a"));
    qlist.addString(string("list"));
    qlist.addString(string("hooray"));
    
    //print the list from head to tail
    qlist.Print();
    cout<<endl;
    
    //print the first list with the reverse iteration
    qlist.revPrintI();
    cout<<endl;
    
    //make a copy for qlist
    strList zlist = qlist;
    
    //modify qlist to test the copy
     qlist.addString(string("check"));
    
     //print the list from head to tail
    qlist.Print();
    cout<<endl;
     
    //print the copy list with the reverse recursion
    //should be the same result as the previous reverse print
    zlist.revPrintR(zlist.getFirst());
    return 0;
}

