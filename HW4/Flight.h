// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548

#ifndef __FLIGHT_H
#define __FLIGHT_H
using namespace std;
#include <string>

class Flight {
public:
    Flight();
    Flight( int flightId, int flightCost, string departCity, string destCity);
    ~Flight();
    void setId( int flightId);
    void setCost( int flightCost);
    void setDepartureCity( string departCity);
    void setDestinationCity( string destCity);

    int getId() const;
    int getCost() const;
    string getDepartureCity() const;
    string getDestinationCity() const;
    Flight& operator=( const Flight& flight);
private:
    string departureCity;
    string destinationCity;
    int id;
    int cost;
};
#endif
