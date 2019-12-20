#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int MIN_VALUE = 100, MAX_VALUE = 999;
    int num1, num2, answer, response;
    unsigned seed = time(0);

    srand(seed);

    num1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
    num2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    answer = num1 + num2;

    cout << "Add the following numbers. Enter your answer and press ENTER to check.\n";
    cout << setw(4) << num1 << endl;
    cout << "+" << num2 << endl;
    cout << "----\n ";
    cin >> response;

    if (response == answer)
        cout << "That's correct! Congratulations!\n";
    else
        cout << "That is incorrect. The correct answer was " << answer << endl;

    return 0;
}
