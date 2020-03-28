/**
    @author Timothy Diliberto
    @version 1.0 3/24/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double budget,
           expense,
           total;

    cout << "Please enter your spending allowance for the month: ";
    cin >> budget;
    cout << "Please enter an expense (enter -1 to quit): ";
    cin >> expense;

    while (expense != -1) {
        total += expense;
        cout << "Enter another expense (-1 to quit): ";
        cin >> expense;
    }

    cout << setprecision(2) << fixed;
    if (total > budget)
        cout << "You overspent by $" << total - budget << " this month.\n";
    else if (total < budget)
        cout << "You underspent by $" << budget - total << " this month.\n";
    else
        cout << "You stuck to budget perfectly!\n";

    return 0;
}
