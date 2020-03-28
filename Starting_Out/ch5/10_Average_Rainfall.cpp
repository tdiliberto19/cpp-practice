/**
    Intakes data for rainfall each month over the course of YEARS. Then outputs number of months,
    total rainfall over the time period, and average monthly rainfall.

    @author Timothy Diliberto
    @version 1.0 3/12/2020
*/

#include <iostream>

using namespace std;

int main() {
    int years,
        total_months = 0;
    double rainfall,
           total_rainfall = 0;

    cout << "Enter the number of years to calculate average rainfall over: ";
    cin >> years;

    while (years < 1) {
        cout << "Please enter at least 1 year: ";
        cin >> years;
    }

    for (int year = 1; year <= years; year++) {
        for (int month = 1; month <= 12; month++) {
            cout << "What was the total rainfall (in inches) for month " << month << ", year "
                 << year << "? ";
            cin >> rainfall;

            while (rainfall < 0) {
                cout << "Please enter a positive value for rainfall: ";
                cin >> rainfall;
            }

            total_rainfall += rainfall;
            total_months++;
        }
    }

    cout << "Number of months recorded: " << total_months << endl
         << "Total rainfall over period: " << total_rainfall << " inches\n"
         << "Average monthly rainfall: " << total_rainfall / static_cast<double>(total_months)
         << " inches\n";

    return 0;
}
