// This program gets a numeric test score from the
// user and displays the corresponding letter grade.
#include <iostream>
using namespace std;

int main()
{
   int testScore;

   // Get the test score.
   cout << "Enter your test score: ";
   cin >> testScore;

   // Determine the letter grade.
   if (testScore >= 90)
   {
      cout << "Your gade is A." << endl;
   }
   else
   {
      if (testScore >= 80)
      {
         cout << "Your gade is B." << endl;
      }
      else 
      {
         if (testScore >= 70)
         {
            cout << "Your gade is C." << endl;
         }
         else 
         {
            if (testScore >= 60)
            {
               cout << "Your gade is D." << endl;
            }
            else
            {
               cout << "Your gade is F." << endl;
            }
         }
      }
   }
   return 0;
}
