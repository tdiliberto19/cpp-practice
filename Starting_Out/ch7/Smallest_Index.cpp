/**
    Returns the index of the smallest element in an array given its size

    @author Timothy Diliberto
    @version 1.1 4/27/2020
    @param array[] Array to be processed
           size Size of the array
    @return smallest_index Index of element with smallest value
*/

#include "Arrays.h"

int smallestIndex(double array[], int size) {
    double smallest_value = array[0],
         smallest_index = 0;

    for (int index = 1; index < size; index++) {
        if (array[index] < smallest_value) {
            smallest_value = array[index];
            smallest_index = index;
        }
    }

    return smallest_index;
}
