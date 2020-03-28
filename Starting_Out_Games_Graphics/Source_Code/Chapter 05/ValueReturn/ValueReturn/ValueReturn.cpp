#include <iostream>
using namespace std;

// Function prototypes
int sum(int, int);

// Definition of the main function
int main()
{
   // Variables
   int userAge,       // The user's age
       friendAge,     // A friend's age
       combinedAge;   // The combined age

   // Get the user's age.
   cout << "What is your age? ";
   cin >> userAge;

   // Get a friend's age.
   cout << "What is your friend's age? ";
   cin >> friendAge;

   // Get the combined age.
   combinedAge = sum(userAge, friendAge);

   // Display the combined age.
   cout << "Your combined age is "
        << combinedAge << " years." << endl;
   return 0;
}

// The sum function accepts two int
// arguments and returns their sum.
int sum(int num1, int num2)
{
    return num1 + num2;
}
