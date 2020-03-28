#include <iostream>
using namespace std;

int main()
{
    // Declare a constant for the array size.
   const int SIZE = 100;

   // Declare an array.
   int values[SIZE];

   // Declare a variable to hold the number of items
   // that are actually stored in the array.
   int count = 0;

   // Declare a variable to hold the user's input.
   int number;

   // Prompt the user to enter a number. If the user enters
   // -1 we will stop accepting input.
   cout << "Enter a number or -1 to quit: ";
   cin >> number;

   // If the input is not -1 and the array is not
   // full, process the input.
   while (number != -1 && count < SIZE)
   {
      // Store the input in the array.
      values[count] = number;

      // Increment count.
      count++;

      // Prompt the user for the next number.
      cout << "Enter a number or -1 to quit: ";
      cin >> number;
   }
   
   // Display the values stored in the array.
   cout << "Here are the numbers you entered:" << endl;
   for (int index = 0; index < count; index++)
   {
      cout << values[index] << endl;
   }
   return 0;
}
