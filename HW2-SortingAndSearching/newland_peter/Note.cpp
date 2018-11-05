/* 
 * File:   Note.cpp
 * Author: PNewland
 * class for midi notes
 * Created on October 6, 2018, 11:38 AM
 */

#include "Note.h"

//default
Note::Note(){
    pitch=0;
    velocity=0;
    //std::cout<<"note[p="<<pitch<<",v="<<velocity<<"] created"<<std::endl;
}

//construct a note with a key and vol input
Note::Note(int key, int vol){
    setPitch(key);
    setVelocity(vol);
    //std::cout<<"note[p="<<pitch<<",v="<<velocity<<"] created"<<std::endl;
}

Note::~Note(){
   //std::cout<<"note destroyed"<<std::endl; 
}

int Note::getPitch(){
    return pitch;
}
int Note::getVelocity(){
    return velocity;
}
void Note::setPitch(int key){
    //enforce invariants
    if(key<0)
        pitch=0;
    else if(key>127)
        pitch=127;
    else
        pitch=key;
}
void Note::setVelocity(int vol){
    //enforce invariants
     if(vol<0)
        velocity=0;
    else if(vol>127)
        velocity=127;
    else
        velocity=vol;
}

Note Note::operator +(const Note &key) const{
    //make a new note that is equal to this
    Note tempNote = *this;
    //tempNote.setPitch(tempNote.pitch+key.pitch);
    return tempNote+key.pitch;
}

Note Note::operator +(int pchng) const{
    Note tempNote = *this;
    tempNote.setPitch(tempNote.pitch+pchng);
    return tempNote;
}

Note& Note::operator +=(const Note& key){
    //setPitch(pitch+key.pitch);
    return *this+=key.pitch;
}

Note& Note::operator +=(int pchng){
    setPitch(pitch+pchng);
    return *this;
}

bool Note::operator !=(const Note& key) const{
    //likely only concerned with pitch but check both
    return ((velocity!=key.velocity)||(pitch!=key.pitch));
}
bool Note::operator ==(const Note& key) const{
    //likely only concerned with pitch but check both
    return((pitch==key.pitch)&&(velocity==key.velocity));
}
