/**
    Reads the names from a list and determines which student will be in front and which student
    will be at the end of the line (sorted alphabetically).

    @author Timothy Diliberto
    @version 2.0 3/28/2020
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int students;
    string name,
           first,
           last;
    ifstream readFile;

    readFile.open("Names.txt");
    cout << "Successfully opened file!\n";

    readFile >> name;
    first = last = name;

    while (readFile >> name) {
        if (name > last)
            last = name;
        if (name < first)
            first = name;
    }

    readFile.close();
    cout << "Successfully closed file!\n";

    cout << "First in line: " << first << endl
         << "Last in line: " << last << endl;
    
    return 0;
}
