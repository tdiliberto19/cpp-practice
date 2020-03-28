// This program displays a stair-step pattern.
#include <iostream>
using namespace std;

int main()
{
   const int NUM_STEPS = 6;
      
    for (int r = 0; r < NUM_STEPS; r++)
    {
       for (int c = 0; c < r; c++)
       {
          cout << " ";
       }
      cout << "#" << endl;
    }
   return 0;
}
