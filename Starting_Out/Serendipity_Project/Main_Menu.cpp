/**
    Serendipity Booksellers' POS Software Package
    Main Menu Screen Style

    @author Timothy Diliberto
    @version 3.0 3/28/2020
*/

#include <iostream>

using namespace std;

int main() {
    int choice;
    
    cout << "   Serendipity Booksellers  \n"
         << "          Main Menu         \n"
         << "1. Cashier Module\n"
         << "2. Inventory Database Module\n"
         << "3. Report Module\n"
         << "4. Exit\n"
         << endl
         << "Enter Your Choice: ";
    cin >> choice;

    while (choice < 1 || choice > 4) {
        cout << "Please enter a number in the range 1-4: ";
        cin >> choice;
    }

    switch (choice) {
        case 1: cout << "You chose 1\n";
                break;
        case 2: cout << "You chose 2\n";
                break;
        case 3: cout << "You chose 3\n";
                break;
        case 4: cout << "You chose 4\n";
    }

    return 0;
}
