#include <iostream>

using namespace std;

int main() {
    double gallons, miles, mpg;

    cout << "Enter the number of gallons your vehicle can hold: ";
    cin >> gallons;
    cout << "Enter the number of miles your vehicle can travel on a full tank: ";
    cin >> miles;

    mpg = miles / gallons;

    cout << "You vehicle will get approximately " << mpg << " miles per gallon.\n";

    return 0;
}
