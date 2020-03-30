/**
    Prints a table of Fahrenheit and Celsius temperatures. Uses a loop to call the function CELSIUS for the
    values of 0-20 and prints each line to the screen.

    @author Timothy Diliberto
    @version 1.0 3/30/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

int celsius(int);

// Controls the flow of the program

int main() {
    
    cout << " --------\n"
         << "| F || C |\n"
         << " --------\n";

    for (int fahrenheit = 0; fahrenheit <= 20; fahrenheit++)
        cout << "|" << setw(3) << fahrenheit << "||" << setw(3) << celsius(fahrenheit) << "|\n";
}

/**
    Converts FAHRENHEIT to CELSIUS.

    @param fahrenheit a temperature in fahrenheit
    @return the fahrenheit temperature in celsius
*/

int celsius(int fahrenheit) {
    double celsius = (5.0 / 9.0) * (fahrenheit - 32.0);

    return static_cast<int>(celsius);
}
