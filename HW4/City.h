// Author name: Efe Beydoðan
// CS201 Section 1
// Bilkent ID: 21901548

#ifndef __CITY_H
#define __CITY_H
#include <string>
using namespace std;
class List;

class City {
public:
    City();
    City( string cityName);
    ~City();
    void setName( string cityName);
    string getName() const;
    void insertCity( City city);
    void setMarked();
    bool getMarked();
    void clearMarked();
    City& operator=( const City& city);
private:
    string name;
    bool marked;
};

#endif // __CITY_H
