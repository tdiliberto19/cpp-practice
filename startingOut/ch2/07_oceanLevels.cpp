#include <iostream>

using namespace std;

int main() {
    const double RISE_RATE = 1.5; // Measured in milliliters

    cout << "The change in ocean level after 5 years is " << 5 * RISE_RATE << endl;
    cout << "The change in ocean level after 7 years is " << 7 * RISE_RATE << endl;
    cout << "The change in ocean level after 10 years is " << 10 * RISE_RATE << endl;

    return 0;
}
