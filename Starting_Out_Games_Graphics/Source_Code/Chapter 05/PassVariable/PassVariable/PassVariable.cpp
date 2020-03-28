#include <iostream>
using namespace std;

// Function prototype
void doubleNumber(int);

// Definition of the main function
int main()
{
   int value;

   cout << "Enter a value and I will double it: ";
   cin >> value;
   doubleNumber(value);
   return 0;
}

// Definition of the doubleNumber function
void doubleNumber(int number)
{
   int result = number *2;
   cout << result << endl;
}
