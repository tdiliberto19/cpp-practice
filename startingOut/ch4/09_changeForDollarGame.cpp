#include <iostream>

using namespace std;

int main() {
    const double PENNY = 0.01, NICKEL = 0.05, DIME = 0.1, QUARTER = 0.25;
    int pennies, nickels, dimes, quarters, total;

    cout << "Please enter the following quantities: \n";
    cout << "Pennies: ";
    cin >> pennies;
    cout << "Nickels: ";
    cin >> nickels;
    cout << "Dimes: ";
    cin >> dimes;
    cout << "Quarters: ";
    cin >> quarters;

    total = (pennies * PENNY) + (nickels * NICKEL) + (dimes * DIME) + (quarters * QUARTER);

    if (total == 1)
        cout << "Congratulations, you won by making a dollar!\n";
    else
        cout << "Sorry, you didn't win (hint: its just a dollar!)\n";

    return 0;
}
