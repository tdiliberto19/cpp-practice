// This program displays a rectangular pattern
// of asterisks.
#include <iostream>
using namespace std;

int main()
{
   int rows, cols;

   // Get the number of rows and columns.
   cout << "How many rows? ";
   cin >> rows;
   cout << "How many columns? ";
   cin >> cols;

   // Display the pattern.
    for (int r = 0; r < rows; r++)
    {
       for (int c = 0; c < cols; c++)
       {
         cout << "*";
       }
       cout << endl;
    }
   return 0;
}
