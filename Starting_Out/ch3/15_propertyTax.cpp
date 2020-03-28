#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double ASSESSMENT_RATE = 0.6, TAX_RATE = 0.75 / 100; //$0.75 per $100
    double propertyValue, assessmentValue, propertyTax;

    cout << "What is your property valued at? ";
    cin >> propertyValue;

    assessmentValue = propertyValue * ASSESSMENT_RATE;
    propertyTax = assessmentValue * TAX_RATE;

    cout << setprecision(2) << fixed;
    cout << "Assessment Value: $" << assessmentValue << endl;
    cout << "Property Tax:     $" << propertyTax << endl;

    return 0;
}
