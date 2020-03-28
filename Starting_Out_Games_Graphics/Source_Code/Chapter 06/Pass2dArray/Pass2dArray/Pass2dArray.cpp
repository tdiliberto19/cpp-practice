#include <iostream>
using namespace std;

// Global constants
const int COLS = 4;      // Number of columns in each array
const int ARR1_ROWS = 3; // Number of rows in array1
const int ARR2_ROWS = 4; // Number of rows in array2

// Function prototype
void showArray(const int [][COLS], int); 

int main()
{
   // Declare and initialize two arrays.
   int array1[ARR1_ROWS][COLS] = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12}};

   int array2[ARR2_ROWS][COLS] = {{10, 20, 30, 40},
                                  {50, 60, 70, 80},
                                  {90, 100, 110, 120},
                                  {130, 140, 150, 160}};
   
   // Display the contents of array1.
   cout << "The contents of array1 are:\n";
   showArray(array1, ARR1_ROWS);

   // Display the contents of array2.
   cout << "The contents of array2 are:\n";
   showArray(array2, ARR2_ROWS);
   return 0;
}

// Function Definition for showArray
// The first argument is a two-dimensional int array with
// COLS columns. The second argument, rows, specifies the
// number of rows in the array. The function displays the 
// array's contents.
void showArray(const int arr[][COLS], int rows)
{
   for (int x = 0; x < rows; x++)
   {
      for (int y = 0; y < COLS; y++)
      {
         cout << arr[x][y] << "\t";
      }
      cout << endl;
   }
}
