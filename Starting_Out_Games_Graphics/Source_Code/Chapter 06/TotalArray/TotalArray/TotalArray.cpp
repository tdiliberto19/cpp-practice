#include <iostream>
using namespace std;

int main()
{
   // Declare a constant for the array size.
   const int SIZE = 5;

   // Create an int array.
   int numbers[SIZE] = { 2, 4, 6, 8, 10 };

   // Declare and initialize an accumulator variable.
   int total = 0; 

   // Step through the array, adding each element to
   // the accumulator. 
   for (int index = 0; index < SIZE; index++)
   {
      total += numbers[index];
   }

   // Display the total.
   cout << "The total is " << total << endl;
   return 0;
}
