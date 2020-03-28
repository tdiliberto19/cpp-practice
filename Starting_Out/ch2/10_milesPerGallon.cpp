#include <iostream>

using namespace std;

int main() {
    int gallons = 15,
        miles = 375,
        mpg;

    mpg = miles / gallons;

    cout << "The car gets " << mpg << " miles per gallon.\n";

    return 0;
}
