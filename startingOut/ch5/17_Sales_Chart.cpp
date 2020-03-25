/**
    des

    @author Timothy Diliberto
    @version 1.0 3/23/2020
*/

#include <iostream>

using namespace std;

int main() {
    int sales1,
        sales2,
        sales3,
        sales4,
        sales5;

    cout << "Enter sales for store 1: ";
    cin >> sales1;
    cout << "Enter sales for store 2: ";
    cin >> sales2;
    cout << "Enter sales for store 3: ";
    cin >> sales3;
    cout << "Enter sales for store 4: ";
    cin >> sales4;
    cout << "Enter sales for store 5: ";
    cin >> sales5;

    cout << "------------------------------\n"
         << "SALES BAR CHART\n"
         << "(Each * = $100)\n"
         << "Store 1: ";
    for (int count = 1; count <= sales1 / 100; count++)
        cout << "*";
    cout << "\nStore 2: ";
    for (int count = 1; count <= sales2 / 100; count++)
        cout << "*";
    cout << "\nStore 3: ";
    for (int count = 1; count <= sales3 / 100; count++)
        cout << "*";
    cout << "\nStore 4: ";
    for (int count = 1; count <= sales4 / 100; count++)
        cout << "*";
    cout << "\nStore 5: ";
    for (int count = 1; count <= sales5 / 100; count++)
        cout << "*";
    cout << endl;

    return 0;
}
