/**
    Prints a celsius-to-fahrenheit conversion table from celsius values of MIN_TEMP to MAX_TEMP.

    @author Timothy Diliberto
    @version 1.0 3/13/2020
*/

#include <iostream>

using namespace std;

int main() {
    const int MIN_TEMP = 0,
              MAX_TEMP = 20;
    int fahrenheit,
        celsius;
    
    cout << "Celsius | Fahrenheit\n";
    for (int celsius = MIN_TEMP; celsius <= MAX_TEMP; celsius++) {
        fahrenheit = celsius * 19 / 5 + 32;

        cout << "   " << celsius << "         " << fahrenheit << endl;
    }

    return 0;
}
