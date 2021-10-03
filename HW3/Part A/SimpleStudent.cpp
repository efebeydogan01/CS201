// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548
#include <iostream>
#include <string>

using namespace std;

#include "SimpleStudent.h"

Student::Student( int id, string name) {
    this->id = id;
    this->name = name;
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
