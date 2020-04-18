/**
    Asks the user to fill out a travel expense report, then writes the data to a file

    @author Timothy Diliberto
    @version 1.0 4/13/2020
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int getDays();
void getTravelTimes(int &, int &);
double roundTrip();
double carRental();
double milesDriven();
double parkingFees(int);
double taxiFees(int);
double eventFees();
double hotelExpenses(int);
double meals(int, int, int);

// Controls the flow of the program

int main() {
    int days,
        departure_time,
        arrival_time;
    double flight_expense,
           rental_expense,
           personal_mileage,
           parking_fee,
           taxi_fee,
           event_fee,
           hotel_expense,
           meal_expense,
           total_personal_expense;
    ofstream writeFile

    cout << "Please fill out the following travel report:\n";
    
    writeFile.open("Travel_Report.txt");

    days = getDays();
    getTravelTimes(departure_time, arrival_time);
    flight_expense = roundTrip();
    rental_expense = carRental();
    personal_mileage = milesDriven();
    parking_fee = parkingFees(days);
    taxi_fee = taxiFees(days);
    event_fee = eventFees();
    hotel_expense = hotelExpenses(days);
    meal_expenses = meals(departure, arrival, days)

    total_personal_expense = flight_expense + rental_expense + persoanl_mileage + parking_fee + taxi_fee +
                              event_fee + hotel_expense + meal_expense;

    writeFile.close();
    
    return 0;
}

/**
    Obtains number of days of trip

    @return days Number of days of trip
*/

int getDays() {
    int days

    cout << "Enter the total number of days of your trip: ";
    cin >> days;

    return days;
}

/**
    Updates initial departure and final arrival of the trip

    @param &departure Time of departure (marks beginning of trip)
           &arrival Arrival time (marks end of trip)
*/

void getTravelTimes(int &departure, int &arrival) {
    
    cout << "Enter the initial departure and final arrive times of your trip in military time\n"
         << "(i.e. 700 is 7:00 AM and 2230 is 10:30 PM)\n"
         << "    -Departure: ";
    cin >> departure;
    cout << "    -Arrival: ";
    cin >> arrival;
}

/**
    Obtains total cost of round-trip airfare

    @return total_cost Cumulative cost of airfare
*/

double roundTrip() {
    double total_cost;

    cout << "Enter the total cost of airfare: $";
    cin >> total_cost;

    return total_cost;
}

/**
    Obtains any expenses toward a rental car

    @return total_cost Cumulative cost of car rentals
*/

double carRental() {
    double total_cost;

    cout << "Enter the total cost of car rentals: $";
    cin >> total_cost;

    return total_cost;
}

/**
    Obtains the total miles driven in a personal vehicle on the trip

    @return total_cost Total cost of driving a personal vehicle
*/

double milesDriven() {
    const double RATE = 0.27;
    double total_cost;

    cout << "Enter the number of miles driven in a personal vehicle: ";
    cin >> total_cost;

    total_cost *= RATE;

    return total_cost;
}

/**
    Calculates the parking fees accumulated on the trip, after company contribution has been accounted for

    @param days Number of days of trip, to calculate company allowance
    @return total_cost Total cost of parking fees
*/

double parkingFees(int days) {
    const int DAILY_ALLOWANCE = 6;
    double total_cost;

    cout << "Enter the total for parking fees: $";
    cin >> total_cost;

    total_cost -= (DAILY_ALLOWANCE * days);

    return total_cost;
}

/**
    Calculates taxi fees after company allowance has been accounted for

    @param days Number of days of trip, to calculate company allowance
    @return total_cost Total cost of taxi fees
*/

double taxiFees(int days) {
    const int DAILY_ALLOWANCE = 10;
    double total_cost;

    cout << "Enter the total for taxi fares: $";
    cin >> total_cost;

    total_cost -= (DAILY_ALLOWANCE * days);

    return total_cost;
}

/**
    Obtains any fees required to attend events

    @return total_cost Total cost of events
*/

double eventFees() {
    double total_cost;

    cout << "Enter the total cost for events: $";
    cin >> total_cost;

    return total_cost;
}

/**
    Calculates hotel expenses, after company allowance is accounted for

    @param days Number of days of trip, to calculate company allowance
    @return total_cost Total cost for hotels
*/

double hotelExpenses(int days) {
    const int DAILY_ALLOWANCE = 90;
    double total_cost;

    cout << "Enter the total cost for your hotel(s): $";
    cin >> total_cost;

    total_cost -= (DAILY_ALLOWANCE * days);

    return total_cost;
}

/**
    Obtains the cost of each meal, factors in the company's allowance, then displays the total cost to the employee

    @param departure Time of departure, used to determine first meal
           arrival Time of arrival, used to determine last meal
           days Number of days
    @return total_cost Total cost for meals
*/

double meals(int departure, int arrival, int days) {
    const int BREAKFAST = 9,
              LUNCH = 12,
              DINNER = 16;
    
    for (int day = 2; day <= days - 1; day++) {
        cout << "Day " << day << endl
             << "    -Breakfast: $";
        cin >> breakfast;
        cout << "    -Lunch: $";
        cin >> lunch;
        cout << "    -Dinner: $";
        cin >> dinner;

        total_cost += (
