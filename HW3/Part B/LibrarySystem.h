// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548

#ifndef __LIBRARYSYSTEM_H
#define __LIBRARYSYSTEM_H

using namespace std;

#include "Student.h"
#include "Book.h"
#include "StudentList.h"
#include "BookList.h"

class LibrarySystem {
public:
    LibrarySystem();
    ~LibrarySystem();
    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);
    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);
    void showAllBooks() const;
    void showBook(const int bookId) const;
    void showStudent(const int studentId) const;
private:
    StudentList studentList;
    BookList bookList;
};


#endif // __LIBRARYSYSTEM_H





