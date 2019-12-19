#include <iostream>

using namespace std;

int main() {
    int month, day, year;

    cout << "Please enter a month (in numeric form): ";
    cin >> month;
    cout << "Enter a day: ";
    cin >> day;
    cout << "Enter a two-digit year: ";
    cin >> year;

    cout << month << "/" << day << "/" << year << endl;

    if (month * day == year)
        cout << "This date is magic!\n";
    else
        cout << "This date is not magic\n";

    return 0;
}
