#include <iostream>

using namespace std;

int main() {
    int gasTank = 20;
    double mpgTown = 23.5,
           mpgHighway = 28.9,
           distance;

    distance = gasTank * mpgTown;
    cout << "The car gets " << distance << " miles per gallon in town.\n";

    distance = gasTank * mpgHighway;
    cout << "The car gets " << distance << " miles per gallon on highway.\n";

    return 0;
}
