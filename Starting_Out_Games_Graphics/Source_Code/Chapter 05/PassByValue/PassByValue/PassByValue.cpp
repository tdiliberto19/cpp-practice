#include <iostream>
using namespace std;

// Function Prototype
void changeMe(int);

int main()
{
   int number = 99;

   // Display the value in number.
   cout << "In main, number is " << number << endl;
   
   // Call changeMe, passing the value in number
   // as an argument.
   changeMe(number);
   
   // Display the value in number again.  
   cout << "Now back in main again." << endl;
   cout << "The number variable is " << number << endl;
   return 0;
}

// Definition of the changeMe function
void changeMe(int myValue)
{
   // Change the value of myValue to 0.
   myValue = 0;
   
   // Display the value in myValue.
   cout << "In changeMe, the value is " << myValue << endl;
}
