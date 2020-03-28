/*
	This program gets the user's age
	and displays it in a message.
*/
#include <iostream>
using namespace std;

int main()
{
	int age;

	cout << "What is your age? ";
	cin >> age;
	cout << "I would never have guessed that you are "
		 << age << " years old!" << endl;
	return 0;
}
