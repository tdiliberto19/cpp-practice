#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    int total_hours;
    double speed;

    cout << "What is the speed of the vehicle (in mph)? \n";
    cin >> speed;
    cout << "How many hours has it traveled? \n";
    cin >> total_hours;

    while (speed <= 0) {
        cout << "Please enter a non-negative number: \n";
        cin >> speed;
    }
    while (total_hours < 1) {
        cout << "Please enter at least 1 hour: \n";
        cin >> total_hours;
    }

    for (int hours = 1; hours <= total_hours; hours++) {
        cout << setprecision(2) << fixed; 
        cout << "Odometer after " << hours << " hour(s): " << speed * hours << " miles\n";
    }

    return 0;
}
