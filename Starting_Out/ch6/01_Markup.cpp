/**
    description

    @author Timothy Diliberto
    @version 1.0 3/28/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

double calculateRetail(double, double);

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

double calculateRetail(double wholesale, double markup) {
    double retail = wholesale * (1 + markup / 100.0);

    return retail;
}
