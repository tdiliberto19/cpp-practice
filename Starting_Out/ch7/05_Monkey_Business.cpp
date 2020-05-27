/**
    Tracks how much food three monkeys eat each day in a week

    @author Timothy Diliberto
    @version 1.1 5/2/2020
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Arrays.h"

using namespace std;

int main() {
    const int ROWS = 3,
              COLS = 5;
    double monkey_food_data [ROWS][COLS],
           average_daily_food,
           least_food_eaten,
           most_food_eaten;
    string days_of_week[COLS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"},
           monkeys[ROWS] = {"Gizmo", "Bingo", "Bongo"};

    for (int day_index = 0; day_index < COLS; day_index++) {
        cout << days_of_week[day_index] << endl;
        for (int monkey_index = 0; monkey_index < ROWS; monkey_index++) {
            cout << "    " << monkeys[monkey_index] << ": ";
            cin >> monkeys[ROWS][COLS];
        }
    }
    cout << endl;

    average_daily_food = averageElements(monkey_food_data, ROWS, COLS);
    least_food_eaten = smallestElement(monkey_food_data, ROWS, COLS);
    most_food_eaten = largestElement(monkey_food_data, ROWS, COLS);

    cout << setprecision(2) << fixed
         << "Average Daily Food: " << average_daily_food << endl
         << "Least Amount Eaten: " << least_food_eaten << endl
         << "Greatest Amount Eaten: " << most_food_eaten << endl;

    return 0;
}
