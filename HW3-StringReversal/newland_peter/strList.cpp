/* 
 * File:   strList.cpp
 * Author: PNewland
 * HW3
 * Created on October 17, 2018, 7:25 PM
 */

#include "strList.h"

strList::strList() {
    this->head=NULL;
    this->size=0;
}

strList::strList(string text) {
    this->addString(text);
}

strList::~strList() {
    delete head;
}
//copy constructor
//this is BigO(n) as we have to go through the old list once to build the new
strList::strList(const strList &old){
    //iterator for old list
    strNode* oldTemp=old.head;
    
    //start new list
    head = new strNode();
    head->data = oldTemp->data;
    size = old.size;
    head->next=NULL;
    //iterator for new list
    strNode* newTemp = head;
    
    for(int i=0; i<size-1; i++){
        //if(oldTemp->next !=NULL){
            oldTemp=oldTemp->next;
            strNode* newstr = new strNode();
            newstr->data = oldTemp ->data;
            newstr->next = NULL;
            newTemp->next = newstr;
            newTemp = newTemp->next;
        //}
    }
 
}


int strList::getSize() const{
    return this->size;
}

strNode* strList::getFirst() const{
    return this->head;
}

//this is BigO(n) as we have to iterate through the list every time we add a string
void strList::addString(string text){
    strNode* newstr = new strNode();
    if(this->size==0){
        newstr->data=text;
        newstr->next=NULL;
        this->head = newstr;
        this->size=1;  
    }
    else{
        strNode* add = this->head;
        for(int i=0; i<(this->size)-1; i++)
        {
         add = add->next;   
        }
        newstr->data=text;
        newstr->next=NULL;
        add->next =newstr;
        this->size++;
    }
}

//this is a test function to print the list from the front to the end
//just to make sure things are going in the correct order
void strList::Print(){
    strNode* printit = this->head;
    for(int i =0; i<this->size; i++){
        
        cout<<printit->data<<" ";
        
        printit= printit->next;
    }
    cout<<"."<<endl;
}

//this is BigO(n^2) as we go through 2 loops
//n for the first loop, n-1 for the second which is simplified to n
void strList::revPrintI(){
    //need to loop through the list
    //but reduce the end point each time through
    //and print the end data
    //then loop again
    int first= this->size;
    strNode* text;
    for(int i=0; i<first; i++){
        text=this->head;
        for(int j=1; j<first-i; j++){
            text=text->next;
        }
        cout<<text->data<<endl;   
    }
}
//this is BigO(n) as we only go through the list once
void strList::revPrintR(const strNode* val){
    //grab a copy of the data where we are
    //call self with decremented size
    //unwind when we hit the last node
    string text = val->data;
    if(val->next!=NULL){
        strNode* temp = val->next;
        revPrintR(temp);
    }
    cout<<text<<endl;
}