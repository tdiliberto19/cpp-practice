#include <iostream>
using namespace std;

// Function prototye
int getTotal(int[], int );

int main()
{
   // A constant for the array size
   const int SIZE = 5;

   // An array initialized with values
   int numbers[SIZE] = { 2, 4, 6, 8, 10 };

   // A variable to hold the sum of the elements
   int sum;

   // Get the sum of the elements.
   sum = getTotal(numbers, SIZE);

   // Display the sum of the array elements.
   cout << "The sum of the array elements is "
        << sum << endl;

   return 0;
}

// The getTotal function accepts an Integer array, and the
// array's size as arguments. It returns the total of the
// array elements.
int getTotal(int arr[], int size)
{
   // Accumulator, initialized to 0
   int total = 0;
   
   // Calculate the total of the array elements.
   for (int index = 0; index < size; index++)
   {
      total = total + arr[index];
   }

   // Return the total.
   return total;
}
