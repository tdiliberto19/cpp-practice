/**
    Serendipity Booksellers' POS Software Package
    Main Menu Screen Style

    @author Timothy Diliberto
    @version 2.0 3/28/2020
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
        cout << "Please choose an option on the menu: ";
        cin >> choice;
    }

    cout << endl
         << "You chose " << choice << endl;

    return 0;
}
