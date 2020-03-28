// This program demonstrates the switch statement.
#include <iostream>
using namespace std;

int main()
{
   // Constants for the TV prices
   const double MODEL_100_PRICE = 199.99;
   const double MODEL_200_PRICE = 269.99;
   const double MODEL_300_PRICE = 349.99;

   // Constants for the TV sizes
   const int MODEL_100_SIZE = 24;
   const int MODEL_200_SIZE = 27;
   const int MODEL_300_SIZE = 32;

   // Variable for the model number
   int modelNumber;

   // Get the test score.
   cout << "Which TV are you interested in?" << endl;
   cout << "The model 100, 200 or 300? ";
   cin >> modelNumber;

   // Display the price and size.
   switch (modelNumber)
   {
   case 100:
      cout << "Price: " << MODEL_100_PRICE << endl;
      cout << "Size: " << MODEL_100_SIZE << endl;
      break;
   case 200:
      cout << "Price: " << MODEL_200_PRICE << endl;
      cout << "Size: " << MODEL_200_SIZE << endl;
      break;
   case 300:
      cout << "Price: " << MODEL_300_PRICE << endl;
      cout << "Size: " << MODEL_300_SIZE << endl;
      break;
   default:
      cout << "Invalid model number." << endl;
   }
   return 0;
}
