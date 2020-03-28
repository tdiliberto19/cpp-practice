// This program demonstrates the pow function.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double radius, area;
	const double PI = 3.14159;

	// Get the circle's radius.
	cout << "Enter the circle's radius: ";
	cin >> radius;

	// Calculate and display the circle's area.
	area = PI * pow(radius, 2.0);
	cout << "The circle's area is: " << area << endl;
	return 0;
}
