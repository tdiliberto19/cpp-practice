#include <iostream>

using namespace std;

int main() {
    const int NUM_OF_VALUES = 5;
    double a = 28,
           b = 32,
           c = 37,
           d = 24,
           e = 33,
           sum;

    sum = a + b + c + d + e;

    cout << "Average of values is " << sum / NUM_OF_VALUES << endl;

    return 0;
}
