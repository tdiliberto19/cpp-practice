#include <iostream>

using namespace std;

int main() {
    int month, year;
    bool leapYear;

    cout << "Please enter a numeric month (1-12), and the year: ";
    cin >> month >> year;

    if (!(year % 100) && !(year % 400) || !(year % 4))
        leapYear = true;
    else
        leapYear = false;

    switch (month) {
        case 1:
            cout << "There are 31 days in January\n";
            break;
        case 2:
            if (leapYear)
                cout << "There are 29 days in February\n";
            else
                cout << "There are 28 days in February\n";
            break;
        case 3:
            cout << "There are 31 days in March\n";
            break;
        case 4:
            cout << "There are 30 days in April\n";
            break;
        case 5:
            cout << "There are 31 days in May\n";
            break;
        case 6:
            cout << "There are 30 days in June\n";
            break;
        case 7:
            cout << "There are 31 days in July\n";
            break;
        case 8:
            cout << "There are 31 days in August\n";
            break;
        case 9:
            cout << "There are 30 days in September\n";
            break;
        case 10:
            cout << "There are 31 days in October\n";
            break;
        case 11:
            cout << "There are 30 days in November\n";
            break;
        case 12:
            cout << "There are 31 days in December\n";
            break;
    }

    return 0;
}
