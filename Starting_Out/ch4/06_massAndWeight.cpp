#include <iostream>

using namespace std;

int main () {
    const double GRAVITY_CONST = 9.81;
    double mass, weight;    

    cout << "Please enter an object's mass (in kilograms): ";
    cin >> mass;

    weight = mass * GRAVITY_CONST;

    cout << "The object weighs " << weight << " newtons. ";

    if (weight > 1000)
        cout << "The object is too heavy";
    else if (weight < 10)
        cout << "The object is too light";
    cout << endl;

    return 0;
}
