#include <iostream>
#include <string>
using namespace std;

// Function prototype
string fullName(string, string, string);

// The main function
int main()
{
   // String objects
   string first,     // To hold the first name
          middle,    // To hold the middle name
          last,      // To hold the last name
          full;      // To hold the full name

   // Get the user's first name.
   cout << "Enter your first name: ";
   cin >> first;

   // Get the user's middle name.
   cout << "Enter your middle name: ";
   cin >> middle;

   // Get the user's last name.
   cout << "Enter your last name: ";
   cin >> last;

   // Get the user's full name.
   full = fullName(first, middle, last);

   // Display the user's full name.
   cout << "Your full name is " << full << endl;
   return 0;
}

// The showIntro function displays an intro screen.
string fullName(string first, string middle, string last)
{
   return first + " " + middle + " " + last;
}
