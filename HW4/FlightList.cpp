// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548
#include <iostream>

using namespace std;

#include "FlightList.h"

FlightList::FlightList() {
    listSize = 0;
    head = NULL;
}

FlightList::~FlightList() {
    while ( !isEmpty()) {
        removeList(1);
    }
}

bool FlightList::isEmpty() const {
    return listSize == 0;
}

int FlightList::getLength() const {
    return listSize;
}

bool FlightList::retrieve( int index, ListItemType& dataItem) const {
    if ( ( index < 1) || ( index > getLength()) )
        return false;

    ListNode* cur = findList(index);
    dataItem = cur->item;
    return true;
}

bool FlightList::insertList( int index, ListItemType newItem) {
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

bool FlightList::removeList( int index) {
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

FlightList::ListNode* FlightList::findList( int index) const {
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


