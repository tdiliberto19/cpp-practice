#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int numPayments;
    double loan, interestRate, sub, monthlyPayment, amountPaid, interestPaid;

    cout << "Please enter the amount of the loan: ";
    cin >> loan;
    cout << "Enter the monthly interest rate: ";
    cin >> interestRate;
    cout << "Enter the number of payments: ";
    cin >> numPayments;

    sub = pow((1 + interestRate), numPayments);
    monthlyPayment = loan * ((interestRate * sub) / (sub - 1));
    amountPaid = monthlyPayment * numPayments;
    interestPaid = amountPaid - loan;

    cout << setprecision(2) << fixed;
    cout << "\nLoan Amount:           $" << setw(10) << loan << endl;
    cout << "Monthly Interest Rate: " << setw(10) << interestRate * 100 << "%\n";
    cout << "Number of Payments:     " << setw(10) << numPayments << endl;
    cout << "Monthly Payment:       $" << setw(10) << monthlyPayment << endl;
    cout << "Amount Paid Back:      $" << setw(10) << amountPaid << endl;
    cout << "Interest Paid:         $" << setw(10) << interestPaid << endl;

    return 0;
}
