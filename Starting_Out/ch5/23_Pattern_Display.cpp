/**
    @author Timothy Diliberto
    @version 1.0 3/27/2020
*/

#include <iostream>

using namespace std;

int main() {
    const int HALF_HEIGHT = 10,
              BASE = 1;

    for (int height = BASE; height <= HALF_HEIGHT; height++) {
        int width = 1;

        while (width <= height) {
            cout << "+";
            width++;
        }
        cout << endl;
    }

    for (int height = HALF_HEIGHT; height >= BASE; height--) {
        int width = 1;

        while (width <= height) {
            cout << "+";
            width++;
        }
        cout << endl;
    }

    return 0;
}
