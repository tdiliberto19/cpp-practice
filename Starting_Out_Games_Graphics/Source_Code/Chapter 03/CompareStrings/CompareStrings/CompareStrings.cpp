// This program compares strings.
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string password;

   // Get a password from the user.
   cout << "Enter the password: ";
   cin >> password;

   // Determine whether the password is correct.
   if (password == "prospero")
   {
      cout << "Password accepted." << endl;
   }
   else
   {
      cout << "Sorry, that's the wrong password." << endl;
   }
   return 0;
}
