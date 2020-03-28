#include <iostream>
using namespace std;

// Function prototype
void displayMessage();

// Definition of the main function
int main()
{
   cout << "This is the main function." << endl;
   displayMessage();
   cout << "Back in the main function." << endl;
   return 0;
}

// Definition of the displayMessage function
void displayMessage()
{
   cout << "This is the displayMessage function." << endl;
}
