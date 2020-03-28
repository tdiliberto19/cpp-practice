#include <iostream>

using namespace std;

int main() {
   int seconds; 

    cout << "Please enter a number of seconds: ";
    cin >> seconds;

    if (seconds >= 86400)
        cout << "There are " << seconds / 86400 << " days in " << seconds << " seconds\n";
    if (seconds >= 3600)
        cout << "There are " << seconds / 3600 << " hours in " << seconds << " seconds\n";
    if (seconds >= 60)
        cout << "There are " << seconds / 60 << " minutes in " << seconds << " seconds\n";

    return 0;
}
