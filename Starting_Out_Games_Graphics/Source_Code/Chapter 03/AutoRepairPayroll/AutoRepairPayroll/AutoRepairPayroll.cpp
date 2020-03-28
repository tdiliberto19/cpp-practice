// This program calculates payroll, including overtime
// if the hours worked are more than 40.
#include <iostream>
using namespace std;

int main()
{
   // Variables
   double hoursWorked,     // Number of hours worked
          payRate,         // Hourly pay rate
          overtimeHours,   // Number of overtime hours
          overtimePay,     // Amount of overtime pay
          grossPay;        // Amount of gross pay

   // Constants
   const double BASE_HOURS = 40.0;    // Base hours per week
   const double OT_MULTIPLIER = 1.5;  // Overtime multiplier

   // Get the number of hours worked.
   cout << "Enter the number of hours worked: ";
   cin >> hoursWorked;

   // Get the hourly pay rate.
   cout << "Enter the hourly pay rate: ";
   cin >> payRate;


   // Calculate the gross pay.
   if (hoursWorked > BASE_HOURS)
   {
      // Calculate the number of overtime hours worked.
      overtimeHours = hoursWorked - BASE_HOURS;

      // Calculate the amount of overtime pay.
      overtimePay = overtimeHours * payRate * OT_MULTIPLIER;

      // Calculate the gross pay.
      grossPay = BASE_HOURS * payRate + overtimePay;
   }
   else
   {
      // Calculate the gross pay (no overtime).
      grossPay = hoursWorked * payRate;
   }

   // Display the gross pay.
   cout << "The gross pay is $" << grossPay << endl;
   return 0;
}
