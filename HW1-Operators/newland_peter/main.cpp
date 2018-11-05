/* 
 * File:   main.cpp
 * Author: PNewland
 * Driver for HW1
 * Created on October 4, 2018, 7:29 PM
 */

#include <cstdlib>
#include <iostream>
#include "Note.h"
using namespace std;

int main(int argc, char** argv) {
    //create a new note with default pitch and velocity
    Note first;
    cout<<"---"<<endl;
    
    //create another new note with a given pitch and velocity
    Note second(5,6);
    cout<<"---"<<endl;
    
    //get the note some value above or below one of the notes with + int
    Note third = first+8;
    cout<<"third note:[p="<<third.getPitch()<<",v="<<third.getVelocity()<<"]"<<endl;
    cout<<"---"<<endl;
    
    //add notes together with +
    third = first+second;
    cout<<"third note:[p="<<third.getPitch()<<",v="<<third.getVelocity()<<"]"<<endl;
    cout<<"---"<<endl;
    third = second +8;
    cout<<"third note:[p="<<third.getPitch()<<",v="<<third.getVelocity()<<"]"<<endl;
    cout<<"---"<<endl;
    
    //increase value of a note with +=
    first+=5;
    cout<<"first note:[p="<<first.getPitch()<<",v="<<first.getVelocity()<<"]"<<endl;
    cout<<"---"<<endl;
    
    //compare notes
    cout<<"first==second?"<<(first==second)<<endl;
    cout<<"third!=first?"<<(third!=first)<<endl;
    cout<<"---"<<endl;
    
 
}

