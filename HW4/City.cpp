// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548
#include <iostream>

using namespace std;

#include "City.h"

City::City() {
    name = "";
    marked = false;
}

City::City( string cityName) {
    name = cityName;
    marked = false;
}

City::~City() {
}

void City::setName( string cityName) {
    name = cityName;
}

string City::getName() const {
    return name;
}

void City::setMarked() {
    marked = true;
}

bool City::getMarked() {
    return marked;
}

void City::clearMarked() {
    marked = false;
}

City& City::operator=( const City& city) {
    if ( &city != this) {
        name = city.getName();
        marked = city.marked;
    }
    return *this;
}


