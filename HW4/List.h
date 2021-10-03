// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548

#ifndef __LIST_H
#define __LIST_H

using namespace std;
#include <string>
#include "City.h"

class List {
public:
    List();
    // List( const List& aList);
    ~List();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve ( int index, City& dataItem) const;
    bool insertList( int index, City newItem);
    bool removeList( int index);
    int getCityIndex( string name) const;
    void setVisited( int index) const;
    void removeVisited( int index) const;
    bool isCyclic( string cityName) const;

private:

    struct ListNode{
        City item;
        ListNode* next;
    };
    ListNode* findList(int index) const;
    int listSize;
    ListNode* head;
};


#endif // __LIST_H
