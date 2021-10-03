// Author name: Efe Beydoðan
// Bilkent ID: 21901548
#include "ReservationSystem.h"
#include "Flight.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

ReservationSystem::ReservationSystem() {
    capacity = 10;
    resCapacity = 10;
    flights = new Flight[capacity];
    current = 0;
    res = new Reservation[resCapacity];
    currentRes = 0;
    resCode = 1;
}

ReservationSystem::~ReservationSystem() {
    if ( flights) {
        delete [] flights;
    }
    if ( res) {
        delete [] res;
    }
}

void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo) {
    for ( int i  = 0; i < current; i++) {
        if( flights[i].getFlightNo() == flightNo) {
            cout << "Flight" << " " << flightNo << " " << "already exists" << endl;
            return;
        }
    }
    if ( rowNo <= 0 || seatNo <= 0) {
        cout << "Invalid row or seat number entered." << endl;
    }
    else {
        if ( current >= capacity) {
            capacity += 2;
            Flight* newFlights = new Flight[capacity];
            for ( int i = 0; i < current; i++) {
                newFlights[i] = flights[i];
            }
            delete [] flights;
            flights = newFlights;
        }
        Flight f( flightNo, rowNo, seatNo);
        flights[current] = f;
        current++;
        cout << "Flight " << flightNo << " has been added" << endl;
    }
}

void ReservationSystem::cancelFlight( const int flightNo) {
    cout << "\n";
    for ( int i = 0; i < current; i++) {
        if ( flights[i].getFlightNo() == flightNo) {
            cout << "Flight " << flights[i].getFlightNo() << " and all of its reservations have been canceled" << endl;
            for ( int k = 0; k < currentRes; k++) {
                if ( res[k].getFlightNum() == flights[i].getFlightNo()) {
                    cancelReservation2( res[k].getResCode());
                }
            }
            if ( i == current - 1) {
                // delete (flights + current - 1);
                // flights[current - 1].~Flight();
                current--;
                return;
            }
            else {
                for ( int j = i; j < current - 1; j++) {
                    flights[j] = flights[j+1];
                }
                // delete (flights + current - 1);
                // flights[current-1].~Flight();
                current--;
                return;
            }
        }
    }
    cout << "Flight " << flightNo << " does not exist" << endl;
}

 void ReservationSystem::showAllFlights() {
    cout << "\n";
    if ( current == 0) {
        cout << "No flights exist" << endl;
     }
     else {
        cout << "Flights currently operated:" << endl;
        for ( int i = 0; i < current; i++) {
            cout << "Flight " << flights[i].getFlightNo() << " (" << flights[i].getAvailableSeatNo() << " available seats)" << endl;
        }
     }
     cout << "\n";
 }

 void ReservationSystem::showFlight( const int flightNo ) {
     cout << "\n";
     for ( int i = 0; i < current; i++) {
        if ( flights[i].getFlightNo() == flightNo) {

            flights[i].displaySeats();
            return;
        }
     }

     cout << "Flight " << flightNo << " does not exist" << endl;
 }

 int ReservationSystem::makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol) {
     cout << "\n";
     stringstream strings;
     bool availableSeat = true;
     for ( int i = 0; i < current; i++) {
        if ( flights[i].getFlightNo() == flightNo) {
            bool* available = flights[i].getSeatsAvailable();
            for ( int k = 0; k < numPassengers; k++) {
                if ( !available[ ((seatRow[k] - 1)*(flights[i].getSeat())) + (int)(seatCol[k]) - 65]) {
                    availableSeat = false;
                    strings << seatRow[k] << seatCol[k] << " ";
                }
            }
            if ( !availableSeat && strings.str().size() <= 3) {
                cout << strings.str() + "is not available" << endl;
                return -1;
            }
            else if ( !availableSeat && strings.str().size() > 3) {
                cout << strings.str() << "are not available" << endl;
                return -1;
            }
            else if ( availableSeat) {
                if ( currentRes >= resCapacity) {
                    resCapacity += 10;
                    Reservation* newRes = new Reservation[resCapacity];
                    for ( int i = 0; i < currentRes; i++) {
                        newRes[i] = res[i];
                    }
                    delete [] res;
                    res = newRes;
                }
                Reservation R( seatRow, seatCol, numPassengers, resCode, flightNo);
                res[currentRes] = R;
                currentRes++;
                int code = resCode;
                resCode++;
                flights[i].setOccupied(numPassengers, seatRow, seatCol);
                return code;
            }
        }
     }
     cout << "Flight " << flightNo << " does not exist" << endl;
     return -1;
 }

void ReservationSystem::cancelReservation( const int resCode) {
    cout << "\n";
    for ( int i = 0; i < currentRes; i++) {
        if ( res[i].getResCode() == resCode) {
            stringstream s;
            int flightNumber = res[i].getFlightNum();
            for ( int j = 0; j < res[i].getNumPassengers(); j++) {
                s << (res[i].getSeatRow())[j] << (res[i].getSeatCol())[j] << " ";
            }
            for ( int k = 0; k < current; k++) {
                if ( flights[k].getFlightNo() == flightNumber) {
                    flights[k].setAvailable( res[i].getNumPassengers(), res[i].getSeatRow(), res[i].getSeatCol());
                }
            }
            if ( i == currentRes - 1) {
                // delete (res + i);
                currentRes--;
            }
            else {
                for ( int k = i; k < currentRes - 1; k++) {
                    res[k] = res[k+1];
                }
                // delete (res + currentRes - 1);
                currentRes--;
            }
            cout << "Reservations for the seats " << s.str() << "is canceled in Flight " << flightNumber << endl;
            return;
        }
    }
    cout << "No reservations are found under code " << resCode << endl;
}

void ReservationSystem::showReservation( const int resCode ) {
    cout << "\n";
    for ( int i = 0; i < currentRes; i++) {
        if ( res[i].getResCode() == resCode) {
            stringstream s;
            for ( int j = 0; j < res[i].getNumPassengers(); j++) {
                s <<  (res[i].getSeatRow())[j] << (res[i].getSeatCol())[j] << " ";
            }
            cout << "Reservations under Code " << resCode << " in Flight " << res[i].getFlightNum() << ": " << s.str() << endl;
            return;
        }
    }
    cout << "No reservations are found under code " << resCode << endl;
}

void ReservationSystem::cancelReservation2( const int resCode) {
    cout << "\n";
    for ( int i = 0; i < currentRes; i++) {
        if ( res[i].getResCode() == resCode) {
            int flightNumber = res[i].getFlightNum();
            for ( int k = 0; k < current; k++) {
                if ( flights[k].getFlightNo() == flightNumber) {
                    flights[k].setAvailable( res[i].getNumPassengers(), res[i].getSeatRow(), res[i].getSeatCol());
                }
            }
            if ( i == currentRes - 1) {
                // delete (res + i);
                currentRes--;
            }
            else {
                for ( int k = i; k < currentRes - 1; k++) {
                    res[k] = res[k+1];
                }
                // delete (res + currentRes - 1);
                currentRes--;
            }
            return;
        }
    }
    cout << "No reservations are found under code " << resCode << endl;
}







