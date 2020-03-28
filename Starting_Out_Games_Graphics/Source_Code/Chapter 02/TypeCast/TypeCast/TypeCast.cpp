// This program uses a type cast to avoid integer division.
#include <iostream>
using namespace std;

int main()
{
	int books;		// Number of books to read
	int months;		// Number of months spent reading
	double perMonth;// Average number of books per month

	// Get the number of books the user plans to read.
	cout << "How many books do you plan to read? ";
	cin >> books;

	// Get the number of months it will take.
	cout << "How many months will it take you to read them? ";
	cin >> months;

	// Calculate and display the average number of
	// books per month.
	perMonth = static_cast<double>(books) / months;
	cout << "That is " << perMonth << " books per month.\n";
	return 0;
}
