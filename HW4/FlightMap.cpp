// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548

#include <iostream>


#include "FlightMap.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

FlightMap::FlightMap( const string cityFile, const string flightFile) {
    pathFound = false;
    minCost = 0;
    minFlight = "";
    string cityName;
    ifstream fileCity;

    fileCity.open( cityFile.c_str(), ios_base::in);
//    while ( fileCity >> cityName) {
//        cities.insertList( cities.getLength() + 1, City(cityName));
//    }

//    while ( getline( fileCity, cityName)) {
//        stringstream ss( cityName);
//        getline(ss, cityName, '\n');
//        cities.insertList( cities.getLength() + 1, City( cityName));
//    }

//    for ( cityName; getline( fileCity, cityName);) {
//        cities.insertList( cities.getLength() + 1, City( cityName));
//    }

    while ( fileCity.eof() == false) {
        getline( fileCity, cityName, '\n');
        cities.insertList( cities.getLength() + 1, City( cityName));
    }


//    char output[100];
//
//    if( fileCity.is_open()) {
//        while( !fileCity.eof()) {
//            fileCity >> output;
//            cities.insertList( cities.getLength() + 1, City( output));
//        }
//    }


    fileCity.close();

    string text;
    string firstCity;
    string adjacentCity;
    string id;
    int flightId;
    string costStr;
    int cost;
    ifstream fileFlight;
    fileFlight.open( flightFile.c_str(), ios_base::in);

    matrix =  new int*[cities.getLength()];
    for ( int i = 0; i < cities.getLength(); i++) {
        matrix[i] = new int[cities.getLength()];
    }

    for ( int i = 0; i < cities.getLength(); i++) {
        for ( int k = 0; k < cities.getLength(); k++) {
            matrix[i][k] = 0;
        }
    }

//    while ( getline( fileFlight, text)) {
//        stringstream ss( text);
//        getline( ss, firstCity, ',');
//        getline( ss, adjacentCity, ',');
//        getline( ss, id, ',');
//        istringstream( id) >> flightId;
//        getline( ss, costStr, '\n');
//        istringstream( costStr) >> cost;
//        flights.insertList( flights.getLength() + 1, Flight( flightId, cost, firstCity, adjacentCity));
//    }
    while ( fileFlight.eof() == false) {
        getline( fileFlight, text, '\n');
        stringstream ss( text);
        getline( ss, firstCity, ',');
        getline( ss, adjacentCity, ',');
        getline( ss, id, ',');
        istringstream( id) >> flightId;
        getline( ss, costStr, '\n');
        istringstream( costStr) >> cost;
        flights.insertList( flights.getLength() + 1, Flight( flightId, cost, firstCity, adjacentCity));
    }


//    for ( int i = 1; i <= cities.getLength(); i++) {
//        City tmp;
//        cities.retrieve( i, tmp);
//        cout << tmp.getName() + " ";
//        cout << cities.getCityIndex( tmp.getName()) << endl;
//    }

    fileFlight.close();
    for ( int i = 1; i <= flights.getLength(); i++) {
        Flight tmp;
        flights.retrieve(i, tmp);
        matrix[cities.getCityIndex( tmp.getDepartureCity()) - 1][cities.getCityIndex( tmp.getDestinationCity()) - 1] = 1;
    }
    mTemp = new int*[cities.getLength()];

    for ( int i = 0; i < cities.getLength(); i++) {
        mTemp[i] = new int[ cities.getLength()];
    }

    for ( int i = 0; i < cities.getLength(); i++) {
        for ( int j = 0; j < cities.getLength(); j++) {
            mTemp[i][j] = matrix[i][j];
        }
    }
}

FlightMap::~FlightMap() {
    for ( int i = 0; i < cities.getLength(); i++) {
        delete [] matrix[i];
    }
    delete [] matrix;

    for ( int i = 0; i < cities.getLength(); i++) {
        delete [] mTemp[i];
    }
    delete [] mTemp;
}

void FlightMap::displayAllCities() const {
    string displayCities = "";
    for ( int i = 1; i < cities.getLength(); i++) {
        City tmp;
        cities.retrieve(i, tmp);
        displayCities = displayCities + tmp.getName() + ", ";
    }
    City tmp;
    cities.retrieve( cities.getLength(), tmp);
    displayCities = displayCities + tmp.getName();
    cout << displayCities << endl;
}

void FlightMap::displayAdjacentCities( const string cityName) const {
    cout << cityName << " -> ";
    for ( int i = 0; i < cities.getLength(); i++) {
        City tmp;
        cities.retrieve( i + 1, tmp);
        if ( tmp.getName().compare( cityName) == 0) {
            int index = cities.getCityIndex( tmp.getName());
            for ( int k = 0; k < cities.getLength(); k++) {
                if ( matrix[index - 1][k] == 1) {
                    City tmp2;
                    cities.retrieve( k + 1, tmp2);
                    cout << tmp2.getName() << ", ";
                }
            }
            cout << endl;
            return;
        }
    }
}

void FlightMap::displayFlightMap() const {
    for ( int i = 1; i <= cities.getLength(); i++) {
        City tmp;
        cities.retrieve( i, tmp);
        displayAdjacentCities( tmp.getName());
    }
}

void FlightMap::findFlights( const string deptCity, const string destCity ) const {
    cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;

    pathFound = false;
    int counter = 0;
    Stack s;
    s.push( City(deptCity));

    while ( !s.isEmpty()) {
        City tmp;
        s.getTop( tmp);
        if ( tmp.getName().compare( destCity) == 0) {
            counter++;
            pathFound = true;
            Stack temp;
            while ( !s.isEmpty()) {
                City tempTop;
                s.pop( tempTop);
                temp.push( tempTop);
            }
            int totalCost = 0;

            City top;
            temp.getTop( top);
            s.push( top);
            string leastCostFlight = "";
            while ( top.getName().compare( destCity) != 0) {
                temp.pop();

                City newCity;
                temp.getTop( newCity);
                if ( newCity.getName().compare( destCity) != 0)
                    s.push( newCity);

                for ( int i = 1; i <= flights.getLength(); i++) {
                    Flight flightTmp;
                    flights.retrieve( i, flightTmp);
                    if ( flightTmp.getDepartureCity().compare( top.getName()) == 0 && flightTmp.getDestinationCity().compare( newCity.getName()) == 0) {
                        cout <<  "Flight #" << flightTmp.getId() << " from " << flightTmp.getDepartureCity() << " to "
                                  << flightTmp.getDestinationCity() << " Cost: " << flightTmp.getCost() << " TL" << endl;
                        totalCost = totalCost + flightTmp.getCost();
                        if ( flightTmp.getDepartureCity().compare( deptCity) == 0)
                            leastCostFlight = leastCostFlight + " " + flightTmp.getDepartureCity() + " -> " + flightTmp.getDestinationCity();
                        else
                            leastCostFlight = leastCostFlight +" -> " + flightTmp.getDestinationCity();
                        break;
                    }
                }
                temp.getTop( top);
            }

            cout << "Total cost .......... " << totalCost << " TL" << endl;
            cout << endl;
            if ( counter == 1) {
                minCost = totalCost;
                minFlight = leastCostFlight;
            }
            else if ( counter > 1) {
                if ( totalCost < minCost) {
                    minCost = totalCost;
                    minFlight = leastCostFlight;
                }
            }
        }

        s.getTop( tmp);
        int unvisited = getUnvisited( cities.getCityIndex( tmp.getName()) - 1);
        City check;
        cities.retrieve( unvisited, check);
        while ( s.isCyclic( check.getName())) {
            matrix[ cities.getCityIndex( tmp.getName()) - 1][ cities.getCityIndex( check.getName()) - 1] = 0;
            unvisited = getUnvisited( cities.getCityIndex( tmp.getName()) - 1);
            if ( unvisited == -1)
                break;
            cities.retrieve( unvisited, check);
        }
        if ( unvisited == -1) {
            City popped;
            s.pop( popped);
            int index = cities.getCityIndex( popped.getName()) - 1;
            for ( int i = 0; i < cities.getLength(); i++) {
                matrix[ index][i] = mTemp[ index][i];
            }
        }
        else {
            City tmp2;
            cities.retrieve( unvisited, tmp2);
            City stackTop;
            s.getTop( stackTop);
            s.push( tmp2);
            matrix[ cities.getCityIndex( stackTop.getName()) - 1][ cities.getCityIndex( tmp2.getName()) - 1] = 0;
//            if ( tmp2.getName().compare( destCity) != 0)
//                cities.setVisited( unvisited);
        }
    }
    if ( !pathFound) {
        cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << endl;
    }

    for ( int i = 0; i < cities.getLength(); i++) {
        for( int j = 0; j < cities.getLength(); j++) {
            matrix[i][j] = mTemp[i][j];
        }
    }
}

void FlightMap::findLeastCostFlight( const string deptCity, const string destCity ) const {
    findFlights( deptCity, destCity);
    if ( pathFound) {
        cout << "A least cost path from " << deptCity << " to " << destCity << " is " << minFlight << " and its cost is " << minCost << " TL" << endl;
        cout << endl;
    }

}

void FlightMap::runFlightRequests( const string requestFile ) const {
    string request;
    ifstream file;

    string deptCity = "";
    string destCity = "";
    file.open( requestFile.c_str());
    while ( file.eof() == false) {
        getline( file, request, '\n');
        stringstream ss( request);
        getline( ss, deptCity, ',');
        getline( ss, destCity, '\n');
        findLeastCostFlight( deptCity, destCity);
    }
    file.close();
}

int FlightMap::getUnvisited( int mIndex) const {
    for ( int i = 0; i < cities.getLength(); i++) {
        if ( matrix[mIndex][i] == 1){
            return (i+1);
//            City tmp;
//            cities.retrieve( i + 1, tmp);
//            if ( !tmp.getMarked()) {
//                return (i + 1);
//            }
        }
    }
    return -1;
}





