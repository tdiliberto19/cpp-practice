/**
    Calculates the area of a rectangle through various functions.

    @author Timothy Diliberto
    @version 1.0 3/28/2020
*/

#include <iostream>

using namespace std;

double getLength();
double getWidth();
double getArea(double, double);
void displayData(double, double, double);

int main() {
    double length,
           width,
           area;

    length = getLength();
    width = getWidth();
    area = getArea(length, width);
    displayData(length, width, area);

}

double getLength() {
    double length;

    cout << "Enter the rectangle's length: ";
    cin >> length;

    return length;
}

double getWidth() {
    double width;

    cout << "Enter the rectangle's width: ";
    cin >> width;

    return width;
}

double getArea(double length, double width) {
    double area = length * width;

    return area;
}

void displayData(double length, double width, double area) {
    cout << "The rectangle's length is " << length << endl
         << "The rectangle's width is " << width << endl
         << "The rectangle's area is " << area << endl;
}
