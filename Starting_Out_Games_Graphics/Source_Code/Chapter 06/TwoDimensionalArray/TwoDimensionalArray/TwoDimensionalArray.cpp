#include <iostream>
#include <string>
using namespace std;

// Function prototye
int getTotal(int[], int );

int main()
{
   // Create a 2D array
   const int ROWS = 3;
   const int COLS = 4;
   int values[ROWS][COLS];

   // Counter variables for rows and columns
   int row, col;

   // Get values to store in the array.
   for (row = 0; row <= ROWS - 1; row++)
   {
      for (col = 0; col <= COLS - 1; col++)
      {
        cout << "Enter a number: " << endl;
        cin >> values[row][col];
      }
   }

   // Display the values in the array.
   cout << "Here are the values you entered." << endl;
   for (row = 0; row <= ROWS - 1; row++)
   {
      for (col = 0; col <= COLS - 1; col++)
      {
        cout << values[row][col] << endl;
      }
   }

   return 0;
}
