#include <iostream>

using namespace std;

int main() {
    int maxNum,
        sum = 0;

    cout << "Enter a positive number: ";
    cin >> maxNum;

    while (maxNum < 0) {
        cout << "Error: invalid number. Please enter a positive integer: ";
        cin >> maxNum;
    }

    for (int number = 1; number <= maxNum; number++)
        sum += number;

    cout << "The sum of all positive integers up to " << maxNum << " is " << sum << endl;

    return 0;
}
