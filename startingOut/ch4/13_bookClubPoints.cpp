#include <iostream>

using namespace std;

int main() {
   int books, points; 

    cout << "How many books did you purchase this month? ";
    cin >> books;

    if (books == 0)
        points = 0;
    else if (books == 1)
        points = 5;
    else if (books == 2)
        points = 15;
    else if (books == 3)
        points = 30;
    else if (books >= 4)
        points = 60;
    else {
        cout << "You can't purchase a negative number of books.\n";
        exit(0);
    }

    cout << "You have earned " << points << " points this month!\n";

    return 0;
}
