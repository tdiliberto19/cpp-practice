#include <iostream>
using namespace std;

// Function prototype
void showSum(int, int);

// Definition of the main function
int main()
{
   cout << "The sum of 12 and 45 is:" << endl;
   showSum(12, 45);
   return 0;
}

// Definition of the showSum function
void showSum(int num1, int num2)
{
   int result = num1 + num2;
   cout << result << endl;
}
