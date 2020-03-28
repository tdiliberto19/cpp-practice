#include <iostream>
using namespace std;

int main()
{
	double payRate;
	int hours;

	cout << "Enter your hourly pay rate: ";
	cin >> payRate;
	cout << "Enter the number of hours worked: ";
	cin >> hours;

	cout << "Here are the values that you entered:" << endl;
	cout << "Hourly pay rate: " << payRate << endl;
	cout << "Hours worked: " << hours << endl;
	return 0;
}
