#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double RECOMMENDED = 0.8;
    double cost, insurance;
    
    cout << "What is the replacement cost of your building? ";
    cin >> cost;

    insurance = cost * RECOMMENDED;

    cout << setprecision(2) << fixed;
    cout << "You should insure your building with at least $" << insurance << endl;

    return 0;
}
