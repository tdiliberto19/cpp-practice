/**
    @author Timothy Diliberto
    @version 1.0 3/29/2020
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double getSales(string);
void findHighest(double, double, double, double);

int main() {
    double northwest,
           northeast,
           southwest,
           southeast;

    northwest = getSales("Northwest");
    northeast = getSales("Northeast");
    southwest = getSales("Southwest");
    southeast = getSales("Southeast");

    findHighest(northwest, northeast, southwest, southeast);

    return 0;
}

double getSales(string branch_name) {
    double sales;

    cout << "Enter the monthly sales for the " << branch_name << " Branch: ";
    cin >> sales;

    while (sales < 0) {
        cout << "Please enter a positive value: ";
        cin >> sales;
    }

    return sales;
}

void findHighest(double northwest, double northeast, double southwest, double southeast) {
    double highest;

    cout << setprecision(2) << fixed;
    if (northwest > northeast && northwest > southwest && northwest > southeast)
        cout << "The Northwest Branch had the highest sales at $" << northwest << endl;
    if (northeast > northwest && northeast > southwest && northeast > southeast)
        cout << "The Northeast Branch had the highest sales at $" << northeast << endl;
    if (southwest > northwest && southwest > northeast && southwest > southeast)
        cout << "The Southwest Branch had the highest sales at $" << southwest << endl;
    if (southeast > northwest && southeast > northeast && southeast > southwest)
        cout << "The Southeast Branch had the highest sales at $" << southeast << endl;
}
