// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548
#include <iostream>

using namespace std;

#include "StudentList.h"

StudentList::StudentList() {
    listSize = 0;
    head = NULL;
}

StudentList::StudentList( const StudentList& aList) {
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

StudentList::~StudentList() {
    while ( !isEmpty()) {
        removeList(1);
    }
}

bool StudentList::isEmpty() const {
    return listSize == 0;
}

int StudentList::getLength() const {
    return listSize;
}

bool StudentList::retrieve( int index, ListItemType2& dataItem) const {
    if ( index < 1 || index > getLength()) {
        return false;
    }

    ListNode* cur = findList(index);
    dataItem = cur->item;

    return true;
}

bool StudentList::studentExists( int studentId) const {

    for ( int i = 1; i <= listSize; i++) {
        ListNode* cur = findList(i);

        if ( cur->item.getId() == studentId) {
            return true;
        }
    }
    return false;
}

int StudentList::studentIndex( const int studentId) const {
    for ( int i = 1; i <= listSize; i++) {
        ListNode* cur = findList(i);

        if ( cur->item.getId() == studentId) {
            return i;
        }
    }
    return -1;
}


string StudentList::getName( int studentId) const {
    for ( int i = 1; i <= listSize; i++) {
        ListNode* cur = findList(i);
        if ( cur->item.getId() == studentId) {
            return cur->item.getName();
        }
    }
    return "";
}

bool StudentList::insertList( int index, ListItemType2 newItem) {
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

bool StudentList::removeList( int index) {
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

bool StudentList::aStudentHasBook( int bookId) const {
    for ( int i = 1; i <= getLength(); i++) {
        if ( findList(i)->item.hasBook(bookId)) {
            return true;
        }
    }
    return false;
}


StudentList::ListNode* StudentList:: findList( int index) const{
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




