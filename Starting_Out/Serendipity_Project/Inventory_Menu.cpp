/**
    Serendipity Booksellers' POS Software Package
    Inventory Database Menu Screen Style

    @author Timothy Diliberto
    @version 2.0 3/28/2020
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

    cout << "You chose " << choice << endl;

    return 0;
}
