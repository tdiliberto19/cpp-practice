/**
    Displays the order status

    @author Timothy Diliberto
    @version 1.0 3/12/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

void processOrder(int &, int &, double &);
void orderStatus(int, int, double);

int main() {
    int spools_ordered,
        spools_stocked;
    double shipping_handling;
    
    processOrder(spools_ordered, spools_stocked, shipping_handling);
    orderStatus(spools_ordered, spools_stocked, shipping_handling);

    return 0;
}

/**
    Gets the data for product ordered, product in stock, and additional shipping and handling charges

    @param &ordered Product ordered by customer
           &stocked Product currently in stock
           &sh Additional shipping & handling charges
*/

void processOrder(int &ordered, int &stocked, double &sh) {
    cout << "Please enter the following data: \n";
    cout << "   -Spools Ordered: ";
    cin >> ordered;

    while (ordered < 1) {
        cout << "Enter at least 1 product: ";
        cin >> ordered;
    }
        
    cout << "   -Spools in Stock: ";
    cin >> stocked;

    while (stocked < 0) {
        cout << "Enter a positive value: ";
        cin >> stocked;
    }

    cout << "   -Additional S&H Charges: ";
    cin >> sh;

    while (sh < 0) {
        cout << "Enter a positive value: ";
        cin >> sh;
    }
}

/**
    Displays the order status

    @param spools_ordered The numebr of spools ordered
           spools_stocked The number of spools in stock
           shipping_handling Additional shipping and handling costs
*/

void orderStatus(int spools_ordered, int spools_stocked, double shipping_handling) {
    const double PRICE = 100,
                 STD_SH = 10;
    int spools_ready = spools_ordered <= spools_stocked ? spools_ordered : spools_stocked,
        backorder = spools_ordered > spools_stocked ? spools_ordered - spools_stocked : 0; 
    double subtotal = spools_ready * PRICE,
           sh = spools_ready * STD_SH + shipping_handling;
    
    cout << "-----------------------------\n"
         << "Spools Ready to Ship: " << spools_ready << endl
         << "Spools on Backorder: " << backorder << endl
         << setprecision(2) << fixed
         << "Subtotal: $" << subtotal << endl
         << "S&H: $" << sh << endl
         << "Total: $" << subtotal + sh << endl;
}
