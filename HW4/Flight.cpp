// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548

#include <iostream>

using namespace std;

#include "Flight.h"
#include <string>
Flight::Flight() {
    departureCity = "";
    destinationCity = "";
    id = 0;
    cost = 0;
}
Flight::Flight( int flightId, int flightCost, string departCity, string destCity) {
    id = flightId;
    cost = flightCost;
    departureCity = departCity;
    destinationCity = destCity;
}

Flight::~Flight() {
}

void Flight::setId( int flightId) {
    id = flightId;
}

void Flight::setCost( int flightCost) {
    cost = flightCost;
}

void Flight::setDepartureCity( string departCity) {
    departureCity = departCity;
}

void Flight::setDestinationCity( string destCity) {
    destinationCity = destCity;
}

int Flight::getId() const {
    return id;
}

int Flight::getCost() const {
    return cost;
}

string Flight::getDepartureCity() const {
    return departureCity;
}

string Flight::getDestinationCity() const {
    return destinationCity;
}

Flight& Flight::operator=( const Flight& flight) {
    if ( this != &flight) {
        departureCity = flight.getDepartureCity();
        destinationCity = flight.getDestinationCity();
        id = flight.getId();
        cost = flight.getCost();
    }
    return *this;
}
