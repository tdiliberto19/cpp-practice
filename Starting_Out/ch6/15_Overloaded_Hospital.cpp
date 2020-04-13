/**
    Calculates and displays the charges for an in- or out-patient

    Note 1: There are no input validations

    @author Timothy Diliberto
    @version 1.0 4/13/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

double calculateCharges(int, double, double, double);
double calculateCharges(double, double);

int main() {
    int patient_type,
        days;
    double daily_rate,
           service_fee,
           medication_cost,
           total_charges;

    cout << "Is the patient being recorded an 1) in-patient, or 2) out-patient? ";
    cin >> patient_type;

    switch (patient_type) {
        case 1:
            cout << "Please enter the following data:\n"
                 << "Days in Hospital: ";
            cin >> days;
            cout << "Daily Rate: ";
            cin >> daily_rate;
            cout << "Hospital Service Fee: ";
            cin >> service_fee;
            cout << "Medication: ";
            cin >> medication_cost;

            total_charges = calculateCharges(days, daily_rate, service_fee, medication_cost);
            break;
        case 2:
            cout << "Please enter the following data:\n"
                 << "Hospital Service Fee: ";
            cin >> service_fee;
            cout << "Medication: ";
            cin >> medication_cost;

            total_charges = calculateCharges(service_fee, medication_cost);
    }

    cout << setprecision(2) << fixed
         << "Total: $" << total_charges << endl;
    
    return 0;
}

/**
    Calculates charges

    @param days Number of days spent in hospital
           daily_rate The daily rate for staying in hospital
           service_fee Cumulative service fee for lab tests, equipment usage, etc.
           medication Cumulative medication charge for any medication used
    @return total The total cost of the hospital stay
*/

double calculateCharges(int days, double daily_rate, double service_fee, double medication) {
    double total = days * daily_rate + service_fee + medication;

    return total;
}

/**
    Calculates charges

    @param service_fee Cumulative service fee for lab tests, equipment usage, etc.
           medication Cumulative medication charge for any medication used
    @return total The total cost of the hospital stay
*/

double calculateCharges(double service_fee, double medication) {
    double total = service_fee + medication;

    return total;
}
