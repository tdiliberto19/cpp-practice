#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double weight, distance, price;

    cout << "How much does the package weigh (in kg)? ";
    cin >> weight;
    cout << "How far is the package to be shipped (in mi)? ";
    cin >> distance;
    
    if (weight <= 0 || weight > 20) {
        cout << "The weight given cannot be accepted. Please enter a weight between 0 and 20kg.\n";
        exit(0);
    }

    if (distance < 10 || distance > 3000) {
        cout << "The distance given cannot be accepted. Please enter a distance between 10 and 3000 mi.\n";
        exit(0);
    }

    if (weight > 0 && weight <= 2)
        price = ceil(distance / 500) * 1.1;
    else if (weight > 2 && weight <= 6)
        price = ceil(distance / 500) * 2.2;
    else if (weight > 6 && weight <= 10)
        price = ceil(distance / 500) * 3.7;
    else if (weight > 10 && weight <= 20)
        price = ceil(distance / 500) * 4.8;

    cout << setprecision(2) << fixed;
    cout << "The total cost of shipping your package is $" << price << endl;

    return 0;
}
