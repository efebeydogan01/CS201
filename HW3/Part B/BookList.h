// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548

#ifndef __BOOKLIST_H
#define __BOOKLIST_H

#include "Book.h"

using namespace std;

typedef Book ListItemType;

class BookList {
public:
    BookList();
    BookList( const BookList& aList);
    ~BookList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve ( int index, ListItemType& dataItem) const;
    bool bookExists(int bookId) const;
    int bookIndex( const int bookId) const;
    string getName( int bookId) const;
    bool insertList( int index, ListItemType newItem);
    bool removeList( int index);
    int* returnIds( int& length);

private:

    struct ListNode{
        ListItemType item;
        ListNode* next;
        friend class LibrarySystem;
    };

    int listSize;
    ListNode* head;

    ListNode* findList(int index) const;
    friend class LibrarySystem;
    friend class Student;
};



#endif // __BookList_H
