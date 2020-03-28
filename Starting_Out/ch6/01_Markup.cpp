/**
    Obtains the wholesale cost and markup percentage, then processes the retail price through the
    function calculateRetail(). The program then displays the retail price.

    @author Timothy Diliberto
    @version 1.0 3/28/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

double calculateRetail(double, double);

// Controls operation of the whole program

int main() {
    double wholesale_cost,
           markup_percentage,
           retail_price;

    cout << "Enter the wholesale cost and markup (as a percentage)\n"
         << "Wholesale: ";
    cin >> wholesale_cost;
    cout << "Markup: ";
    cin >> markup_percentage;

    retail_price = calculateRetail(wholesale_cost, markup_percentage);

    cout << setprecision(2) << fixed
         << "Retail Price: $" << retail_price << endl;

    return 0;
}

/**
    Receives the wholesale cost and markup percentage of an item, then calculates the retail price

    @param wholesale the wholesale value of the item
           markup the markup percentage on the item
    @return the retail price of the item
*/

double calculateRetail(double wholesale, double markup) {
    double retail = wholesale * (1 + markup / 100.0);

    return retail;
}
