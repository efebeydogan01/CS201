// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

#include "Student.h"
#include "BookList.h"

Student::Student( int id, string name) {
    this->id = id;
    this->name = name;
    checkedOut = BookList();
}

Student::Student() {
    id = 0;
    name = "";
}

void Student::setId( int id) {
    this->id = id;
}

void Student::setName( string name) {
    this->name = name;
}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

Student& Student::operator=( const Student& student) {
    if ( &student != this) {
        id = student.getId();
        name = student.getName();
    }

    return *this;
}

bool Student::hasBook( int bookId) const {
    if ( checkedOut.bookExists(bookId)) {
        return true;
    }
    return false;
}

int* Student::returnBookIds( int& length) {
    return checkedOut.returnIds(length);
}

int Student::getCheckedOutLength() {
    return checkedOut.getLength();
}

void Student::checkOutBook( Book book) {
    checkedOut.insertList( checkedOut.getLength() + 1, book);
}

void Student::removeBook( int bookId) {
    checkedOut.removeList( checkedOut.bookIndex(bookId));
}

void Student::showBooks() {
    if ( checkedOut.getLength() > 0) {
        cout << std::left << setw(15) << "Book id" << setw(25) << "Book name" << setw(10) << "Year" << endl;
        for ( int i = 1; i <= checkedOut.getLength(); i++) {
            int id = checkedOut.findList(i)->item.getId();
            // int idLength = trunc(log10(id)) + 1;
            string title = checkedOut.findList(i)->item.getTitle();
            // int titleLength = title.length();
            int year = checkedOut.findList(i)->item.getYear();
            // int yearLength = trunc(log10(year)) + 1;
            // cout << id << setw(13 - idLength + titleLength) << title << setw(25 - titleLength + yearLength) << year << endl;
            cout << std::left << setw(15) << id << setw(25) << title << setw(10) << year << endl;
        }
    }
}

void Student::showBooks2() {
    for ( int i = 1; i <= checkedOut.getLength(); i++) {
        int id = checkedOut.findList(i)->item.getId();
        // int idLength = trunc(log10(id)) + 1;
        string title = checkedOut.findList(i)->item.getTitle();
        // int titleLength = title.length();
        int year = checkedOut.findList(i)->item.getYear();
        // int yearLength = trunc(log10(year)) + 1;
        // cout << id << setw(13 - idLength + titleLength) << title << setw(25 - titleLength + yearLength) << year << setw(18 - yearLength + 23) << "Checked out by student " << getId() << endl;
        cout << std::left << setw(15) << id << setw(25) << title << setw(10) << year << setw(20) << "Checked out by student " << getId() << endl;
    }
}

void Student::showBookById( int bookId) {
    for ( int i = 1; i <= checkedOut.getLength(); i++) {
        if ( checkedOut.findList(i)->item.getId() == bookId) {
            // int idLength = trunc(log10(bookId)) + 1;
            string title = checkedOut.findList(i)->item.getTitle();
            // int titleLength = title.length();
            int year = checkedOut.findList(i)->item.getYear();
            // int yearLength = trunc(log10(year)) + 1;
            // cout << bookId << setw(13 - idLength + titleLength) << title << setw(25 - titleLength + yearLength) << year << setw(18 - yearLength + 23) << "Checked out by student " << getId() << endl;
            cout << std::left << setw(15) << bookId << setw(25) << title << setw(10) << year << setw(20) << "Checked out by student " << getId() << endl;
            return;
        }
    }
}

