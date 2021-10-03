// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548

#ifndef __BOOK_H
#define __BOOK_H

#include <string>

using namespace std;

class Book {
public:
    Book();
    Book( int id, string title, int year);

    void setId( int id);
    void setTitle( string title);
    void setYear( int year);

    int getId() const;
    string getTitle() const;
    int getYear() const;

    Book& operator=(const Book& book);

private:
    int bookId;
    string bookTitle;
    int bookYear;
};

#endif // __BOOK_H
