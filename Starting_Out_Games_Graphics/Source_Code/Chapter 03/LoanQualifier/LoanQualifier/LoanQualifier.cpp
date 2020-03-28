// This program determines whether a bank customer
// qualifies for a loan.
#include <iostream>
using namespace std;

int main()
{
   // Variables
   double salary;   // Applicant's salary
   int yearsOnJob;  // Years on the job 

   // Constants
   const double MIN_SALARY = 30000.0;  // Minimum salary
   const int MIN_YEARS = 2;            // Minimum years

   // Get the applicant's salary.
   cout << "Enter your annual salary: ";
   cin >> salary;

   // Get the applicant's years on the current job.
   cout << "Enter the number of years on your current job: ";
   cin >> yearsOnJob;


   // Determine whether the customer qualifies.
   if (salary >= MIN_SALARY)
   {
      if (yearsOnJob >= MIN_YEARS)
      {
         cout << "You qualify for the loan." << endl;
      }
      else
      {
         cout << "You must have been on your current" << endl;
         cout << "job for at least " << MIN_YEARS 
              << " years to qualify." << endl;
      }
   }
   else
   {
      cout << "You must earn at least $" << MIN_SALARY
           << " to qualify." << endl;
   }
   return 0;
}
