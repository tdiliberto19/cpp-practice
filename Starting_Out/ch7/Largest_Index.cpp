/**
    Returns the largest element of an element in an array given its size

    @author Timothy Diliberto
    @version 1.1 4/27/2020
    @param array[] Array to be processed
           size Size of the array
    @return largest_index Index of element with largest value
*/

#include "Arrays.h"

int largestIndex(int array[], int size) {
    int largest_value = array[0],
        largest_index;

    for (int index = 1; index < size; index++) {
        if (array[index] > largest_value) {
            largest_value = array[index];
            largest_index = index;
        }
    }

    return largest_index;
}

int largestIndex(double array[], int size) {
    double largest_value = array[0];
    int largest_index;

    for (int index = 1; index < size; index++) {
        if (array[index] > largest_value) {
            largest_value = array[index];
            largest_index = index;
        }
    }

    return largest_index;
}
