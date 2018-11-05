/* 
 * File:   NoteList.h
 * Author: PNewland
 *
 * Created on October 13, 2018, 11:26 AM
 */

#ifndef NOTELIST_H
#define NOTELIST_H

#include "NoteNode.h"
#include "Note.h"


class NoteList {
public:
    //constructor/destructor
    NoteList();
    NoteList(Note aNote);
    ~NoteList();
    //copy constructor, need this to return clones.
    //NoteList(const NoteList& old);
    
    //add and remove from the end to start with
    void pushEndNote(Note aNote);
    Note popNote();
    Note popTopNote();
    
    //look for a match in pitch and velocity to start with
    //this is O(n) as we need to look at each in the list
    bool findNote(Note aNote);
    
    //sort ascending with bubble, true to sort by pitch, false by velocity
    //this is O(n^2) when the smallest value is last
    NoteList sortABub(bool byPitch);
    
    //sort descending with selection
    //this is O(n^2) also
    NoteList sortDSel(bool byPitch);
    
    NoteList getNew(NoteList* oldList);
    
    
    NoteNode* head;
    NoteNode* tail;
    
    int size;
};

#endif /* NOTELIST_H */