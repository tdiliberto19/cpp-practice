#include <iostream>
using namespace std;

int main()
{
	// Declare variables
	double retailPrice,
		   discount,
		   salePrice;

	// Get the retail price and discount.
	cout << "Enter the item's retail price: ";
	cin >> retailPrice;
	cout << "Enter the amount of the discount: ";
	cin >> discount;

	// Calculate and display the sale price.
	salePrice = retailPrice - discount;
	cout << "The sale price is: " << salePrice << endl;
	return 0;
}
