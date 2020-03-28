#include <iostream>
using namespace std;

// Function prototype
void doubleNumber(int);

// Definition of the main function
int main()
{
   doubleNumber(4);
   return 0;
}

// Definition of the doubleNumber function
void doubleNumber(int number)
{
   int result = number *2;
   cout << result << endl;
}
