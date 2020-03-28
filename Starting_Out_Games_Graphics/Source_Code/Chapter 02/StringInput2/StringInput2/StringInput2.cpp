// This program demonstrates string input.
#include <iostream>
#include <string> 
using namespace std;

int main()
{
	string firstName, lastName;

	// Get the user's first and last names.
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;

	// Display the user's first and last names.
	cout << "Your name is: " 
		 << firstName << " " 
		 << lastName << endl;
	return 0;
}
