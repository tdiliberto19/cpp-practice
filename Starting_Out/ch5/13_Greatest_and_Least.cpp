/**
    Asks the user to input a series of numbers, terminated by -99. The program will display the
    highest and lowest of these numbers.

    @author Timothy Diliberto
    @version 1.0 3/13/2020
*/

#include <iostream>

using namespace std;

int main() {
    int number,
        lowest,
        highest;

    cout << "Please enter a series of numbers, one at a time. When ready to terminate, type -99.\n";
    cin >> number;
    
    if (number == -99)
        exit(0);

    highest = lowest = number;

    cin >> number;
    while (number != -99) {
        if (number < lowest)
            lowest = number;
        if (number > highest)
            highest = number;
        cin >> number;
    }

    cout << "Highest number: " << highest << endl
         << "Lowest number: " << lowest << endl;

    return 0;
}
