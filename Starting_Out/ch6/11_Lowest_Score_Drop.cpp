/**
    Calculates the average of a student's 4 highest test scores.

    @author Timothy Diliberto
    @verison 1.0 4/6/2020
*/

#include <iostream>

using namespace std;

void getScore(int &);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

// Controls the flow of the program

int main() {
    int score1,
        score2,
        score3,
        score4,
        score5;

    getScore(score1);
    getScore(score2);
    getScore(score3);
    getScore(score4);
    getScore(score5);

    calcAverage(score1, score2, score3, score4, score5);
    
    return 0;
}

/**
    Obtains a single test score and verifies that it is between 0 and 100, inclusive

    @param &score References one of the five variables in main, dependent on the iteration
*/
void getScore(int &score) {
    cout << "Enter a test score: ";
    cin >> score;

    while (score < 0 || score > 100) {
        cout << "Please enter a score between 0 and 100: ";
        cin >> score;
    }
}

/**
    Calculates and displays the average of the 4 highest numbers from main(), subtracting LOWEST from the list

    @param score1 The first score
           score2 The second score
           score3 The third score
           score4 The fourth score
           score5 The fifth score
*/
void calcAverage(int score1, int score2, int score3, int score4, int score5) {
    int lowest = findLowest(score1, score2, score3, score4, score5);
    double average = static_cast<double>(score1 + score2 + score3 + score4 + score5 - lowest) / 4.0;

    cout << "The average of the 4 highest scores is " << average << endl;
}

/**
    Finds the lowest of five numbers

    @param num1 The first number
           num2 The second number
           num3 The third number
           num4 The fourth number
           num5 The fifth number
    @return (multiple) The number less than or equal all other numbers
*/
int findLowest(int num1, int num2, int num3, int num4, int num5) {
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
