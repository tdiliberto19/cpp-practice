#include <iostream>

using namespace std;

int main() {
    const double PERCENT_EARNED = 0.58;
    int sales = 8.6E6;
    double profit;

    profit = sales * PERCENT_EARNED;

    cout << "Total profit: $" << profit << endl;

    return 0;
}
