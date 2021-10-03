// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548

#ifndef __STUDENTLIST_H
#define __STUDENTLIST_H

#include "Student.h"
using namespace std;

typedef Student ListItemType2;

class StudentList {
public:
    StudentList();
    StudentList( const StudentList& aList);
    ~StudentList();

    bool isEmpty() const;
    int getLength() const;
    bool retrieve ( int index, ListItemType2& dataItem) const;
    bool studentExists(int studentId) const;
    int studentIndex( const int studentId) const;
    string getName( int studentId) const;
    bool insertList( int index, ListItemType2 newItem);
    bool removeList( int index);
    bool aStudentHasBook(int bookId) const;

private:

    struct ListNode{
        ListItemType2 item;
        ListNode* next;
        friend class LibrarySystem;
    };

    int listSize;
    ListNode* head;
    ListNode* findList(int index) const;
    friend class LibrarySystem;

};

#endif

