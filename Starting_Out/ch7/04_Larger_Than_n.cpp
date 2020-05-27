/**
    Displays all values of an array greater than n.

    @author Timothy Diliberto
    @version 1.0 4/27/2020
*/

#include <iostream>

using namespace std;

void largerThanN(int [], int, int);

// Controls the flow of the program

int main() {
    const int SIZE = 10;
    int n = 5,
        numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    largerThanN(numbers, SIZE, n);

    return 0;
}

/**
    Literally what it says above...

    @author Timothy Diliberto
    @version 1.0 4/27/2020
*/

void largerThanN(int array[], int size, int n) {
    for (int index = 0; index < size; index++) {
        if (array[index] > n)
            cout << array[index] << " ";
    }
    cout << endl;
}
