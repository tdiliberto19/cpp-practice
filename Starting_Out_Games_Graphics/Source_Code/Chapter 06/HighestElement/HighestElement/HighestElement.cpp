#include <iostream>
using namespace std;

int main()
{
    // Declare a constant for the array size.
   const int SIZE = 5;

   // Declare an array.
   int numbers[SIZE] = { 8, 1, 12, 6, 2 };

   // Declare a variable to hold the highest value, and
   // initialize it with the first value in the array.
   int highest = numbers[0];

   // Step through the rest of the array, beginning at
   // element 1. When a value greater than highest is found,
   // assign that value to highest.
   for (int index = 1; index < SIZE; index++)
   {
      if (numbers[index] > highest)
      {
         highest = numbers[index];
      }
   }

   // Display the highest value.
   cout << "The highest value is " << highest << endl;
   return 0;
}
