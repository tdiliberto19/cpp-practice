/**
    
    
    @author Timothy Diliberto
    @version 1.0 3/20/2020
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    int months;
    double balance,
           annual_interest_rate,
           monthly_interest_rate,
           deposit,
           withdrawl,
           total_deposit,
           total_withdrawl,
           interest,
           total_interest;
    ofstream writeFile;

    cout << "What is the annual interest rate on your savings account? (enter as %) ";
    cin >> annual_interest_rate;
    cout << "What is the starting balance? ";
    cin >> balance;
    cout << "How many months have passed? ";
    cin >> months;

    monthly_interest_rate = annual_interest_rate / 1200;

    for (int month = 1; month <= months; month++) {
        cout << "How much did you deposit into your account this month? ";
        cin >> deposit;

        while (deposit < 0) {
            cout << "Please enter a positive value (this will be added to your balance): ";
            cin >> deposit;
        }

        cout << "How much did you withdraw from your account this month? ";
        cin >> withdrawl;

        while (withdrawl < 0) {
            cout << "Please enter a positive value (this will be subtracted from your balance): ";
            cin >> withdrawl;
        }

        total_deposit += deposit;
        total_withdrawl += withdrawl;
        balance += deposit - withdrawl;
        interest += balance * monthly_interest_rate;
        total_interest += interest;
        balance += interest;

        if (balance < 0) {
            cout << "Your account has been suspended due to insufficient funds.\n";
            exit(0);
        }
    }

    writeFile.open("Savings_Balance.txt");
    cout << "Successfully opened file!\n";

    writeFile << setprecision(2) << fixed
         << "Total Deposited: $" << total_deposit << endl
         << "Total Withdrawn: $" << total_withdrawl << endl
         << "Total Interest Earned: $" << total_interest << endl
         << "Final Balance: $" << balance << endl;
    cout << "To view your savings balance, view the Savings_Balance.txt file in this directory!\n";

    writeFile.close();
    cout << "Successfully closed file!\n";

    return 0;
}
