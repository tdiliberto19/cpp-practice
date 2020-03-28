#include <iostream>
using namespace std;

int main()
{
   const int SIZE = 3;   // Constant for array size
   int hours[SIZE];      // Array to hold hours

   // Get the hours for each employee.
   for (int index = 0; index < SIZE; index++)
   {
      cout << "Enter the hours worked by employee "
           << index + 1 << ": ";
      cin >> hours[index];
   }
   
   // Display the values in the array.
   cout << "The hours you entered are:" << endl;
   for (int index = 0; index < SIZE; index++)
   {
      cout << hours[index] << endl;
   }
   return 0;
}
