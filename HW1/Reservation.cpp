// Author name: Efe Beydoðan
// Bilkent ID: 21901548
#include <iostream>
using namespace std;
#include "Reservation.h"

Reservation::Reservation( const int*& row, const char*& col, const int passengerNum, const int codeRes, const int flight) {
    seatRow = new int[passengerNum];
    for ( int i = 0; i < passengerNum; i++) {
        seatRow[i] = row[i];
    }
    seatCol = new char[passengerNum];
    for ( int i = 0; i < passengerNum; i++) {
        seatCol[i] = col[i];
    }
    numPassengers = passengerNum;
    resCode = codeRes;
    flightNo = flight;
}

Reservation::Reservation() {
    resCode = 0;
    seatRow = NULL;
    seatCol = NULL;
    numPassengers = 0;
    flightNo = 0;
}

Reservation::~Reservation() {
    if ( seatRow) {
        delete [] seatRow;
    }
    if ( seatCol) {
        delete [] seatCol;
    }
}

int Reservation::getResCode() {
    return resCode;
}
int* Reservation::getSeatRow() {
    return seatRow;
}

char* Reservation::getSeatCol() {
    return seatCol;
}

int Reservation::getNumPassengers() {
    return numPassengers;
}

int Reservation::getFlightNum() {
    return flightNo;
}

Reservation& Reservation::operator=( const Reservation& res) {
    if ( &res != this) {
        if ( seatRow != NULL) {
            delete [] seatRow;
        }
        if ( seatCol != NULL) {
            delete [] seatCol;
        }
        numPassengers = res.numPassengers;
        flightNo = res.flightNo;
        resCode = res.resCode;
        seatRow = new int[numPassengers];
        for ( int i = 0; i < numPassengers; i++) {
            seatRow[i] = res.seatRow[i];
        }
        seatCol = new char[numPassengers];
        for ( int i = 0; i < numPassengers; i++) {
            seatCol[i] = res.seatCol[i];
        }
    }

    return *this;
}

