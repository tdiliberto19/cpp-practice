#include <iostream>

using namespace std;

int main() {
    int num1, num2;

    cout << "Please enter two different numbers: ";
    cin >> num1 >> num2;

    if (num1 > num2)
        cout << num1 << " is greater than " << num2 << endl;
    else if (num2 > num1)
        cout << num2 << " is greater than " << num1 << endl;
    else
        cout << "The numbers are the same size.\n";

    return 0;
}
