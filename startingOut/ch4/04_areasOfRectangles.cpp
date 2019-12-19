#include <iostream>

using namespace std;

int main() {
    double length1, width1, length2, width2, area1, area2;

    cout << "Please enter the length and width of a rectangle: ";
    cin >> length1 >> width1;
    cout << "Enter the length and width of a second rectangle: ";
    cin >> length2 >> width2;

    area1 = length1 * width1;
    area2 = length2 * width2;

    if (area1 > area2)
        cout << "The area of the first rectangle is larger than the second.\n";
    else if (area2 > area1)
        cout << "The area of the second rectangle is larger than the first.\n";
    else
        cout << "The rectangles have equal areas.\n";

    return 0;
}
