#include <iostream>

using namespace std;

int main() {

    int price = 2500, year = 0;
    double rate = 1.04;

    while (year < 6) {
        price *= rate;
        cout << "The fee for year " << year + 2020 << " is $" << price << endl;
        year += 1;
    }
    
    return 0;
}
