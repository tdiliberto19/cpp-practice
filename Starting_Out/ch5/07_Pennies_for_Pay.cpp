#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    const double PENNY = 0.01;
    int days;
    double total_earnings;

    cout << "Enter the number of days worked: ";
    cin >> days;

    while (days < 1) {
        cout << "Please enter at least 1 day: \n";
        cin >> days;
    }

    for (int day = 1; day <= days; day++) {
        cout << setprecision(2) << fixed;
        total_earnings = pow(2, day) / 200;
        cout << "Day " << day << " Earnings: $" << total_earnings << endl;
    }

    cout << "-----------------\n";
    cout << "TOTAL EARNINGS: $" << total_earnings << endl;

    return 0;
}
