// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548

#ifndef __STUDENT_H
#define __STUDENT_H
using namespace std;
#include <string>
#include "BookList.h"
#include "Book.h"

class Student {
public:
    Student( int id, string name);
    Student();

    void setId( int id);
    void setName( string name);

    int getId() const;
    string getName() const;

    Student& operator=(const Student& student);

    bool hasBook( int bookId) const;
    int* returnBookIds(int& length);
    int getCheckedOutLength();
    void checkOutBook( Book book);
    void removeBook(int bookId);
    void showBooks();
    void showBooks2();
    void showBookById(int bookId);
    BookList checkedOut;

private:
    int id;
    string name;
};




#endif
