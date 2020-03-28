// This program demonstrates string input.
#include <iostream>
#include <string> 
using namespace std;

int main()
{
	string name;

	// Get the user's name.
	cout << "Enter your name: ";
	cin >> name;

	// Display the user's name.
	cout << "Your name is: " 
		 << name << endl;
	return 0;
}
