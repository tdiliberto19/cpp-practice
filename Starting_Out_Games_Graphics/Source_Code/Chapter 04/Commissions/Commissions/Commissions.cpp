// This program calculates sales commissions.
#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Variables
   double sales, commission;
   string keepGoing = "y";

   // Constant for the commission rate
   const double COMMISSION_RATE = 0.10;

   // Determine the commissions.
   while (keepGoing == "y")
   {
      // Get the amount of sales.
      cout << "Enter the amount of sales: ";
      cin >> sales;
   
      // Calculate the commission.
      commission = sales * COMMISSION_RATE;
   
      // Display the commission
      cout << "The commission is $" 
          << commission << endl;

      cout << "Do you want to calculate another" << endl;
      cout << "commission? (Enter y for yes): ";
      cin >> keepGoing;
   }
   return 0;
}
