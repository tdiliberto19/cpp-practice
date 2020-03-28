#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Declare a constant for the array size.
   const int SIZE = 6;

   // Declare a string array initialized with values.
   string cars[SIZE] = { "BMW", "Audi", "Lamborghini",
                         "Mercedes", "Porsche", "Ferrari" };

   // Declare a variable to hold the search value.
   string searchValue;

   // Declare a Boolean variable to act as a flag.
   bool found;

   // Declare a variable to step through the array.
   int index;

   // The flag must initally be set to False.
   found = false;

   // Set the counter variable to 0.
   index = 0;

   // Get the string to search for.
   cout << "What car should I search for? ";
   cin >> searchValue;

   // Step through the array searching for
   // the specified name.
   while (found == false && index < SIZE)
   {
      if (cars[index] == searchValue)
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
      cout << "That car was found in element " 
           << index << endl;
   }
   else
   {
      cout << "That car was not found in the array." << endl;
   }
   return 0;
}
