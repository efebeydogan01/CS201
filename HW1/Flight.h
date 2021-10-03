// Author name: Efe Beydoðan
// Bilkent ID: 21901548
#ifndef __FLIGHT_H
#define __FLIGHT_H

using namespace std;

class Flight {
public:
    Flight( int flight, int row, int seat);
    Flight( const Flight& flight);
    Flight();
    ~Flight();

    int getFlightNo();
    int getRow();
    int getSeat();
    int getAvailableSeatNo();
    int getSeatsNum();
    void displaySeats();
    bool* getSeatsAvailable();
    void setOccupied( const int numPassenger, const int*& row, const char*& seat);
    void setAvailable( const int numPassenger, const int* row, const char* seat);
    Flight& operator=( const Flight& flight);

private:
    int flightNo;
    int rowNo;
    int seatNo;
    int availableSeatNo;
    int seatsNum;
    int* rows;
    char* seats;
    bool* seatsAvailable;
};


#endif
