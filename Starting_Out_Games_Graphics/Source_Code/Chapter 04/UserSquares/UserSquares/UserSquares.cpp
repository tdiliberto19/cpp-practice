// This program prints a table of numbers
// and their squares.
#include <iostream>
using namespace std;

int main()
{
   int upperLimit;

   // Get the upper limit.
   cout << "This program displays numbers, starting at 1," << endl;
   cout << "and their squares. How high should I go? ";
   cin >> upperLimit;

   // Display the table headings.
   cout << "Number\t\tSquare" << endl;

   // Display the values.
   for (int number = 1; number <= upperLimit; number++)
   {
      cout << number << "\t\t" 
          << (number * number) << endl;
   }
   return 0;
}
