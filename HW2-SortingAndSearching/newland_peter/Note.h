/* 
 * File:   Note.h
 * Author: PNewland
 * class for midi notes
 * Created on October 6, 2018, 11:38 AM
 */
#include <iostream>

#ifndef NOTE_H
#define NOTE_H

class Note{
public:
    Note();
    Note(int key, int vol);
    ~Note();
    
    //+ operation returns a new note
    //add notes
    Note operator+(const Note &key) const; //last const to protect this
    //get the note some position above/below this note
    Note operator+(int pchng) const;
    
    //+= operation modifies this and returns ref to this
    //modify with other key will increase pitch and volume
    Note& operator+=(const Note &key);
    //modify with a pitch int
    Note& operator+=(int pchng);
    
    //compare notes
    bool operator==(const Note &key) const;
    bool operator!=(const Note &key) const;
    
    //properties
    int getPitch();
    int getVelocity();
    void setPitch(int key);
    void setVelocity(int vol);
    
private:
    int pitch; //limit from 0-127
    int velocity; //limit from 0-127
};
#endif /* NOTE_H */
