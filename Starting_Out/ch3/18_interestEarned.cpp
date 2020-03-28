#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int timesCompounded;
    double principal, interestRate, amount, interest;

    cout << "Please enter the initial amount deposited: ";
    cin >> principal;
    cout << "Enter the interest rate (as a decimal): ";
    cin >> interestRate;
    cout << "Enter the number of times the interest is compounded per year: ";
    cin >> timesCompounded;

    amount = principal * pow((1 + interestRate / timesCompounded), timesCompounded);
    interest = amount - principal;

    cout << setprecision(2) << fixed;
    cout << "\nInterest Rate:     " << setw(8) << interestRate * 100 << "%\n";
    cout << "Times Compounded:   " << setw(8) << timesCompounded << endl;
    cout << "Principal Amount:  $" << setw(8) << principal << endl;
    cout << "Interest:          $" << setw(8) << interest << endl;
    cout << "Amount in Savings: $" << setw(8) << amount << endl;

    return 0;
}
