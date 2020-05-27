/**
    Returns the smallest element of an array given its size

    @author Timothy Diliberto
    @version 1.1 4/24/2020
    @param array[] Array to be processed
           size Size of the array
    @return smallest Element with smallest value
*/

#include "Arrays.h"

const int WIDTH = 100;

// For integer arrays

int smallestElement(int array[], int size) {
    int smallest = array[0];

    for (int index = 1; index < size; index++) {
        if (array[index] < smallest)
            smallest = array[index];
        index++;
    }

    return smallest;
}

// For double 2D arrays

double smallestElement(double array[][WIDTH], int rows, int cols) {
    double smallest = array[0][0];

    for (int row_index = 0; row_index < rows; row_index++) {
        for (int col_index = 0; col_index < cols; col_index++) {
            if (array[row_index][col_index] < smallest)
                smallest = array[row_index][col_index];
        }
    }

    return smallest;
}
