// Author name: Efe Beydoðan
//CS201 Section 1
// Bilkent ID: 21901548

#ifndef __SIMPLESTUDENT_H
#define __SIMPLESTUDENT_H
using namespace std;
#include <string>

class Student {
public:
    Student( int id, string name);
    Student();

    void setId( int id);
    void setName( string name);

    int getId() const;
    string getName() const;

    Student& operator=(const Student& student);

private:
    int id;
    string name;
};




#endif // __SIMPLESTUDENT_H
