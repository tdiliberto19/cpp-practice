#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double celsius, fahrenheit;

    cout << "Enter a temperture in celsius to convert to fahrenheit: ";
    cin >> celsius;

    fahrenheit = 9 / 5 * celsius + 32;

    cout << setprecision(4);
    cout << celsius << "C is " << fahrenheit << "F\n";

    return 0;
}
