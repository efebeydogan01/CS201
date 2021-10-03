// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548

#ifndef __STACK_H
#define __STACK_H

#include "List.h"
#include "City.h"
#include <string>

typedef City StackItemType;

class Stack {
public:
    Stack();
    // Stack( const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push( StackItemType newItem);
    bool pop();
    bool pop( StackItemType& stackTop);
    bool getTop( StackItemType& stackTop) const;
    bool isCyclic( string cityName) const;

private:
    List aList;
};

#endif // __STACK_H
