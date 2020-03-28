#include <iostream>
using namespace std;
int main()
{
   const int NUM_EMPLOYEES = 3;   // Number of employees
   int hours[NUM_EMPLOYEES];      // Holds hours worked
   double payRate[NUM_EMPLOYEES]; // Holds pay rates
   double grossPay;               // Holds gross pay

   // Input the hours worked and the hourly pay rate.
   cout << "Enter the hours worked by " << NUM_EMPLOYEES
        << " employees and their" << endl;
   cout << "hourly pay rates." << endl;

   for (int index = 0; index < NUM_EMPLOYEES; index++)
   {
      cout << "Hours worked by employee #" 
           << index+1 << ": ";
      cin >> hours[index];

      cout << "Hourly pay rate for employee #" 
           << index+1 << ": ";
      cin >> payRate[index];
   }

   // Display each employee's gross pay.
   cout << "Gross pay for each employee:" << endl;
   for (int index = 0; index < NUM_EMPLOYEES; index++)
   {
      grossPay = hours[index] * payRate[index];
      cout << "Employee #" << index + 1
           << ": $" << grossPay << endl;
   }
   return 0;
}
