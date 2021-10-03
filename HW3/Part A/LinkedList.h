// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548
#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include "SimpleStudent.h"
using namespace std;

typedef Student ListItemType;

class LinkedList {
public:
    LinkedList();
    LinkedList( const LinkedList& aList);
    ~LinkedList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve ( int index, ListItemType& dataItem) const;
    bool studentExists(int studentId) const;
    int studentIndex( const int studentId);
    string getName( int studentId) const;
    bool insertList( int index, ListItemType newItem);
    bool removeList( int index);

private:

    struct ListNode{
        ListItemType item;
        ListNode* next;
    };

    int listSize;
    ListNode* head;

    ListNode* findList(int index) const;
};

#endif // __LINKEDLIST_H
