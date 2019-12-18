#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int NUM_OF_MONTHS = 3;
    double rainfall1, rainfall2, rainfall3, average;
    string month1, month2, month3;

    cout << "Please enter 3 different months to determine average rainfall: ";
    cin >> month1 >> month2 >> month3;
    cout << "Please enter the amount of rainfall (in inches) for " << month1 << ": ";
    cin >> rainfall1;
    cout << "Please enter the amount of rainfall for " << month2 << ": ";
    cin >> rainfall2;
    cout << "Please enter the amount of rainfall for " << month3 << ": ";
    cin >> rainfall3;

    average = (rainfall1 + rainfall2 + rainfall3) / NUM_OF_MONTHS;

    cout << setprecision(2) << fixed;
    cout << "The average rainfall for " + month1 + ", " + month2 + ", and " + month3 + " is "
         << average << " inches.\n";

    return 0;
}
