// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548
#ifndef __SIMPLELIBRARYSYSTEM_H
#define __SIMPLELIBRARYSYSTEM_H

using namespace std;
#include "LinkedList.h"
#include "SimpleStudent.h"

class LibrarySystem {
public:
    LibrarySystem();
    ~LibrarySystem();
    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void showStudent(const int studentId) const;

private:
    LinkedList studentList;
};


#endif // __SIMPLELIBRARYSYSTEM_H





