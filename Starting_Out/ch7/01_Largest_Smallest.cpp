/**
    Obtains 10 values for an array, then determines the largest and smallest of the values

    @author Timothy Diliberto
    @version 2.0 4/27/2020
*/

#include <iostream>
#include "Arrays.h"

using namespace std;

// Controls the flow of the program

int main() {
    const int NUM_ELEMS = 10;
    int largest,
        smallest,
        num_array[NUM_ELEMS];

    cout << "Please enter values into the array:\n";
    for (int &number : num_array)
        cin >> number;

    largest = largestElement(num_array, NUM_ELEMS);
    smallest = smallestElement(num_array, NUM_ELEMS);

    cout << "--------------------\n"
         << "Largest Element: " << largest << endl
         << "Smallest Element: " << smallest << endl;

    return 0;
}
