#include <iostream>
using namespace std;

// Function prototypes
void getGrossPay(double &);
void getBonuses(double &);
void showGrossPayContrib(double);
void showBonusContrib(double);

// Gloabal variable declaration
double CONTRIBUTION_RATE = 0.05;

// Definition of the main function
int main()
{
   // Variables
   double annualGrossPay, // To hold the annual gross pay
          totalBonuses;   // To hold the total bonuses

   // Get the annual gross pay.
   getGrossPay(annualGrossPay);

   // Get the total of the bonuses.
   getBonuses(totalBonuses);

   // Display the contribution for the gross pay.
   showGrossPayContrib(annualGrossPay);

   // Display the contribution for the bonuses.
   showBonusContrib(totalBonuses);
   return 0;
}

// The getGrossPay function gets the user's
// annual gross pay and assigns it to the
// grossPay reference parameter.
void getGrossPay(double &grossPay)
{
   cout << "Enter the annual gross pay: ";
   cin >> grossPay;
}

// The getBonuses function gets the amount
// of bonuses and assigns it to the bonuses
// reference parameter.
void getBonuses(double &bonuses)
{
   cout << "Enter the amount of bonuses: ";
   cin >> bonuses;
}

// The showGrossPayContrib function accepts
// the gross pay as an argument and displays
// the retirement contribution for gross pay.
void showGrossPayContrib(double grossPay)
{
   double contrib = grossPay * CONTRIBUTION_RATE;
   cout << "Contribution for the gross pay: $"
       << contrib << endl;
}

// The showBonusContrib function accepts
// the bonus amount as an argument and displays
// the retirement contribution for bonuses.
void showBonusContrib(double bonuses)
{
   double contrib = bonuses * CONTRIBUTION_RATE;
   cout << "Contribution for bonuses: $"
       << contrib << endl;
}
