#include <iostream>
using namespace std;

// Function prototype
void anotherFunction();

// Gloabal variable declaration
int num = 2;

// Definition of the main function
int main()
{
   cout << "In main, num is " << num << endl;
   anotherFunction();
   cout << "Back in main, num is " << num << endl;
   return 0;
}

// Definition of anotherFunction
void anotherFunction()
{
   cout << "In anotherFunction, num is " << num << endl;
   num = 50;
   cout << "But, it is now changed to " << num << endl;
}
