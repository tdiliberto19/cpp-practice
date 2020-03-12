#include <iostream>

using namespace std;

int main() {
    int counter = 1;
    double calPerMin = 3.6;

    while (counter <= 6) {
        cout << "Calories burned after " << counter * 5 << " minutes: " << calPerMin * counter * 5;
        counter++;
    }

    return 0;
}
