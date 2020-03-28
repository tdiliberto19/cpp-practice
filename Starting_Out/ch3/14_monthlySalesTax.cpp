#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const double STATE_TAX = 0.04, COUNTY_TAX = 0.02;
    int year;
    double totalCollected, productSales, totalSalesTax, stateTax, countyTax;
    string month;
    
    cout << "Please enter the month and year of the report: ";
    cin >> month >> year;
    cout << "Please enter the total amount collected at the register: ";
    cin >> totalCollected;

    productSales = totalCollected / (1 + STATE_TAX + COUNTY_TAX);
    totalSalesTax = totalCollected - productSales;
    stateTax = productSales * STATE_TAX;
    countyTax = productSales * COUNTY_TAX;

    cout << setprecision(2) << fixed;
    cout << "\nDate: " << month << " " << year << endl;
    cout << "--------------------\n";
    cout << "Total Collected:   $" << setw(10) << totalCollected << endl;
    cout << "Sales:             $" << setw(10) << productSales << endl;
    cout << "County Sales Tax:  $" << setw(10) << countyTax << endl;
    cout << "State Sales Tax:   $" << setw(10) << stateTax << endl;
    cout << "Total Sales Tax:   $" << setw(10) << totalSalesTax << endl;

    return 0;
}
