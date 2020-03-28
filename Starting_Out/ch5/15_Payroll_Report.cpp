/**
    Collects data on employee earnings and tax withholdings, then displaying the total values for
    the company to view.

    @author Timothy Diliberto
    @version 1.0 3/20/2020
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    unsigned employee_number = -1;
    double gross_pay,
           state_tax,
           federal_tax,
           fica,
           total_net_pay = 0,
           total_gross = 0,
           total_state = 0,
           total_federal = 0,
           total_fica = 0;

    while (employee_number != 0) {
        cout << "-----------------------------------\n"
             << "Enter the employee number: ";
        cin >> employee_number;

        if (employee_number == 0)
            break;

        cout << "Enter the employee's gross pay: ";
        cin >> gross_pay;

        while (gross_pay < 0) {
            cout << "Please enter a positive gross pay: ";
            cin >> gross_pay;
        }

        cout << "Enter the employee's state tax: ";
        cin >> state_tax;

        while (state_tax < 0 || state_tax > gross_pay) {
            cout << "Please enter a valid state tax amount: ";
            cin >> state_tax;
        }

        cout << "Enter the employee's federal tax: ";
        cin >> federal_tax;

        while (federal_tax < 0 || federal_tax > gross_pay) {
            cout << "Please enter a valid federal tax amount: ";
            cin >> federal_tax;
        }

        cout << "Enter the employee's FICA witholdings: ";
        cin >> fica;

        while (fica < 0 || fica > gross_pay) {
            cout << "Please enter a valid FICA amount: ";
            cin >> fica;
        }

        total_net_pay += gross_pay - state_tax - federal_tax - fica;
        total_gross += gross_pay;
        total_state += state_tax;
        total_federal += federal_tax;
        total_fica += fica;
    }
    
    cout << setprecision(2) << fixed
         << "----------------------------------\n"
         << "Total Gross Pay: $" << total_gross << endl
         << "Total State Tax: $" << total_state << endl
         << "Total Federal Tax: $" << total_federal << endl
         << "Total FICA: $" << total_fica << endl
         << "Total Net Pay: $" << total_net_pay << endl;

    return 0;
}
