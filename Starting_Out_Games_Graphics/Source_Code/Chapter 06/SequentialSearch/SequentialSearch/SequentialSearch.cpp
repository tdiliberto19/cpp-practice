#include <iostream>
using namespace std;

int main()
{
   // Constant for the array size.
   const int SIZE = 10;

   // Declare an array to hold test scores.
   int scores[SIZE] = { 87, 75, 98, 100, 82,
                        72, 88, 92, 60,  78 };

   // Declare a Boolean variable to act as a flag.
   bool found;

   // Declare a variable to step through the array.
   int index;

   // The flag must initially be set to False.
   found = false;

   // Set the counter variable to 0.
   index = 0;

   // Step through the array searching for a
   // score equal to 100.
   while (found == false && index < SIZE)
   {
      if (scores[index] == 100)
      {
        found = true;
      }
      else
      {
        index = index + 1;
      }
   }

   // Display the search results.
   if (found)
   {
      cout << "You earned 100 on test number "
           << (index + 1) << endl;
   }
   else
   {
      cout << "You did not earn 100 on any test." << endl;
   }
   return 0;
}
