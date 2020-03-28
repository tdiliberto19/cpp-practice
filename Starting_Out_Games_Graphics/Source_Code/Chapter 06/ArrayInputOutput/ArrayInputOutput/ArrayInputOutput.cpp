#include <iostream>
using namespace std;

int main()
{
   const int SIZE = 3;   // Constant for array size
   int hours[SIZE];      // Array to hold hours

   // Get the hours worked by employee 1.
   cout << "Enter the hours worked by employee 1: ";
   cin >> hours[0];
   
   // Get the hours worked by employee 2.
   cout << "Enter the hours worked by employee 2: ";
   cin >> hours[1];
   
   // Get the hours worked by employee 3.
   cout << "Enter the hours worked by employee 3: ";
   cin >> hours[2];

   // Display the values in the array.
   cout << "The hours you entered are:" << endl;
   cout << hours[0] << endl;
   cout << hours[1] << endl;
   cout << hours[2] << endl;
   return 0;
}
