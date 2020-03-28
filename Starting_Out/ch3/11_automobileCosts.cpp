#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double carLoan, insurance, gas, oil, tires, maintenance, totalCost;

    cout << "Please enter the monthly costs for each of the following:\n";
    cout << "Car Loan Payment: ";
    cin >> carLoan;
    cout << "Insurance: ";
    cin >> insurance;
    cout << "Gas: ";
    cin >> gas;
    cout << "Oil: ";
    cin >> oil;
    cout << "Tires: ";
    cin >> tires;
    cout << "Maintenance: ";
    cin >> maintenance;

    totalCost = carLoan + insurance + gas + oil + tires + maintenance;

    cout << setprecision(2) << fixed;
    cout << "\nThe total monthly cost to upkeep your vehicle is $" << totalCost << endl;

    return 0;
}
