/**
    Provides a menu to the user, asking them to choose a topic. Then asks a random question
    corresponding to the chosen topic. Asks the user to give an answer and check with the system.
    If correct, it will congratulate the user. Otherwise, it will provide the correct answer.

    @author Tim Diliberto
    @version 1.3.1 3/12/2020
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    
    const int MIN_NUM = 100,
              MAX_NUM = 999,
              ADDITION = 1,
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
        srand(time(NULL));
        num1 = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
        num2 = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;

        cout << "****************************************************\n"
             << "Welcome to Math Tutor! Please choose an topic below:\n"
             << "****************************************************\n"
             << "1. Addition\n"
             << "2. Subtraction\n"
             << "3. Multiplication\n"
             << "4. Division\n"
             << "5. Exit Tutor\n"
             << "****************************************************\n";
        cin >> choice;

        while (choice < ADDITION || choice > EXIT) {
            cout << "\n**********************************\n"
                 << "Please choose a valid menu option:\n"
                 << "**********************************\n"
                 << "1. Addition\n"
                 << "2. Subtraction\n"
                 << "3. Multiplication\n"
                 << "4. Division\n"
                 << "5. Exit Tutor\n"
                 << "**********************************\n";
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
