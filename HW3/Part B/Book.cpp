// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548

#include <iostream>
#include "Book.h"

using namespace std;

Book::Book() {
    bookId = 0;
    bookTitle = "";
    bookYear = 0;
}

Book::Book( int id, string title, int year) {
    bookId = id;
    bookTitle = title;
    bookYear = year;
}

void Book::setId( int id) {
    bookId = id;
}

void Book::setTitle( string title) {
    bookTitle = title;
}

void Book::setYear( int year) {
    bookYear = year;
}

int Book::getId() const {
    return bookId;
}

string Book::getTitle() const {
    return bookTitle;
}

int Book::getYear() const {
    return bookYear;
}

Book& Book::operator=( const Book& book) {
    if ( &book != this) {
        bookId = book.getId();
        bookTitle = book.getTitle();
        bookYear = book.getYear();
    }
}








