/**
    Header files for ch7 (Arrays)
    
    @author Timothy Diliberto
    @version 1.1 4/27/2020
*/

#ifndef ARRAYS_H
#define ARRAYS_H

#include <iostream>

const int LENGTH = 100,
          WIDTH = 100;

using namespace std;

int largestElement(int [], int); // Largest_Element.cpp
double largestElement(double [LENGTH][WIDTH], int, int);
int smallestElement(int [], int); // Smallest_Element.cpp
double smallestElement(double [LENGTH][WIDTH], int, int);
int largestIndex(int [], int); // Largest_Index.cpp
int largestIndex(double [], int);
int smallestIndex(int [], int); // Smallest_Index.cpp
int smallestIndex(double [], int);
double sumElements(double [], int); // Sum_Elements.cpp
double averageElements(double [], int); // Average_Elements.cpp
double averageElements(double [LENGTH][WIDTH], int, int);

#endif
