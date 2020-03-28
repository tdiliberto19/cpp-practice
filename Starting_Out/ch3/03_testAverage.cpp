#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int NUM_OF_SCORES = 5;
    double score1, score2, score3, score4, score5, average;

    cout << "Please enter 5 test scores: ";
    cin >> score1 >> score2 >> score3 >> score4 >> score5;

    average = (score1 + score2 + score3 + score4 + score5) / NUM_OF_SCORES;

    cout << setprecision(1) << fixed;
    cout << "The average of the test scores is " << average << endl;

    return 0;
}
