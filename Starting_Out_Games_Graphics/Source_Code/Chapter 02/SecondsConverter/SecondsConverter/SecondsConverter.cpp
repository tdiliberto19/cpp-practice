// This program converts a number of seconds to
// hours, minutes, and seconds.
#include <iostream>
using namespace std;

int main()
{
	int totalSeconds,	// Total number of seconds
		hours,			// Number of hours
		minutes,		// Number of minutes
		seconds;		// Number of seconds

	// Get the total number of seconds.
	cout << "Enter a number of seconds: ";
	cin >> totalSeconds;

	// Calculate the number of hours.
	// Note: This calculation uses integer division.
	hours = totalSeconds / 3600;

	// Calculate the number of minutes.
	// Note: This calculation also uses integer division.
	minutes = (totalSeconds / 60) % 60;

	// Calculate the number of remaining seconds.
	seconds = totalSeconds % 60;

	// Display the results.
	cout << "Here is the time in hours, minutes, and seconds:\n"; 
	cout << "Hours: " << hours << endl;
	cout << "Minutes: " << minutes << endl;
	cout << "Seconds: " << seconds << endl;
	return 0;
}
