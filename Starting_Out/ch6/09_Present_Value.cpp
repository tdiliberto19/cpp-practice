/**
    Calculates the starting balance required to reach a desired amaount in a savings account

    @author Timothy Diliberto
    @version 1.0 4/6/2020
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double presentValue(double, double, int);

// Controls the flow of the program

int main() {
    int years;
    double future_value,
           annual_interest,
           present_value;

    cout << "Please enter the desired amount to be earned from this account: ";
    cin >> future_value;
    cout << "Enter the annual interest rate (as percentage): ";
    cin >> annual_interest;
    cout << "Enter the number of years you'll let your deposit sit: ";
    cin >> years;

    present_value = presentValue(future_value, annual_interest, years);

    cout << setprecision(2) << fixed
         << "You must deposit $" << present_value << " to reach $" << future_value << " in " << years
         << " years\n";

    return 0;
}

/**
    Calculates the PRESENT VALUE of a savings account assuming the constant ANNUAL INTEREST RATE over YEARS and a
    desired balance of FUTURE VALUE.

    @param future_value Desired value for the savings account to reach
           annual_interest Annual interest rate on the account
           years Number of years the money will sit in the account
    @return present_value Required starting balance
*/

double presentValue(double future, double interest, int years) {
    double starting = future / pow(1 + (interest / 100), static_cast<double>(years));

    return starting;
}
