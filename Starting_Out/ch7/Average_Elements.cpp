/**
    Averages elements of array

    @author Timothy Diliberto
    @version 1.1 4/27/2020
    @param array[] Array containing elements to average
           size Number of elements in array / to divide by
    @return average Average of elements in array
*/

#include "Arrays.h"

double averageElements(double array[], int size) {
    double total = 0,
           average;

    for (int index = 0; index < size; index++)
        total += array[index];

    average = total / size;

    return average;
}
