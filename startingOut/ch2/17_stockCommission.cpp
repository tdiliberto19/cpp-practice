#include <iostream>

using namespace std;

int main() {
    const double COMMISSION = 0.02;
    int shares = 750, price = 35;
    double total, commission;

    total = shares * price;
    commission = total * COMMISSION;

    cout << "Total (w/o commission): " << total << endl;
    cout << "Total Commission: " << commission << endl;
    cout << "Total: " << total + commission << endl;

    return 0;
}
