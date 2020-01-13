#include <iostream>
#include <string>

using namespace std;

int main() {
    int time1, time2, time3;
    string runner1, runner2, runner3;

    cout << "Please enter the names and times (in seconds) of three runners: \n";
    cout << "Runner 1: ";
    getline(cin, runner1);
    cout << "Time 1: ";
    cin >> time1;
    cout << "Runner 2: ";
    cin.ignore();
    getline(cin, runner2);
    cout << "Time 2: ";
    cin >> time2;
    cout << "Runner 3: ";
    cin.ignore();
    getline(cin, runner3);
    cout << "Time 3: ";
    cin >> time3;

    cout << "And the winners are...\n";

    if (time1 < time2 && time1 < time3) {
        if (time2 < time3) {
            cout << "1st: " << runner1 << endl;
            cout << "2nd: " << runner2 << endl;
            cout << "3rd: " << runner3 << endl;
        }
        else if (time3 < time2) {
            cout << "1st: " << runner1 << endl;
            cout << "2nd: " << runner3 << endl;
            cout << "3rd: " << runner2 << endl;
        }
        else {
            cout << "1st: " << runner1 << endl;
            cout << "2nd: " << runner2 << endl;
            cout << "2nd: " << runner3 << endl;
        }
    }
    else if (time2 < time1 && time2 < time3) {
        if (time1 < time3) {
            cout << "1st: " << runner2 << endl;
            cout << "2nd: " << runner1 << endl;
            cout << "3rd: " << runner3 << endl;
        }
        else if (time3 < time1) {
            cout << "1st: " << runner2 << endl;
            cout << "2nd: " << runner3 << endl;
            cout << "3rd: " << runner1 << endl;
        }
        else {
            cout << "1st: " << runner2 << endl;
            cout << "2nd: " << runner1 << endl;
            cout << "2nd: " << runner3 << endl;
        }
    }
    else if (time3 < time1 && time3 < time2) {
        if (time1 < time2) {
            cout << "1st: " << runner3 << endl;
            cout << "2nd: " << runner1 << endl;
            cout << "3rd: " << runner2 << endl;
        }
        else if (time2 < time1) {
            cout << "1st: " << runner3 << endl;
            cout << "2nd: " << runner2 << endl;
            cout << "3rd: " << runner1 << endl;
        }
        else {
            cout << "1st: " << runner3 << endl;
            cout << "2nd: " << runner1 << endl;
            cout << "2nd: " << runner2 << endl;
        }
    }
    else
        cout << "Something went wrong and I don't know what.\n";

    return 0;
}
