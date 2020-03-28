/**
    @author Timothy Diliberto
    @version 1.0 3/27/2020
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    int count,
        sum,
        number;
    double average;
    ifstream readFile;

    readFile.open("List_Of_Numbers.txt");
    cout << "File opened successfully!\n";

    while (readFile >> number) {
        count++;
        sum += number;
    }

    readFile.close();
    cout << "File closed successfully!\n";

    average = static_cast<double>(sum) / count;

    cout << setprecision(2) << fixed
         << "Number of numbers: " << count << endl
         << "Sum of numbers: " << sum << endl
         << "Average of numbers: " << average << endl;

    return 0;
}
