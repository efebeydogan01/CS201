// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548

#ifndef __FLIGHTLIST_H
#define __FLIGHTLIST_H

#include "Flight.h"

using namespace std;

typedef Flight ListItemType;

class FlightList {
public:
    FlightList();
    ~FlightList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve ( int index, ListItemType& dataItem) const;
    bool insertList( int index, ListItemType newItem);
    bool removeList( int index);

private:

    struct ListNode{
        ListItemType item;
        ListNode* next;
    };
    ListNode* head;
    ListNode* findList(int index) const;
    int listSize;
};

#endif
