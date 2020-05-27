/**
    Returns the largest element of an array given its size

    @author Timothy Diliberto
    @version 1.1 4/24/2020
    @param array[] Array to be processed
           size Size of the array
    @return largest Element with largest value
*/

#include "Arrays.h"

const int WIDTH = 100;

// For integer array

int largestElement(int array[], int size) {
    int largest = array[0];

    for (int index = 1; index < size; index++) {
        if (array[index] > largest)
            largest = array[index];
    }

    return largest;
}

// For double 2D array

double largestElement(double array[][WIDTH], int rows, int cols) {
    double largest = array[0][0];

    for (int row_index = 0; row_index < rows; row_index++) {
        for(int col_index = 0; col_index < cols; col_index++) {
            if (array[row_index][col_index] > largest)
                largest = array[row_index][col_index];
    }

    return largest;
}
