/**
    Sums elements of array

    @author Timothy Diliberto
    @version 1.0 4/27/2020
    @param array[] Array containing elements to be summed
    @return total Sum of elements of array
*/

#include "Arrays.h"

double sumElements(double array[], int size) {
    double total = 0;

    for (int index = 0; index < size; index++)
        total += array[index];

    return total;
}
