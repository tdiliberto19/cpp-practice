#include <iostream>

using namespace std;

int main() {
    const int COOKIES = 10, CALORIES = 300;
    double cookies, ratio;

    cout << "How many cookies did you really eat? ";
    cin >> cookies;

    ratio = cookies / COOKIES;

    cout << "You consumed about " << CALORIES * ratio << endl;

    return 0;
}
