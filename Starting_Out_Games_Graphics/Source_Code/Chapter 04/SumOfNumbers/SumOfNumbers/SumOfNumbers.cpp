// This program calculates the sum of a series of numbers.
#include <iostream>
using namespace std;

int main()
{
   // Variables
   int number,      // To hold each number
       total = 0;   // Accumlator, initialized with 0

   // Constant for the number of numbers
   const int MAX_NUMS = 5;

   // Explain the program's purpose.
   cout << "This program calculates the total" << endl;
   cout << "of " << MAX_NUMS << " numbers." << endl;

   // Get the numbers and accumulate them.
   for (int counter = 0; counter < MAX_NUMS; counter++)
   {
      cout << "Enter a number: ";
      cin >> number;
      total += number;
   }

   // Display the total.
   cout << "The total is: " << total << endl;
   return 0;
}
