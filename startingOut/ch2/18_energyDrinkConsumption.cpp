#include <iostream>

using namespace std;

int main() {
    const double PERC_1 = 0.15, PERC_2 = 0.58;
    double respondents = 16500.0, purchased, citrusPreferred;

    purchased = respondents * PERC_1;
    citrusPreferred = purchased * PERC_2;

    cout << "The number of respondents who purchase more than one energy drink per week is " << purchased
         << endl;
    cout << "The number of respondents who purchase energy drinks and prefer citrus flavors is " << citrusPreferred 
         << endl;

    return 0;
}
