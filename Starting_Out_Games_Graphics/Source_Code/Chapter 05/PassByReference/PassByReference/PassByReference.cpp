#include <iostream>
using namespace std;

// Function prototype
void setToZero(int &);

int main()
{
   int value = 99;
   cout << "The value is " << value << endl;
   setToZero(value);
   cout << "Now the value is " << value << endl;
   return 0;
}

// Definition of the setToZero function
void setToZero(int &num)
{
   num = 0;
}
