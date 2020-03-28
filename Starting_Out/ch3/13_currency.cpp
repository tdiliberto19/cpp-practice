#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double YEN_PER_DOLLAR = 98.93, EUROS_PER_DOLLAR = 0.74;
    double dollars;

    cout << "Enter a dollar amount to convert: ";
    cin >> dollars;

    cout << "$" << dollars << " USD is equal to " << dollars * YEN_PER_DOLLAR << " Yen\n";
    cout << "$" << dollars << " USD is equal to " << dollars * EUROS_PER_DOLLAR << " Euros\n";

    return 0;
}
