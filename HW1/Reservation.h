// Author name: Efe Beydoðan
// Bilkent ID: 21901548
#ifndef __RESERVATION_H
#define __RESERVATION_H

using namespace std;

class Reservation {
public:
    Reservation( const int*& seat, const char*& col, const int passengerNum, const int codeRes, const int flight);
    Reservation();
    ~Reservation();

    int getResCode();
    int* getSeatRow();
    char* getSeatCol();
    int getNumPassengers();
    int getFlightNum();
    Reservation& operator=( const Reservation& res);


private:
    int resCode;
    int* seatRow;
    char* seatCol;
    int numPassengers;
    int flightNo;
};

#endif
