#include <iostream>
using namespace std;

int main()
{
    // Declare a constant for the array size.
   const int SIZE = 4;

   // Declare an array.
   double scores[SIZE] = { 92.5, 81.6, 65.7, 72.8 };

   // Declare and initialize an accumulator variable.
   double total = 0.0; 

   // Declare a variable to hold the average.
   double average; 

   // Step through the array, adding each element to
   // the accumulator.
   for (int index = 0; index < SIZE; index++)
   {
      total += scores[index];
   }

   // Calculate the average.
   average = total / SIZE;

   // Display the average.
   cout << "The average is " <<  average << endl;
   return 0;
}
