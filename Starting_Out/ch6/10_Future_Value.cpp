/**
    Calculates the future balance based on a given starting balance in a savings account

    @author Timothy Diliberto
    @version 1.0 4/6/2020
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double futureValue(double, double, int);

// Controls the flow of the program

int main() {
    int years;
    double present_value,
           monthly_interest,
           future_value;

    cout << "Please enter the starting amount to be desposited into this account: ";
    cin >> present_value;
    cout << "Enter the monthly interest rate (as percentage): ";
    cin >> monthly_interest;
    cout << "Enter the number of years you'll let your deposit sit: ";
    cin >> years;

    future_value = futureValue(present_value, monthly_interest, years);

    cout << setprecision(2) << fixed
         << "After " << years << " years, your deposit of $" << present_value << " will reach $" << future_value
         << endl;

    return 0;
}

/**
    Calculates the FUTURE VALUE of a savings account assuming the constant MONTHLY INTEREST RATE over YEARS and a
    starting balance of STARTING VALUE.

    @param starting_value Desired value for the savings account to reach
           monthly_interest Annual interest rate on the account
           years Number of years the money will sit in the account
    @return present_value Required starting balance
*/

double futureValue(double starting, double interest, int years) {
    double future = starting * pow(1 + (interest / 100), static_cast<double>(years));

    return future;
}
