#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int ADULT_PRICE = 10, CHILD_PRICE = 6;
    const double THEATER_SHARE = 0.2;
    int adult, child;
    double grossProfit, netBoxProfit;
    string name;

    cout << "What is the name of the movie? ";
    getline(cin, name);
    cout << "How many adult and child tickets were sold? ";
    cin >> adult >> child;

    grossProfit = (ADULT_PRICE * adult) + (CHILD_PRICE * child);
    netBoxProfit = grossProfit * THEATER_SHARE;
    
    cout << setprecision(2) << fixed;
    cout << "Movie Name:                " << name << endl;
    cout << "Adult Tickets Sold:          " << adult << endl;
    cout << "Child Tickets Sold:          " << child << endl;
    cout << "Gross Box Office Profit:    $" << grossProfit << endl;
    cout << "Net Box Office Profit:      $" << netBoxProfit << endl;
    cout << "Amount Paid to Distributor: $" << grossProfit - netBoxProfit << endl;

    return 0;
}
