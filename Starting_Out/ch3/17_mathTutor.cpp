#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int MIN_VALUE = 100, MAX_VALUE = 999;
    int num1, num2, answer;
    unsigned seed = time(0);

    srand(seed);

    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    answer = num1 + num2;

    cout << "Add the following numbers. Press ENTER to check your answer.\n";
    cout << setw(4) << num1 << endl;
    cout << "+" << num2 << endl;
    cout << "----";
    cin.get();
    cout << setw(4) << answer << endl;

    return 0;
}
