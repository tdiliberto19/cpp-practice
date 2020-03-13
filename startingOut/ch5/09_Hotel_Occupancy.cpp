/**
    Asks the user for the number of floors as well as occupied and unoccupied rooms. It then
    produces a list of rooms per floor as well as a total percentage of vacancy.

    @author Timothy Diliberto
    @version 1.0 3/12/2020
*/

#include <iostream>

using namespace std;

int main() {
    int floors,
        rooms,
        occupied;
    double total_rooms = 0,
           total_occupied = 0;

    cout << "How many floors are in your hotel? ";
    cin >> floors;

    while (floors < 1) {
        cout << "Please enter at least 1 floor: ";
        cin >> floors;
    }

    for (int floor = 1; floor <= floors; floor++) {
        if (floor == 13)
            continue;

        cout << "How many rooms are on floor " << floor << "? ";
        cin >> rooms;

        while (rooms < 10) {
            cout << "Please enter at least 10 rooms: ";
            cin >> rooms;
        }

        cout << "How many of those rooms are occupied? ";
        cin >> occupied;

        while (occupied > rooms) {
            cout << "Please enter a number less than or equal to " << rooms << ": ";
            cin >> occupied;
        }

        total_rooms += rooms;
        total_occupied += occupied;
    }

    cout << "There are " << total_rooms << " rooms in this hotel, " << total_occupied << " of "
         << "which are occupied. The percent of occupied rooms is "
         << total_occupied / total_rooms * 100 << "%.\n";

    return 0;
}
