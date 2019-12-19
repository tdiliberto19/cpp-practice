#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double PI = 3.14159, SLICE_AREA = 14.125;
    double diameter, radius, area, slices;

    cout << "Please enter the diameter of the pizza (in inches): ";
    cin >> diameter;

    radius = diameter / 2;
    area = PI * radius * radius;

    slices = area / SLICE_AREA;

    cout << setprecision(1) << fixed;
    cout << "You can have approximately " << slices << " slices\n";

    return 0;
}
