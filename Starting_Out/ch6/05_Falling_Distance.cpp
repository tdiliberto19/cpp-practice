/**
    Calculates the distance an object would have fallen if it fell from 1-10 seconds
    
    @author Timothy Diliberto
    @version 1.0 3/30/2020
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double GRAVITY = 9.81;

double fallingDistance(int);

// Controls program flow

int main() {
    
    for (int count = 1; count <= 10; count++)
        cout << "After " << count << " second(s), an object would have fallen " <<
            fallingDistance(count) << "m\n";
}

/**
    Returns the distance, in METERS, that an object fell based on how many SECONDS in was falling

    @param seconds the number of seconds to be used in the calculation
    @return the distance in meters an object fell in a certain amount of time (in seconds)
*/

double fallingDistance(int seconds) {
    double meters = GRAVITY * pow(seconds, 2) / 2;

    return meters;
}
