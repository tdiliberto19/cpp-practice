/**
    Returns the largest element of an array given its size

    @author Timothy Diliberto
    @version 1.1 4/24/2020
    @param array[] Array to be processed
           size Size of the array
    @return largest Element with largest value
*/

#include "Arrays.h"

int largestElement(int array[], int size) {
    int largest = array[0];

    for (int index = 1; index < size; index++) {
        if (array[index] > largest)
            largest = array[index];
        index++;
    }

    return largest;
}
