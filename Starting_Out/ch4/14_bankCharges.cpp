#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int checks;
    double balance, fees = 10.0;

    cout << "How much money is in your bank account? ";
    cin >> balance;
    cout << "How many checks did you write this month? ";
    cin >> checks;

    if (balance < 400)
        fees += 15;

    if (checks >= 0 && checks < 20)
        fees += checks * 0.1;
    else if (checks >= 20 && checks < 40)
        fees += checks * 0.08;
    else if (checks >= 40 && checks < 60)
        fees += checks * 0.06;
    else if (checks >= 60)
        fees += checks * 0.04;
    else {
        cout << "You cannot input a negative number of checks.\n";
        exit(0);
    }
    
    cout << setprecision(2) << fixed;
    cout << "Your service fees for the month are $" << fees << endl;

    return 0;
}
