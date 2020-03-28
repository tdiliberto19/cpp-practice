/**
    @author Timothy Diliberto
    @version 1.0 3/24/2020
*/

#include <iostream>

using namespace std;

int main() {
    const int MIN_VALUE = 1,
              MAX_VALUE = 20;
    int number = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE,
        guess;

    cout << "I thought of a number between 1 and 20... try and guess it!\n"
         << "Guess: ";
    cin >> guess;

    while (guess != number) {
        if (guess > number) {
            cout << "Too high, try again!\n"
                 << "Guess: ";
            cin >> guess;
            continue;
        }

        if (guess < number) {
            cout << "Too low, try again!\n"
                 << "Guess: ";
            cin >> guess;
            continue;
        }
    }

    cout << "Good job, you got it!\n";

    return 0;
}
