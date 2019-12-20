#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double UNIT_COST = 99.0,
                 DISCOUNT_1 = 0.2, DISCOUNT_2 = 0.3, DISCOUNT_3 = 0.4, DISCOUNT_4 = 0.5;
    int units;
    double total;

    cout << "How many units were sold? ";
    cin >> units;

    total = units * UNIT_COST;

    if (units >= 10 && units <= 19)
        total *= DISCOUNT_1;
    else if (units >= 20 && units <= 49)
        total *= DISCOUNT_2;
    else if (units >= 50 && units <= 99)
        total *= DISCOUNT_3;
    else if (units >= 100)
        total *= DISCOUNT_4;
    else if (units <= 0)
        cout << "Invalid number. Must be greater than 0\n";

    cout << setprecision(2) << fixed;
    cout << "The total cost of the purchase was $" << total << endl;

    return 0;
}

