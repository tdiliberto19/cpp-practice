/**
    Serendipity Booksellers' POS Software Package
    Reports Screen Style

    @author Timothy Diliberto
    @version 2.0 3/28/2020
*/

#include <iostream>

using namespace std;

int main() {
    int choice;
    
    cout << "   Serendipity Booksellers  \n"
         << "           Reports          \n"
         << "1. Inventory Listings\n"
         << "2. Inventory Wholesale Value\n"
         << "3. Inventory Retail Value\n"
         << "4. Listing by Quantity\n"
         << "5. Listing by Cost\n"
         << "6. Listing by Age\n"
         << "7. Return\n"
         << endl
         << "Enter Your Choice: ";
    cin >> choice;

    while (choice < 1 || choice > 7) {
        cout << "Please choose an option on the menu: ";
        cin >> choice;
    }

    cout << "You chose " << choice << endl;

    return 0;
}
