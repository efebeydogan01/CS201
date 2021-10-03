// Author name: Efe Beydoðan
// Bilkent ID: 21901548
#include <iostream>

using namespace std;

#include "Flight.h"

Flight::Flight(int flight, int row, int seat) {
    flightNo = flight;
    rowNo = row;
    seatNo = seat;
    availableSeatNo = row * seat;
    seatsNum = row * seat;
    rows = new int[rowNo];
    seats = new char[seatNo];
    seatsAvailable = new bool[seatsNum];
    for ( int i = 0; i < seatsNum; i++) {
        seatsAvailable[i] = true;
    }
    for ( int i = 0; i < rowNo; i++) {
        rows[i] = i+1;
    }
    for ( int i = 0; i < seatNo; i++) {
        seats[i] = (char)(65+i);
    }
}

Flight::Flight( const Flight& flight) {
    flightNo = flight.flightNo;
    rowNo = flight.rowNo;
    seatNo = flight.seatNo;
    availableSeatNo = flight.availableSeatNo;
    seatsNum = flight.seatsNum;
    rows = new int[rowNo];
    seats = new char[seatNo];
    seatsAvailable = new bool[seatsNum];
    for ( int i = 0; i < seatsNum; i++) {
        seatsAvailable[i] = flight.seatsAvailable[i];
    }
    for ( int i = 0; i < rowNo; i++) {
        rows[i] = flight.rows[i];
    }
    for ( int i = 0; i < seatNo; i++) {
        seats[i] = (char)(65+i);
    }
}

Flight::Flight() {
    flightNo = 0;
    rowNo = 0;
    seatNo = 0;
    availableSeatNo = 0;
    seatsNum = 0;
    rows = NULL;
    seats = NULL;
    seatsAvailable = NULL;
}

Flight::~Flight() {
    delete [] rows;
    delete [] seats;
    delete [] seatsAvailable;
}

int Flight::getFlightNo() {
    return flightNo;
}

int Flight::getRow() {
    return rowNo;
}

int Flight::getSeat() {
    return seatNo;
}

int Flight::getAvailableSeatNo() {
    return availableSeatNo;
}

int Flight::getSeatsNum() {
    return seatsNum;
}

void Flight::displaySeats() {
    cout << "Flight " << flightNo << " has " << availableSeatNo << " available seats" << endl;
    int counter = 0;
    cout << "  ";
    for ( int i = 0; i < seatNo; i++) {
        cout << seats[i] << " ";
    }
    cout << "\n";
    for ( int k = 0; k < rowNo; k++) {
        cout << rows[k] << " ";
        for ( int i = 0; i < seatNo; i++) {
            if ( seatsAvailable[counter]) {
                cout << "o" << " ";
                counter++;
            }
            else {
                cout << "x" << " ";
                counter++;
            }
        }
        cout << "\n";
    }
}

bool* Flight::getSeatsAvailable() {
    return seatsAvailable;
}

void Flight::setOccupied( const int numPassenger, const int*& row, const char*& seat) {
    for ( int i = 0; i < numPassenger; i++) {
        seatsAvailable[ ((row[i] - 1)*(seatNo)) + (int)(seat[i]) - 65] = false;
        availableSeatNo--;
    }
}

void Flight::setAvailable( const int numPassenger, const int* row, const char* seat) {
    for ( int i = 0; i < numPassenger; i++) {
        seatsAvailable[ ((row[i] - 1)*(seatNo)) + (int)(seat[i]) - 65] = true;
        availableSeatNo++;
    }
}

Flight& Flight::operator=( const Flight& flight) {
    if ( &flight != this) {
        flightNo = flight.flightNo;
        rowNo = flight.rowNo;
        seatNo = flight.seatNo;
        availableSeatNo = flight.availableSeatNo;
        seatsNum = flight.seatsNum;

        if ( rows != NULL) {
            delete [] rows;
        }
        if ( seats != NULL) {
            delete [] seats;
        }
        if ( seats != NULL) {
            delete [] seatsAvailable;
        }

        rows = new int[rowNo];
        seats = new char[seatNo];
        seatsAvailable = new bool[seatsNum];
        for ( int i = 0; i < seatsNum; i++) {
            seatsAvailable[i] = flight.seatsAvailable[i];
        }
        for ( int i = 0; i < rowNo; i++) {
            rows[i] = flight.rows[i];
        }
        for ( int i = 0; i < seatNo; i++) {
            seats[i] = (char)(65+i);
        }
    }

    return *this;
}

