/**
    Serendipity Booksellers' POS Software Package
    Reports Screen Style

    @author Timothy Diliberto
    @version 4.0 3/28/2020
*/

#include <iostream>

using namespace std;

int main() {
    int choice;

    do {
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
            case 6: cout << "You chose 6\n";
                    break;
            case 7: cout << "You chose 7\n";
                    break;
        }
    } while (choice != 7);

    return 0;
}
