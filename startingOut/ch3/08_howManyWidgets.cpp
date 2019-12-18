#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double WEIGHT = 12.5;
    double pallet, total, numWidgets;

    cout << "How much does the pallet weigh by itself? ";
    cin >> pallet;
    cout << "How much does the pallet weigh with the widgets? ";
    cin >> total;

    numWidgets = (total - pallet) / WEIGHT;

    cout << setprecision(0);
    cout << "There are approximately " << numWidgets << " widgets on the pallet\n";

    return 0;
}
