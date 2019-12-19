#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const int AVERAGE = 4;
    const double PI = 3.14159, SLICE_AREA = 14.125;
    int people, minimumSlices;
    double diameter, radius, area, slices, minimumPies;

    cout << "How many people will be attending the party? ";
    cin >> people;
    cout << "Please enter the diameter of the pizzas to be ordered (in inches): ";
    cin >> diameter;

    radius = diameter / 2;
    area = PI * radius * radius;

    slices = area / SLICE_AREA;
    minimumSlices = people * AVERAGE;
    minimumPies = minimumSlices / slices;
    
    cout << setprecision(1) << fixed;
    cout << "You will need approximately " << ceil(minimumPies) << " pies\n";

    return 0;
}
