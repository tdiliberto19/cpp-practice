#include <iostream>

using namespace std;

int main() {
    const double STATE_SALES = 0.04,
                 COUNTY_SALES = 0.02;
    int purchase = 95;
    double salesTax;

    salesTax = (purchase * STATE_SALES) + (purchase * COUNTY_SALES);

    cout << "Total sales tax is $" << salesTax << endl;

    return 0;
}
