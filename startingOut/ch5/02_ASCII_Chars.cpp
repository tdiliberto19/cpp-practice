#include <iostream>

using namespace std;

int main() {

    for (int ascii = 32; ascii < 127; ascii++) {
        cout << "ASCII: " << ascii << "\tCHAR: " << char(ascii) << "\t\t";
        ascii++;
        cout << "ASCII: " << ascii << "\tCHAR: " << char(ascii) << "\t\t";
        ascii++;
        cout << "ASCII: " << ascii << "\tCHAR: " << char(ascii) << endl;
    }

    return 0;
}
