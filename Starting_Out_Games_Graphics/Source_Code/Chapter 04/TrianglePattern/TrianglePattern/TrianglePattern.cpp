// This program displays a triangle pattern.
#include <iostream>
using namespace std;

int main()
{
   const int BASE_SIZE = 8;
      
    for (int r = 0; r < BASE_SIZE; r++)
    {
       for (int c = 0; c < (r+1); c++)
       {
          cout << "*";
       }
       cout << endl;
    }
   return 0;
}
