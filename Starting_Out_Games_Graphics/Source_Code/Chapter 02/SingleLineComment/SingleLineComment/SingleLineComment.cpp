// This program calculates gross pay.
#include <iostream>
using namespace std;

int main()
{
	double payRate;	// To hold the hourly pay rate
	int hours;		// To hold the hours worked

	// Get the hourly pay rate.
	cout << "Enter your hourly pay rate: ";
	cin >> payRate;

	// Get the number of hours worked.
	cout << "Enter the number of hours worked: ";
	cin >> hours;

	// Display the values entered.
	cout << "Here are the values that you entered:" << endl;
	cout << "Hourly pay rate: " << payRate << endl;
	cout << "Hours worked: " << hours << endl;
	return 0;
}
