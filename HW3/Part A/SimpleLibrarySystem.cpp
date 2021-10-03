// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548
#include <iostream>
#include "SimpleLibrarySystem.h"
#include "LinkedList.h"
#include "SimpleStudent.h"

using namespace std;

LibrarySystem::LibrarySystem() {
}

LibrarySystem::~LibrarySystem() {
    studentList.~LinkedList();
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
    int index = 0;
    if ( studentList.studentExists(studentId)) {
        index = studentList.studentIndex( studentId);
        studentList.removeList(index);
        cout << "Student " << studentId << " has been removed" << endl;
        return;
    }


    cout << "Student " << studentId << " does not exist" << endl;

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
    }
}
