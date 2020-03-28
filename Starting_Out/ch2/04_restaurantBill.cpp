#include <iostream>

using namespace std;

int main() {
    const double TAX_RATE = 0.0675,
                 TIP_RATE = 0.2;
    double bill = 88.67, tax, tip, total;

    tax = bill * TAX_RATE;
    tip = (bill + tax) * TIP_RATE;
    total = bill + tax + tip;

    cout << "Meal cost: $" << bill << endl;
    cout << "Tax amount: $" << tax << endl;
    cout << "Tip amount: $" << tip << endl;
    cout << "Total bill: $" << total << endl;

    return 0;
}
