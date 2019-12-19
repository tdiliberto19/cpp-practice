#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double height, weight, bmi;

    cout << "Please enter your height (in inches) and weight (in pounds): ";
    cin >> height >> weight;

    bmi = (weight * 703) / (height * height);
    
    cout << setprecision(1) << fixed;
    cout << "Your BMI is " << bmi << ". ";

    if (bmi < 18.5)
        cout << "You are underweight\n";
    else if (bmi > 25)
        cout << "You are overweight\n";
    else
        cout << "You are at an optimal weight\n";

    return 0;
}
