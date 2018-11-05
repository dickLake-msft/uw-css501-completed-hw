/* 
 * File:   main.cpp
 * Author: PNewland
 *HW2 for list building, searching, sorting
 * Created on October 13, 2018, 11:07 AM
 */

#include <cstdlib>
#include <iostream>
#include "Note.h"
#include "NoteList.h"

using namespace std;

/*
 * driver to test list creation, population, search, and sort
 */
int main() {
    //make 10 notes
    Note n1(45,66);
    Note n2(23,45);
    Note n3(56,78);
    Note n4(82,1);
    Note n5(98,76);
    Note n6(20,9);
    Note n7(123,82);
    Note n8(21,88);
    Note n9(49,28);
    Note n10(88,33);
    
    //make a list
    NoteList melody1(n6);
    
    //add some notes to the end of the list
    melody1.pushEndNote(n1);
    melody1.pushEndNote(n5);
    melody1.pushEndNote(n3);
    melody1.pushEndNote(n2);
    melody1.pushEndNote(n9);
    melody1.pushEndNote(n8);
    melody1.pushEndNote(n7);
    melody1.pushEndNote(n10);
    melody1.pushEndNote(n4);
    
    //cout<<melody1.size<<endl;
    //print out melody again
   /*
    NoteNode* test=melody1.head;
    for(int i =0; i <(melody1.size); i++){
        Note temp = test->data;
        cout<<"what"<<temp.getPitch()<<endl;
        test=test->next;
    }
    */
   
    //sort by velocity ascending
    NoteList crescendo = melody1.sortABub(false);
    cout<<"The melody sorted by velocity is as follows:"<<endl;
    while(crescendo.size>0){
        //cout<<(crescendo.size)<<endl;
        Note temp= crescendo.popTopNote();
        cout<<"[p:"<<temp.getPitch()<<",v:"<<temp.getVelocity()<<"]"<<endl;
        
    }
    
    
    //sort by pitch descending
    NoteList falling = melody1.sortDSel(true);  
    cout<<"The melody sorted by pitch is as follows:"<<endl;
    while(falling.size>0){
        Note temp= falling.popTopNote();
        cout<<"[p:"<<temp.getPitch()<<",v:"<<temp.getVelocity()<<"]"<<endl;
    }    
    
    
    //find a note
    if(melody1.findNote(Note(49,28))){
        cout<<"found the note"<<endl;
    }
    else{
        cout<<"that note isn't in this melody"<<endl;
    }
    if(melody1.findNote(Note(49,27))){
        cout<<"found the note"<<endl;
    }
    else{
        cout<<"that note isn't in this melody"<<endl;
    }
    if(melody1.findNote(Note(48,28))){
        cout<<"found the note"<<endl;
    }
    else{
        cout<<"that note isn't in this melody"<<endl;
    }
    return 0;
}

