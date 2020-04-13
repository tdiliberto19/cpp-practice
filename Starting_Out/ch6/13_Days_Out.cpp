/**
    Calculates the total number of days a company's employees were absent.

    @author Timothy Diliberto
    @version 1.0 3/12/2020
*/

#include <iostream>

using namespace std;

int getNumEmployees();
int getMissedDays(int);
double average(int, int);

// Controls the flow of the program

int main() {
    
    int num_employees = getNumEmployees();
    double average_days_missed = average(getMissedDays(num_employees), num_employees);

    cout << "Your employees have missed an average of " << average_days_missed << " days\n";
    
    return 0;
}

/**
    Obtains the number of employees at a company

    @return employees Total number of employees
*/

int getNumEmployees() {
    int employees;
    
    cout << "How many employees work at your company: ";
    cin >> employees;

    while (employees < 1) {
        cout << "Please enter at least 1 employee: ";
        cin >> employees;
    }

    return employees;
}

/**
    Gets the number of missed days for each employee and finds their sum

    @param employees The total number of employees
    @return total_missed_days The total number of days missed by all employees
*/

int getMissedDays(int employees) {
    int missed_days,
        total_missed_days = 0;
    
    cout << "Please enter number of days missed for each: \n";

    for (int employee = 1; employee <= employees; employee++) {
        cout << "   -Employee " << employee << ": ";
        cin >> missed_days;

        while (missed_days < 0) {
            cout << "Please enter a positive value for missed days: ";
            cin >> missed_days;
        }

        total_missed_days += missed_days;
    }

    return total_missed_days;
}

/**
    Calculates the average given a sum and number of values

    @param sum The total value of all numbers
           number The number of numbers being averaged
    @return average The average of the numbers
*/

double average(int sum, int number) {
    double average = static_cast<double>(sum) / static_cast<double>(number);

    return average;
}
