#include <iostream>
using namespace std;

int main()
{
    // Declare a constant for the array size.
   const int SIZE = 5;

   // Declare an array.
   int numbers[SIZE] = { 8, 1, 12, 6, 2 };

   // Declare a variable to hold the lowest value, and
   // initialize it with the first value in the array.
   int lowest = numbers[0];

   // Step through the rest of the array, beginning at
   // element 1. When a value less than lowest is found,
   // assign that value to lowest.
   for (int index = 1; index < SIZE; index++)
   {
      if (numbers[index] < lowest)
      {
         lowest = numbers[index];
      }
   }

   // Display the lowest value.
   cout << "The lowest value is " << lowest << endl;
   return 0;
}
