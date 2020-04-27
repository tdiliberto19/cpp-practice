/**
    Obtains 10 values for an array, then determines the largest and smallest of the values

    @author Timothy Diliberto
    @version 1.1 4/26/2020
*/

#include <iostream>

using namespace std;

// Controls the flow of the program

int largestElement(int [], int);
int smallestElement(int [], int);

int main() {
    const int NUM_ELEMS = 10;
    int index = 1,
        largest,
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
