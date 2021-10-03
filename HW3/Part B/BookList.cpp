// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548
#include <iostream>

using namespace std;

#include "BookList.h"

BookList::BookList() {
    listSize = 0;
    head = NULL;
}

BookList::BookList( const BookList& aList) {
    listSize = aList.listSize;

    if ( aList.head == NULL) {
        head = NULL;
    }
    else {
        head = new ListNode;
        head->item = aList.head->item;
        ListNode* ptr = head;

        for ( ListNode* origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next) {
            ptr->next = new ListNode;
            ptr = ptr->next;
            ptr->item = origPtr->item;
        }
        ptr->next = NULL;
    }
}

BookList::~BookList() {
    while ( !isEmpty()) {
        removeList(1);
    }
}

bool BookList::isEmpty() const {
    return listSize == 0;
}

int BookList::getLength() const {
    return listSize;
}

bool BookList::retrieve( int index, ListItemType& dataItem) const {
    if ( index < 1 || index > getLength()) {
        return false;
    }

    ListNode* cur = findList(index);
    dataItem = cur->item;

    return true;
}

bool BookList::bookExists( int bookId) const {

    for ( int i = 1; i <= listSize; i++) {
        ListNode* cur = findList(i);

        if ( cur->item.getId() == bookId) {
            return true;
        }
    }
    return false;
}

int BookList::bookIndex( const int bookId) const {
    for ( int i = 1; i <= listSize; i++) {
        ListNode* cur = findList(i);

        if ( cur->item.getId() == bookId) {
            return i;
        }
    }
    return -1;
}


string BookList::getName( int bookId) const {
    for ( int i = 1; i <= listSize; i++) {
        ListNode* cur = findList(i);
        if ( cur->item.getId() == bookId) {
            return cur->item.getTitle();
        }
    }
    return "";
}

bool BookList::insertList( int index, ListItemType newItem) {
    int newLength = getLength() + 1;

    if ( index < 1 || index > newLength) {
        return false;
    }
    ListNode* newPtr = new ListNode;
    listSize = newLength;
    newPtr->item = newItem;

    if ( index == 1) {
        newPtr-> next = head;
        head = newPtr;
    }
    else {
        ListNode* prev = findList(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}

bool BookList::removeList( int index) {
    ListNode* cur;

    if ( index < 1 || index > getLength()) {
        return false;
    }

    listSize--;

    if ( index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        ListNode* prev = findList(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }

    cur->next = NULL;
    delete cur;
    cur = NULL;
    return true;
}

int* BookList::returnIds( int& length) {
    int* ids = new int[getLength()];
    length = 0;
    for ( int i = 1; i <= getLength(); i++) {
        ids[i-1] = findList(i)->item.getId();
        length++;
    }
    return ids;
}

BookList::ListNode* BookList:: findList( int index) const{
    if ( index < 1 || index > getLength()) {
        return NULL;
    }

    else {
        ListNode* cur = head;
        for ( int skip = 1; skip < index; skip++) {
            cur = cur->next;
        }
        return cur;
    }
}
