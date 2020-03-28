#include <iostream>
#include <string>

using namespace std;

int main() {
    string color1, color2;

    cout << "Please enter two primary colors (red, blue, or yellow): ";
    cin >> color1 >> color2;

    if (color1 == color2)
        cout << "The resulting color is " << color1 << endl;
    else if ((color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red"))
        cout << "The resulting color is purple\n";
    else if ((color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red"))
        cout << "The resulting color is orange\n";
    else if ((color1 == "yellow" && color2 == "blue") || (color1 == "blue" && color2 == "yellow"))
        cout << "The resulting color is green\n";
    else
        cout << "Color inputs not understood. Please try again.\n";

    return 0;
}
