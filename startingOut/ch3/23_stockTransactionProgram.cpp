#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int STOCKS = 1000;
    const double COMMISSION = 0.02;
    double stockValue = 45.50, money, commission, difference = 0;

    money = STOCKS * stockValue;
    commission = money * COMMISSION;
    difference -= money + commission;

    cout << setprecision(2) << fixed;
    cout << "Joe paid $" << money << " for the stocks\n";
    cout << "He also paid $" << commission << " in commission\n";

    stockValue = 56.90;
    money = STOCKS * stockValue;
    commission = money * COMMISSION;
    difference += money - commission;

    cout << "Joe sold the stock for $" << money << endl;
    cout << "He paid the stockbrocker $" << commission << " in commission\n";
    cout << "Overall, Joe's net gain/loss was $" << difference << endl;

    return 0;
}
