// This program prompts the user to enter three test
// scores. It displays the average of those scores and
// and congratulates the user if the average is 95
// or greater.
#include <iostream>
using namespace std;

int main()
{
	// Variables
	double test1,		// To hold test score #1
		   test2,		// To hold test score #2
		   test3,		// To hold test score #3
		   average;		// To hold the average

	// Constant for a high average.
	const double HIGH_AVERAGE = 95.0;

	// Get the three test scores.
	cout << "Enter the score for test 1: ";
	cin >> test1;
	cout << "Enter the score for test 2: ";
	cin >> test2;
	cout << "Enter the score for test 3: ";
	cin >> test3;

	// Calculate the average test score.
	average = (test1 + test2 + test3) / 3.0;

	// Display the average.
	cout << "The average score is: " 
		 << average << endl;

	// If the average is high, congratulate
	// the user.
	if (average >= HIGH_AVERAGE)
	{
		cout << "Congratulations!" << endl;
		cout << "That's a great average!" << endl;
	}

	return 0;
}
