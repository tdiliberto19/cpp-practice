#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double CLASS_A = 15.0, CLASS_B = 12.0, CLASS_C = 9.0;
    int ticketNumA, ticketNumB, ticketNumC;
    double profit;

    cout << "How many class A tickets were purchased? ";
    cin >> ticketNumA;
    cout << "How many class B tickets were purchased? ";
    cin >> ticketNumB;
    cout << "How many class C tickets were purchased? ";
    cin >> ticketNumC;

    profit = CLASS_A * ticketNumA + CLASS_B * ticketNumB + CLASS_C * ticketNumC;

    cout << setprecision(2) << fixed;
    cout << "The stadium made a profit of $" << profit << endl;

    return 0;
}
