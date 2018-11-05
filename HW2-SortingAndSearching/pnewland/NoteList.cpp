/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NoteList.cpp
 * Author: PNewland
 * 
 * Created on October 13, 2018, 11:26 AM
 */

#include <iostream>
#include "NoteList.h"
using namespace std;

NoteList::NoteList(){
    this->head=NULL;
    this->tail=NULL;
    this->size=0;
}
NoteList::NoteList(Note aNote){
    NoteNode* nn = new NoteNode; //this is very important
    nn->data = aNote;
    nn->next=NULL;
    nn->prev=NULL;
    //make a new node and point the list at it
    this->head=nn;
    this->tail=nn;
    this->size=1;
}
NoteList::~NoteList(){
    delete head;
    delete tail;
}
void NoteList::pushEndNote(Note aNote){
    NoteNode* nn = new NoteNode; //super crucial to not waste another day
    nn->data = aNote;
    
    nn->next=NULL;
    
    if(size==0){
     nn->prev=NULL;
     this->head=nn;
     this->tail=nn;
     this->size=1;
    }
    else{
    //set the current tail next to the new node
    this->tail->next=nn;
    //set the new node previous to the current tail
    nn->prev=this->tail;
    //now set the tail to the new node and increase the list count
    this->tail=nn;
    this->size++;
    }
    
}

Note NoteList::popNote(){
    Note tempNote = tail->data;
    this->size--;
    if(this->tail!=this->head){
    this->tail=this->tail->prev;
    delete this->tail->next;
    this->tail->next=NULL;
    }
    else{
        this->tail=NULL;
        this->head=NULL;
    }
    return tempNote;
}
Note NoteList::popTopNote(){
    Note tempNote= this->head->data;
    this->size--;
    if(this->head->next!=NULL){
        this->head=this->head->next;
        delete this->head->prev;
        this->head->prev=NULL;
    }else{
        this->tail=NULL;
        this->head=NULL;
    }
    return tempNote;
}
bool NoteList::findNote(Note aNote){
    NoteNode* nn = this->head;
    while(nn->next!=NULL)
    {
        if(nn->data==aNote){
            return true;
        }
        else{
            nn=nn->next;
        }
    }
    if(tail->data==aNote){
        return true;
    }
    return false;
}

NoteList NoteList::sortABub(bool byPitch){
    //make a new one to return so data in this one is preserved
    NoteList* sorted = new NoteList(*this);
    
    if(this->size<=1){
        return *sorted;
    }
    //bubble sort swaps current with next if current larger than next
    //else get next 
    //keep track that if we make a swap, we need to go through the list again
    bool swapped=false;
    //todo refactor this
    int outer=sorted->size;
    for(int i=0; i<outer; i++){
        swapped=false;
        //get the first one
        NoteNode* check1=sorted->head;
        int inner = sorted->size-1;
        if(!byPitch){
            
            for(int j=0; j<inner; j++)
            {
                Note temp1 = check1->data;
                Note temp2 = check1->next->data;
                if(temp1.getVelocity()>temp2.getVelocity()){
                    //need to swap the data
                    check1->next->data=temp1;
                    check1->data=temp2;
                    swapped=true;
                }
                check1=check1->next;
            }
        }
        else{
            for (int j=0; j<inner; j++){
                Note temp1 = check1->data;
                Note temp2 = check1->next->data;
                if(temp1.getPitch()>temp2.getPitch()){
                    //need to swap the data
                    check1->next->data=temp1;
                    check1->data=temp2;
                    swapped=true;
                }
                check1=check1->next;
            }
        }
    }
    
    //need this in copy constructor
    NoteNode* oldList = sorted->head;
    Note temp = oldList->data;
    NoteList* newList = new NoteList(temp);
    for(int i=0; i<(sorted->size-1); i++){
        //already started one so get the next one
        temp = oldList->next->data;
        newList->pushEndNote(temp);
        if(oldList!=tail){
            oldList=oldList->next;
        }       
    }
    
    return *newList;
}

NoteList NoteList::sortDSel(bool byPitch){
    //make a new one to return so data in this one is preserved
    NoteList* sorted2 = new NoteList(*this);
    
    if(this->size<=1){
        return *sorted2;
    }
    
    //selection sort finds the (in this case) maximum value and stores it
    //by swapping it with the first position and increments the next start
    //then repeats looking and storing until the start is at the end
    NoteNode* check1=sorted2->head;
    NoteNode* maxNode=check1;
    
    while(check1->next!=NULL){
        NoteNode* check2=check1->next;
        int maxPitch = check1->data.getPitch();
        int maxVel = check1->data.getVelocity();
        
        while(check2->next!=NULL)
        {
            int checkPitch=check2->data.getPitch();
            int checkVel = check2->data.getVelocity();
            if(byPitch){
                if(checkPitch>maxPitch){
                    maxPitch=checkPitch;
                    maxNode=check2;
                }
            }
            else{
                if(checkVel>maxVel){
                    maxVel=checkVel;
                    maxNode=check2;
                }
            }
            check2 = check2->next;
        }
        Note temp = maxNode->data;
        maxNode->data=check1->data;
        check1->data=temp;
        //cout<<"loop "<<(check1->data.getPitch())<<endl;
        check1=check1->next;
    }
   
    //need this in copy constructor
    NoteNode* oldList = sorted2->head;
    Note temp = oldList->data;
    NoteList* newList = new NoteList(temp);//again this is the important bit
    for(int i=0; i<(sorted2->size-1); i++){
        //already started one so get the next one
        temp = oldList->next->data;
        newList->pushEndNote(temp);
        if(oldList!=tail){
            oldList=oldList->next;
        }       
    }
    
    return *newList;
}

    