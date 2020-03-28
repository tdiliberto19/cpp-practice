/**
    @author Timothy Diliberto
    @version 1.0 3/26/2020
*/

#include <iostream>

using namespace std;

int main() {
    int dimension;

    cout << "Enter a number between 1 and 14: ";
    cin >> dimension;

    while (dimension < 1 || dimension > 14) {
        cout << "Enter a number between 1 and 14: ";
        cin >> dimension;
    }

    for (int height = 1; height <= dimension; height++) {
        for (int width = 1; width <= dimension; width++)
            cout << "*";
        cout << endl;
    }

    return 0;
}
