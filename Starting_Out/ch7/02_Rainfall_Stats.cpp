/**
    Allows user to enter 12 months of rainfall data. Displays total, average monthly, and months with highest and
    lowest rainfall.

    @author Timothy Diliberto
    @version 1.0 4/27/2020
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Arrays.h"

using namespace std;

// Controls the flow of the program

int main() {
    const int MONTHS = 12,
              TOTAL_MONTHS = 12;
    int year;
    double total_rainfall,
           average_monthly_rainfall,
           highest_index,
           lowest_index,
           rainfall[MONTHS];
    string location,
           months[TOTAL_MONTHS] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    cout << "Enter your location: ";
    getline(cin, location);
    cout << "Enter a year to record rainfall: ";
    cin >> year;
    cout << "Enter total rainfall for the following months:\n";

    for (int index = 0; index < MONTHS; index++) {
        cout << "    " << months[index] << ": ";
        cin >> rainfall[index];
    }

    for (string month : months)
        cout << " " << month << "  ";
    cout << endl;

    for (double inches : rainfall)
        cout << setprecision(4) << setw(5) << inches << " ";
    cout << endl << endl;

    total_rainfall = sumElements(rainfall, MONTHS);
    average_monthly_rainfall = averageElements(rainfall, MONTHS);
    highest_index = largestIndex(rainfall, MONTHS);
    lowest_index = smallestIndex(rainfall, MONTHS);

    cout << setprecision(2) << fixed
         << "Total Rainfall in " << year << ": " << total_rainfall << " in." << endl
         << "Average Monthly Rainfall: " << average_monthly_rainfall << " in." << endl
         << "Month with Most Rainfall: " << months[static_cast<int>(highest_index)] << endl
         << "Month with Least Rainfall: " << months[static_cast<int>(lowest_index)] << endl;

    return 0;
}
