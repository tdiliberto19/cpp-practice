/**
    Serendipity Booksellers' POS Software Package
    Inventory Database Menu Screen Style

    @author Timothy Diliberto
    @version 3.0 3/28/2020
*/

#include <iostream>

using namespace std;

int main() {
    int choice;
    
    cout << "   Serendipity Booksellers  \n"
         << "      Inventory Database    \n"
         << "1. Lookup Book\n"
         << "2. Add Book\n"
         << "3. Edit Book Records\n"
         << "4. Delete Book\n"
         << "5. Return\n"
         << endl
         << "Enter Your Choice: ";
    cin >> choice;

    while (choice < 1 || choice > 5) {
        cout << "Please choose an option on the menu: ";
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
                break;
        case 5: cout << "You chose 5\n";
                break;
    }

    return 0;
}
