#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int minA = 450, minB = 900;
    const double costA = 39.99, costB = 59.99, costC = 69.99, perMinA = 0.45, perMinB = 0.4;
    int minutes, month;
    double totalA, totalB;
    char choice;

    cout << "Select a mobile service package? (please enter the letter)\n";
    cout << "Package A: 450 minutes for $39.99/month. $0.45/min for additional minutes.\n";
    cout << "Package B: 900 minutes for $59.99/month. $0.40/min for additional minutes.\n";
    cout << "Package C: Unlimited minutes for $69.99/month.\n";
    cin >> choice;

    cout << "How many minutes did you use this month? ";
    cin >> minutes;

    cout << "Which month's minutes are being recorded? (please enter the numeric value) ";
    cin >> month;

    if (minutes < 0) {
        cout << "Minutes cannot be negative\n";
        exit(0);
    }

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (minutes > 44640) {
                cout << "Minutes input exceeds minutes in month\n";
                exit(0);
            }
        case 4:
        case 6:
        case 9:
        case 11:
            if (minutes > 43200) {
                cout << "Minutes input exceeds minutes in month\n";
                exit(0);
            }
        case 2:
            if (minutes > 40320) {
                cout << "Minutes input exceeds minutes in month\n";
                exit(0);
            }
    }

    if (minutes <= minA)
        totalA = costA;
    else
        totalA = costA + perMinA * (minutes - minA);

    if (minutes <= minB)
        totalB = costB;
    else
        totalB = costB + perMinB * (minutes - minB);

    cout << setprecision(2) << fixed;

    switch (choice) {
        case 'a':
        case 'A':
            cout << "Your monthly bill is $" << totalA << endl;
            if (totalB < totalA)
                cout << "If you chose Package B, you could have saved $" << totalA - totalB << endl;
            if (costC < totalA)
                cout << "If you chose Package C, you could have saved $" << totalA - costC << endl;
            break;
        case 'b':
        case 'B':
            cout << "Your monthly bill is $" << totalB << endl;
            if (totalA < totalB)
                cout << "If you chose Package A, you could have saved $" << totalB - totalA << endl;
            if (costC < totalB)
                cout << "If you chose Package C, you could have saved $" << totalB - costC << endl;
            break;
        case 'c':
        case 'C':
            cout << "Your monthly bill is $" << costC << endl;
            if (totalA < costC)
                cout << "If you chose Package A, you could have saved $" << costC - totalA << endl;
            if (totalB < costC)
                cout << "If you chose Package B, you could have saved $" << costC - totalB << endl;
            break;
        default:
            cout << "Please pick a valid package: A, B, or C.\n";
            exit(0);
    }

    return 0;
}
