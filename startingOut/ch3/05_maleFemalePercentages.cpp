#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int males, females, total;
    double percMales, percFemales;

    cout << "How many males and females are in the class? ";
    cin >> males >> females;

    total = males + females;
    percMales = static_cast<double>(males) / total;
    percFemales = static_cast<double>(females) / total;

    cout << "The percentage of males in the class is " << percMales * 100 << "%\n";
    cout << "The percentage of females in the class is " << percFemales * 100 << "%\n";

    return 0;
}
