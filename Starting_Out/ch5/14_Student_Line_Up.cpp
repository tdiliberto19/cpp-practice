/**
    Asks the user to enter a group of students, by name. It will then state which student will be
    at the front and back of the line (sorted alphabetically).

    @author Timothy Diliberto
    @version 1.0 3/12/2020
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int students;
    string name,
           first,
           last;
    
    cout << "How many students in class? ";
    cin >> students;
    cin.ignore();

    if (students < 1 || students > 25) {
        cout << "Class sizes range from 1 to 25 students. Please enter an appropriate number: ";
        cin >> students;
    }

    cout << "Please enter the names of the students, one at a time (be consistent with "
         << "capitalizing the first letter!):\n";
    getline(cin, name);
    first = last = name;

    for (int student = 2; student <= students; student++) {
        getline(cin, name);
        if (name > last)
            last = name;
        if (name < first)
            first = name;
    }

    cout << "First in line: " << first << endl
         << "Last in line: " << last << endl;
    
    return 0;
}
