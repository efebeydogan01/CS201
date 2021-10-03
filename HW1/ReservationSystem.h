// Author name: Efe Beydoðan
// Bilkent ID: 21901548
#ifndef __RESERVATIONSYSTEM_H
#define __RESERVATIONSYSTEM_H

#include "Flight.h"
#include "Reservation.h"

using namespace std;

class ReservationSystem {
public:
    ReservationSystem();
    ~ReservationSystem();

    void addFlight( const int flightNo, const int rowNo, const int seatNo );
    void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );
    int makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol );
    void cancelReservation( const int resCode );
    void showReservation( const int resCode );
    void cancelReservation2( const int resCode);
        int capacity;

private:
    Flight* flights;
    int current;
    Reservation* res;
    int currentRes;
    int resCode;
    int resCapacity;
};

#endif
