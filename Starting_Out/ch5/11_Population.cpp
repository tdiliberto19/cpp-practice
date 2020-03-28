/**
    Obtains information about the number of base organisms as well as their growth rate and the
    number of days observed. The program then outputs the total population for each day of the
    study.
    
    @author Timothy Diliberto
    @version 1.0 3/12/2020
*/

#include <iostream>

using namespace std;

int main() {
    int organisms,
        days;
    double percent_increase;

    cout << "Enter the starting number of organisms: ";
    cin >> organisms;
    cout << "Enter their daily population increase (as a percentage between 0 and 100): ";
    cin >> percent_increase;
    cout << "Enter the number of days the organisms' growth was observed: ";
    cin >> days;
    
    cout << "Day 0: " << organisms << " organisms\n";
    for (int day = 1; day <= days; day++) {
        organisms *= 1.0 + percent_increase / 100.0;
        cout << "Day " << day << ": " << organisms << " organisms\n";
    }

    return 0;
}
