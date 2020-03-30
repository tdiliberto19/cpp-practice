/**
    @author Timothy Diliberto
    @version 1.0 3/29/2020
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double getNumAccidents(string);
void findLowest(int, int, int, int, int);

int main() {
    int north,
        south,
        east,
        west,
        central;

    north = getNumAccidents("North");
    south = getNumAccidents("South");
    east = getNumAccidents("East");
    west = getNumAccidents("West");
    central = getNumAccidents("Central");

    findLowest(north, south, east, west, central);

    return 0;
}

double getNumAccidents(string city_region) {
    double auto_accidents;

    cout << "Enter the number of auto accidents in " << city_region << " District last year: ";
    cin >> auto_accidents;

    while (auto_accidents < 0) {
        cout << "Please enter at least 0 accidents: ";
        cin >> auto_accidents;
    }

    return auto_accidents;
}

void findLowest(int north, int south, int east, int west, int central) {
    double lowest;

    if (north < south && north < east && north < west && north < central)
        cout << "The North District has the lowest number of auto accidents at " << north << endl;
    if (south < north && south < east && south < west && south < central)
        cout << "The South District has the lowest number of auto accidents at " << north << endl;
    if (west < south && west < east && west < north && west < central)
        cout << "The West District has the lowest number of auto accidents at " << north << endl;
    if (east < south && east < north && east < west && east < central)
        cout << "The East District has the lowest number of auto accidents at " << north << endl;
    if (central < south && central < east && central < west && central < north)
        cout << "The Central District has the lowest number of auto accidents at " << north << endl;
}
