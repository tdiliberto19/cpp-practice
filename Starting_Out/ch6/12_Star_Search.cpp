/**
    Obtains five judges' scores and calculates the performer's score by averaging all but the highest and lowest
    scores
    
    @author Timothy Diliberto
    @version 1.0 4/7/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

void getJudgeData(double &);
void calcScore(double, double, double, double, double);
double findLowest(double, double, double, double, double);
double findHighest(double, double, double, double, double);

//Controls the flow of the program

int main() {
    // Scores initialized to represent judge's number
    double score1 = 1,
           score2 = 2,
           score3 = 3,
           score4 = 4,
           score5 = 5;

    getJudgeData(score1);
    getJudgeData(score2);
    getJudgeData(score3);
    getJudgeData(score4);
    getJudgeData(score5);

    calcScore(score1, score2, score3, score4, score5);

    return 0;
}

/**
    Obtains a judge's score and checks that it is between 0 and 10, inclusive

    @param &score References one of the five scores for each judge, dependent on the iteration
*/

void getJudgeData(double &score) {
    cout << "Judge " << score << "'s Score: ";
    cin >> score;

    while (score < 0 || score > 10) {
        cout << "Enter a score from 0 and 10: ";
        cin >> score;
    }
}

/**
    Calculates the performer's score by averaging all but the highest and lowest numbers

    @param score1 The first score
           score2 The second score
           score3 The third score
           score4 The fourth score
           score5 The fifth score
*/

void calcScore(double score1, double score2, double score3, double score4, double score5) {
    double lowest = findLowest(score1, score2, score3, score4, score5),
           highest = findHighest(score1, score2, score3, score4, score5);

    double average = (score1 + score2 + score3 + score4 + score5 - lowest - highest) / 3.0;

    cout << setprecision(1) << fixed
         << endl << "Final Score: " << average << endl;
}

/**
    Finds the lowest of five numbers

    @param num1 The first number
           num2 The second number
           num3 The third number
           num4 The fourth number
           num5 The fifth number
    @return lowest The number less than or equal to every other number
*/

double findLowest(double num1, double num2, double num3, double num4, double num5) {
    if (num1 <= num2 && num1 <= num3 && num1 <= num4 && num1 <= num5)
        return num1;
    else if (num2 <= num1 && num2 <= num3 && num2 <= num4 && num2 <= num5)
        return num2;
    else if (num3 <= num2 && num3 <= num1 && num3 <= num4 && num3 <= num5)
        return num3;
    else if (num4 <= num2 && num4 <= num3 && num4 <= num1 && num4 <= num5)
        return num4;
    else
        return num5;
}

/**
    Finds the highest of five numbers

    @param num1 The first number
           num2 The second number
           num3 The third number
           num4 The fourth number
           num5 The fifth number
    @return highest The number greater than or equal to every other number
*/

double findHighest(double num1, double num2, double num3, double num4, double num5) {
    if (num1 >= num2 && num1 >= num3 && num1 >= num4 && num1 >= num5)
        return num1;
    else if (num2 >= num1 && num2 >= num3 && num2 >= num4 && num2 >= num5)
        return num2;
    else if (num3 >= num2 && num3 >= num1 && num3 >= num4 && num3 >= num5)
        return num3;
    else if (num4 >= num2 && num4 >= num3 && num4 >= num1 && num4 >= num5)
        return num4;
    else
        return num5;
}
