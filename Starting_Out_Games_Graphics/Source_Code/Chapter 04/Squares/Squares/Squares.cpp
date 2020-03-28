// This program prints a table showing the squares
// of the numbers 1 through 10.
#include <iostream>
using namespace std;

int main()
{
   const int MAX_VALUE = 10;

   // Display the table headings.
   cout << "Number\t\tSquare" << endl;

   for (int number = 1; number <= MAX_VALUE; number++)
   {
      cout << number << "\t\t" 
          << (number * number) << endl;
   }
   return 0;
}
