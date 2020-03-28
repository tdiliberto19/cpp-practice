#include <iostream>
using namespace std;

int main()
{
   const int SIZE = 6;   // Constant for array size
   int hours[SIZE];      // Array to hold employee's hours
   double payRate,       // To hold pay rate
          grossPay;      // To hold gross pay

   // Get the hourly pay rate for all employees.
   cout << "Enter the hourly pay rate: ";
   cin >> payRate;

   // Get the hours for each employee.
   for (int index = 0; index < SIZE; index++)
   {
      cout << "Enter the hours worked by employee "
           << index + 1 << ": ";
      cin >> hours[index];
   }
   
   // Display each employee's gross pay.
   cout << "Gross pay for each employee:" << endl;
   for (int index = 0; index < SIZE; index++)
   {
      grossPay = hours[index] * payRate;
      cout << "Employee " << index + 1
           << ": $" << grossPay << endl;
   }
   return 0;
}
