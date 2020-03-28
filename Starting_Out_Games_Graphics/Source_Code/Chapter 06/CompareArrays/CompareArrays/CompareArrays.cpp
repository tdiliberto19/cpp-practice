#include <iostream>
using namespace std;

int main()
{
    // Declare a constant for the array size.
   const int SIZE = 5;

   // Declare and initialize two arrays.
   int firstArray[SIZE]  = { 5, 10, 15, 20, 25 };
   int secondArray[SIZE] = { 5, 10, 15, 20, 25 };

   // Variables
   bool arraysEqual = true; // Flag variable
   int index = 0;           // To hold array subscripts

   // Determine whether the elements contain the same data.
   while (arraysEqual && index < SIZE)
   {
      if (firstArray[index] != secondArray[index])
      {
         arraysEqual = false;
      }
      index++;
   }

   // Display the results.
   if (arraysEqual)
   {
      cout << "The arrays are equal." << endl;
   }
   else
   {
      cout << "The arrays are not equal." << endl;
   }
   return 0;
}
