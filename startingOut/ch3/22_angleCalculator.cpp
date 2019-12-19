#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double angle;   

    cout << "Please enter an angle, in radians: ";
    cin >> angle;

    cout << setprecision(4) << fixed;
    cout << "sin(" << angle << ") = " << sin(angle) << endl;
    cout << "cos(" << angle << ") = " << cos(angle) << endl;
    cout << "tan(" << angle << ") = " << tan(angle) << endl;

    return 0;
}
