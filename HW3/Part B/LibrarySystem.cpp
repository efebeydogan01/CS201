// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548
#include <iostream>
#include "LibrarySystem.h"
#include "StudentList.h"
#include "Student.h"
#include "Book.h"
#include "BookList.h"
#include <iomanip>
#include <cmath>

using namespace std;

LibrarySystem::LibrarySystem() {
}

LibrarySystem::~LibrarySystem() {
    studentList.~StudentList();
    bookList.~BookList();
}

void LibrarySystem::addBook( const int bookId, const string bookName, const int bookYear) {
    if ( bookList.bookExists(bookId)) {
        cout << "Book " << bookId << " already exists" << endl;
    }
    else {
        bookList.insertList( bookList.getLength() + 1, Book(bookId, bookName, bookYear));
        cout << "Book " << bookId << " has been added" << endl;
    }
}

void LibrarySystem::deleteBook( const int bookId) {
    if ( bookList.bookExists( bookId)) {
        bookList.removeList( bookList.bookIndex(bookId));
        cout << "Book " << bookId << " has not been checked out" << endl;
        cout << "Book " << bookId << " has been deleted" << endl;
    }
    else if ( studentList.aStudentHasBook(bookId)) {
        returnBook(bookId);
        bookList.removeList(bookList.bookIndex(bookId));
        cout << "Book " << bookId << " has been deleted" << endl;
    }
    else {
        cout << "Book " << bookId << " does not exist" << endl;
    }
}


void LibrarySystem::addStudent( const int studentId, const string studentName) {

    if ( studentList.studentExists( studentId)) {
        cout << "Student " << studentId << " already exists" << endl;
        return;
    }

    studentList.insertList( studentList.getLength() + 1, Student(studentId, studentName));
    cout << "Student " << studentId << " has been added" << endl;
}

void LibrarySystem::deleteStudent( const int studentId) {
    if ( studentList.studentExists(studentId)) {
        int length = 0;
        int* ids = studentList.findList( studentList.studentIndex(studentId))->item.returnBookIds(length);
        for ( int i = 0; i < length; i++) {
            returnBook( ids[i]);
        }
        delete [] ids;
        studentList.removeList(studentList.studentIndex( studentId));
        cout << "Student " << studentId << " has been deleted" << endl;
        return;
    }

    cout << "Student " << studentId << " does not exist" << endl;

}

void LibrarySystem::checkoutBook(const int bookId, const int studentId) {
    for ( int i = 1; i <= studentList.getLength(); i++) {
        if ( studentList.findList(i)->item.hasBook(bookId)) {
            cout << "Book " << bookId << " has been already checked out by another student" << endl;
            return;
        }
    }
    if ( !bookList.bookExists(bookId)) {
        cout << "Book " << bookId << " does not exist for checkout" << endl;
    }
    else if ( !studentList.studentExists(studentId)) {
        cout << "Student " << studentId << " does not exist for checkout" << endl;
    }
    else {
        studentList.findList( studentList.studentIndex(studentId))->item.checkOutBook( bookList.findList( bookList.bookIndex(bookId))->item);
        bookList.removeList(bookList.bookIndex(bookId));
        cout << "Book " << bookId << " has been checked out by student " << studentId << endl;
    }
}

void LibrarySystem::returnBook( const int bookId) {
    if ( bookList.bookExists(bookId)) {
        cout << "Book " << bookId << " has not been checked out" << endl;
        return;
    }
    for ( int i = 1; i <= studentList.getLength(); i++) {
        if ( studentList.findList(i)->item.hasBook(bookId)) {
            bookList.insertList(bookList.getLength() + 1, (Book) studentList.findList(i)->item.checkedOut.findList( studentList.findList(i)->item.checkedOut.bookIndex(bookId))->item);
            studentList.findList(i)->item.removeBook( bookId);
            cout << "Book " << bookId << " has been returned" << endl;
            return;
        }
    }

    cout << "Book " << bookId << " does not exist" << endl;
}

void LibrarySystem::showAllBooks() const {
    cout << std::left << setw(15) << "Book id" << setw(25) << "Book name" << setw(10) << "Year" <<  setw(20) << "Status" << endl;
    // cout << "Book id" << setw(15) << "Book name" << setw(20) << "Year" <<  setw(20) << "Status" << endl;
    for ( int i = 1; i <= bookList.getLength(); i++) {
          string title = bookList.findList(i)->item.getTitle();
//        int titleLength = title.length();
          int year = bookList.findList(i)->item.getYear();
//        int yearLength = trunc(log10(year)) + 1;
          int id = bookList.findList(i)->item.getId();
//        int idLength = trunc(log10(id)) + 1;
        cout << std::left << setw(15) << id << setw(25) << title << setw(10) << year << setw(20) << "Not checked out" << endl;
    }
    for ( int i = 1; i <= studentList.getLength(); i++) {
        studentList.findList(i)->item.showBooks2();
    }
}

void LibrarySystem::showBook(const int bookId) const {
    if ( bookList.bookExists(bookId)) {
//        int idLength = trunc(log10(bookId)) + 1;
        string title = bookList.findList( bookList.bookIndex(bookId))->item.getTitle();
//        int titleLength = title.length();
        int year = bookList.findList( bookList.bookIndex(bookId))->item.getYear();
//        int yearLength = trunc(log10(year)) + 1;
//        cout << bookId << setw(13 - idLength + titleLength) << title << setw(25 - titleLength + yearLength) << year << setw(18 - yearLength + 15) << "Not checked out" << endl;
        cout << std::left << setw(15) <<  bookId << setw(25) << title << setw(10) << year << setw(20) << "Not checked out" << endl;
        return;
    }
    else {
        for ( int i = 1; i <= studentList.getLength(); i++) {
            if ( studentList.findList(i)->item.hasBook( bookId)) {
                studentList.findList(i)->item.showBookById( bookId);
                return;
            }
        }
    }
    cout << "Book " << bookId << " does not exist" << endl;
}


void LibrarySystem::showStudent( const int studentId) const {
    bool found = false;
    string name;

    if ( studentList.studentExists(studentId)) {
        found = true;
        name = studentList.getName(studentId);
    }

    if ( !found) {
        cout << "Student " << studentId << " does not exist" << endl;
    }
    else {
        cout << "Student ID: " << studentId << ", Student Name: " << name << endl;
        if ( studentList.findList( studentList.studentIndex(studentId))->item.checkedOut.getLength() >0 ) {
            cout << "Student " << studentId << " checked out the following books: " << endl;
            studentList.findList( studentList.studentIndex(studentId))->item.showBooks();
        }
        else {
            cout << "Student " << studentId << " has no books" << endl;
        }
    }
}
