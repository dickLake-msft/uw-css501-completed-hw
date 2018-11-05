/* 
 * File:   NoteNode.h
 * Author: PNewland
 * 
 * NoteNode should really only be used by NoteList as the user probably only
 * wants to detail with the notes and the lists, not the intermediate step
 * of list nodes
 * 
 * Created on October 13, 2018, 11:26 AM
 */

#ifndef NOTENODE_H
#define NOTENODE_H

#include "Note.h"

class NoteNode {
public:    
    Note data;
    
    NoteNode* next;
    NoteNode* prev;
};

#endif /* NOTENODE_H */

