/**
    Averages elements of array

    @author Timothy Diliberto
    @version 1.1 4/27/2020
    @param array[] Array containing elements to average
           size Number of elements in array / to divide by
    @return average Average of elements in array
*/

#include "Arrays.h"

// For double array

double averageElements(double array[], int size) {
    double total = 0,
           average;

    for (int index = 0; index < size; index++)
        total += array[index];

    average = total / size;

    return average;
}

// For double 2D array

double averageElements(double array[][], int rows, int cols) {
    double total = 0.0,
           average;

    for (int row_index = 0; row_index < rows; row_index++) {
        for (int col_index = 0; col_index < cols; col_index++)
            total += array[row_index][col_index];

    average = total / (rows * cols);

    return average;
}
