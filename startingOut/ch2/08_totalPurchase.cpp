#include <iostream>

using namespace std;

int main() {
    const double SALES_TAX = 0.07;
    double item1 = 15.95,
           item2 = 24.95,
           item3 = 6.95,
           item4 = 12.95,
           item5 = 3.95,
           subtotal, salesTax, total;

    subtotal = item1 + item2 + item3 + item4 + item5;
    salesTax = subtotal * SALES_TAX;
    total = subtotal + salesTax;

    cout << "Item 1: $" << item1 << endl;
    cout << "Item 2: $" << item2 << endl;
    cout << "Item 3: $" << item3 << endl;
    cout << "Item 4: $" << item4 << endl;
    cout << "Item 5: $" << item5 << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Sales Tax: $" << salesTax << endl;
    cout << "Total: $" << total << endl;

    return 0;
}
