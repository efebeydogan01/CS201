// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548

#ifndef __FLIGHTMAP_H
#define __FLIGHTMAP_H
using namespace std;
#include "Stack.h"
#include "City.h"
#include "List.h"
#include "FlightList.h"
#include "Flight.h"
#include <string>

class FlightMap {
public:
    FlightMap( const string cityFile, const string flightFile );
    ~FlightMap();
    void displayAllCities() const;
    void displayAdjacentCities( const string cityName ) const;
    void displayFlightMap() const;
    void findFlights( const string deptCity, const string destCity ) const;
    void findLeastCostFlight( const string deptCity, const string destCity ) const;
    void runFlightRequests( const string requestFile ) const;
    int getUnvisited( int mIndex) const;
private:
    int** matrix;
    int** mTemp;
    mutable int minCost;
    mutable string minFlight;
    mutable bool pathFound;
    List cities;
    FlightList flights;
};


#endif // __FLIGHTMAP_H
