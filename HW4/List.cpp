// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548
#include <iostream>

using namespace std;

#include "List.h"

List::List() {
    listSize = 0;
    head = NULL;
}

List::~List() {
    while ( !isEmpty()) {
        removeList(1);
    }
}

bool List::isEmpty() const {
    return listSize == 0;
}

int List::getLength() const {
    return listSize;
}

bool List::retrieve( int index, City& dataItem) const {
    if ( ( index < 1) || ( index > getLength()) )
        return false;

    ListNode* cur = findList(index);
    dataItem = cur->item;
    return true;
}

bool List::insertList( int index, City newItem) {
    int newSize = getLength() + 1;
    if ( ( index < 1) || ( index > newSize) )
        return false;

    listSize = newSize;
    ListNode* newPtr = new ListNode;
    newPtr->item = newItem;
    if ( index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        ListNode* prev = findList( index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}

bool List::removeList( int index) {
    ListNode* cur;

    if ( ( index < 1) || ( index > getLength()) )
        return false;

    listSize--;

    if ( index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        ListNode* prev = findList( index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;
    return true;
}

int List::getCityIndex( string name) const {
    for ( int i = 1; i <= getLength(); i++) {
        bool comparison = findList(i)->item.getName() == name;
        if ( findList(i)->item.getName() == name) {
            return i;
        }
    }
}


void List::setVisited( int index) const {
    findList( index)->item.setMarked();
}

void List::removeVisited( int index) const {
    findList( index)->item.clearMarked();
}

bool List::isCyclic( string cityName) const {
    for ( int i = 1; i <= getLength(); i++) {
        if ( findList( i)->item.getName().compare( cityName) == 0) {
            return true;
        }
    }
    return false;
}

List::ListNode* List::findList( int index) const {
    if ( ( index < 1) || ( index > getLength()) )
        return NULL;

    else {
        ListNode* cur = head;
        for ( int skip = 1; skip < index; skip++) {
            cur = cur->next;
        }
        return cur;
    }
}

