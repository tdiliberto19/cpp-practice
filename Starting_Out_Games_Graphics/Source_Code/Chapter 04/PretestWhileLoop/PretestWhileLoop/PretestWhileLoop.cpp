// This program demonstrates the pretest while loop.
#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Variable to hold the temperature
   double temperature;

   // Constant for the maximum temperature
   const double MAX_TEMP = 102.5;

   // Get the substance's temperature.
   cout << "Enter the substance's temperature: ";
   cin >> temperature;

   // If necessary, adjust the thermostat.
   while (temperature > MAX_TEMP)
   {
      cout << "The temperature is too high." << endl;
      cout << "Turn the thermostat down and wait" << endl;
      cout << "five minutes. Take the temperature" << endl;
      cout << "again and enter it here: ";
      cin >> temperature;
   }

   // Remind the user to check the temperature
   // again in 15 minutes.
   cout << "The temperature is acceptable." << endl;
   cout << "Check it again in 15 minutes." << endl;
   return 0;
}
