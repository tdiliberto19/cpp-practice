/**
    Serendipity Booksellers' POS Software Package
    Cashier Screen Style

    Obtains information about a book purchase from Serendipity. Then produces a receipt of purchase
    including the subtotal, tax and total.

    @author Timothy Diliberto
    @version 2.0 3/28/2020
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const double TAX_RATE = 0.06,
              QUANTITY_WIDTH = 3,
              ISBN_WIDTH = 13,
              PRICE_WIDTH = 7;
    int quantity;
    double price,
           subtotal,
           tax,
           total;
    string date,
           isbn,
           title;

    cout << "Fill out the following form for check-out:\n"
         << "Date (mm/dd/yyyy): ";
    getline(cin, date);
    cout << "Quantity: ";
    cin >> quantity;
    cin.ignore();
    cout << "ISBN: ";
    getline(cin, isbn);
    cout << "Title: ";
    getline(cin, title);
    cout << "Price: ";
    cin >> price;
    cout << endl;

    subtotal = price * quantity;
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;
    
    cout << setprecision(2) << fixed
         << "Serendipity Booksellers\n"
         << endl
         << "Date: " << date << endl
         << endl
         << "Qty ISBN          Title" << setfill(' ') << setw(title.length() + 10) << "Price   Total\n"
         << setfill('-') << setw(QUANTITY_WIDTH + ISBN_WIDTH + title.length() + PRICE_WIDTH + 12) << "-\n"
         << setfill(' ') << left                << setw(QUANTITY_WIDTH) << quantity << " "
                         << left                << setw(ISBN_WIDTH)     << isbn << " "
                         << left                << setw(title.length()) << title << " "
                         << left << "$" << left << setw(PRICE_WIDTH)    << price
                                 << "$"                                 << price * quantity << endl
         << endl << endl
         << "          Subtotal: $" << subtotal << endl
         << "          Tax: $" << tax << endl
         << "          Total: $" << total << endl
         << endl
         << "Thank you for shopping at Serendipity!\n";

    return 0;
}
