#include <iostream>

using namespace std;

int main() {
    const int COOKIES = 48;
    const double SUGAR = 1.5, BUTTER = 1, FLOUR = 2.75;
    int cookies;
    double ratio;

    cout << "How many cookies would you like to make? ";
    cin >> cookies;

    ratio = static_cast<double>(cookies) / COOKIES;

    cout << "You will need the following ingredients to complete the recipe: \n";
    cout << SUGAR * ratio << " cups of sugar\n"
         << BUTTER * ratio << " cups of butter\n"
         << FLOUR * ratio << " cups of flour\n";
    
    return 0;
}
