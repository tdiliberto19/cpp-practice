#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double ASSESSMENT_RATE = 0.6;
    double propertyValue, taxRate, assessmentValue, propertyTax;

    cout << "What is your property valued at? ";
    cin >> propertyValue;
    cout << "What is the tax rate per $100 assessed value? ";
    cin >> taxRate;

    assessmentValue = propertyValue * ASSESSMENT_RATE;
    propertyTax = (assessmentValue - 5000) * (taxRate / 100);

    cout << setprecision(2) << fixed;
    cout << "Assessment Value:       $" << setw(10) << assessmentValue << endl;
    cout << "Senior Taxed Value:     $" << setw(10) << assessmentValue - 5000 << endl;
    cout << "Annual Property Tax:    $" << setw(10) << propertyTax << endl;
    cout << "Quarterly Property Tax: $" << setw(10) << propertyTax / 4 << endl;

    return 0;
}
