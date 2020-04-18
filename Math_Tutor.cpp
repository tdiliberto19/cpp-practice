/**
    A tutoring program offering problems regarding basic mathematical operations with customizable options for a
    wide range of problems
    
    @author Tim Diliberto
    @version 2.0 4/7/2020
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MIN_NUM = 100,
          MAX_NUM = 999;

int main() {
    const int ADDITION = 1,
              SUBTRACTION = 2,
              MULTIPLICATION = 3,
              DIVISION = 4,
              EXIT = 5;
    int choice;
    double num1,
           num2,
           solution,
           answer;

    do {
        cout << "*********************************************************************\n"
             << "*  ** **   ****  ****** **  **   ****** **  ** ******  ****  *****  *\n"
             << "* ** * ** **  **   **   ******     **   **  **   **   **  ** **  ** *\n"
             << "* **   ** ******   **   **  **     **   **  **   **   **  ** ****** *\n"
             << "* **   ** **  **   **   **  **     **    ****    **    ****  **  ** *\n"
             << "*********************************************************************\n"
             << "*********************************************************************\n"
             << "*       Welcome to Math Tutor! Please select a menu item below:     *\n"
             << "*********************************************************************\n"
             << "*                         1. Addition                               *\n"
             << "*                       2. Subtraction                              *\n"
             << "*                      3. Multiplication                            *\n"
             << "*                         4. Division                               *\n"
             << "*                        5. Exit Tutor                              *\n"
             << "*********************************************************************\n";
        cin >> choice;

        while (choice < ADDITION || choice > EXIT) {
            cout << "*********************************************************************\n"
                 << "*                  Please choose a valid menu option:               *\n"
                 << "*********************************************************************\n"
                 << "*                          1. Addition                              *\n"
                 << "*                        2. Subtraction                             *\n"
                 << "*                       3. Multiplication                           *\n"
                 << "*                          4. Division                              *\n"
                 << "*                         5. Exit Tutor                             *\n"
                 << "*********************************************************************\n";
            cin >> choice;
        }

        if (choice != EXIT) {
            switch (choice) {
                case ADDITION:
                    solution = num1 + num2;
                    cout << "Add the following numbers. Then press ENTER to check your answer\n"
                         << setw(4) << num1 << endl
                         << "+" << num2 << endl
                         << "----\n";
                    cin >> answer;
                    break;
                case SUBTRACTION:
                    solution = num1 - num2;
                    cout << "Subtract the following numbers. Then press ENTER to check your "
                         << "answer\n"
                         << setw(4) << num1 << endl
                         << "-" << num2 << endl
                         << "----\n";
                    cin >> answer;
                    break;
                case MULTIPLICATION:
                    solution = num1 * num2;
                    cout << "Multiply the following numbers. Then press ENTER to check your "
                         << "answer\n"
                         << setw(4) << num1 << endl
                         << "*" << num2 << endl
                         << "----\n";
                    cin >> answer;
                    break;
                case DIVISION:
                    solution = num1 / num2;
                    cout << "Divide the following numbers. Then press ENTER to check your answer\n"
                         << setw(4) << num1 << endl
                         << "/" << num2 << endl
                         << "----\n";
                    cin >> answer;
            }

            if (labs(solution - answer) < 0.000001)
                cout << "Correct! Congratulations!\n";
            else
                cout << "That is incorrect. The correct answer is " << solution << endl;
        }

    } while (choice != EXIT);

    return 0;
}

int random_number_generator() {
    srand(time(NULL));

    return rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
}
