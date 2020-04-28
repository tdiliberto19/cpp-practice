/**
    Obtains number of jars sold of a specific type of salsa. Produces a receipt containing sales for each salsa
    type, total sales, and the names of the most and least popular products.

    @author Timothy Diliberto
    @version 1.0 4/27/2020
*/

#include <iostream>
#include <string>
#include "Arrays.h"

using namespace std;

// Controls the flow of the program

int main() {
    const int NUM_TYPES = 5;
    const double SALSA_PRICES[NUM_TYPES] = {1.75, 2.00, 2.50, 2.25, 2.50};
    int most_popular_index,
        least_popular_index,
        jars_sold[NUM_TYPES];
    double total_sales,
           total_sales_type[NUM_TYPES];
    string salsa_types[NUM_TYPES] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};

    cout << "Enter the number of salsa jars per type sold:\n";

    for (int index = 0; index < NUM_TYPES; index++) {
        cout << salsa_types[index] << ": ";
        cin >> jars_sold[index];

        while (jars_sold[index] < 0) {
            cout << "Please enter a positive value: ";
            cin >> jars_sold[index];
        }
    }

    for (int index = 0; index < NUM_TYPES; index++)
        total_sales_type[index] = jars_sold[index] * SALSA_PRICES[index];

    total_sales = sumElements(total_sales_type, NUM_TYPES);
    most_popular_index = largestIndex(jars_sold, NUM_TYPES);
    least_popular_index = smallestIndex(jars_sold, NUM_TYPES);
    
    cout << "Total: " << total_sales << endl
         << "Most Popular: " << salsa_types[most_popular_index] << endl
         << "Least Popular: " << salsa_types[least_popular_index] << endl;

    return 0;
}
