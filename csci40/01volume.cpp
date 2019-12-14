#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const double pi = 3.14159;
    double radius, surfaceArea, volume;

    cout << "Please enter a radius: ";
    cin >> radius;

    surfaceArea = 4 * pi * pow(radius, 2);
    volume = 4.0 / 3.0 * pi * pow(radius, 3);

    cout << "The surface area of the sphere is " << surfaceArea << endl;
    cout << "The volume of the sphere is " << volume << endl;

    return 0;
}
