#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double RATE = 1.5; // in millimeters per year
     
    for (int year = 0; year <= 25; year++) {
        cout << setprecision(1) << fixed;
        cout << "Year " << year << ": Ocean Level Change: +" << year * RATE << "mm\n";
    }

    return 0;
}
