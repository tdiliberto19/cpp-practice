/**
    @author Timothy Diliberto
    @version 1.0 3/26/2020
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int population_1900,
        population_1920,
        population_1940,
        population_1960,
        population_1980,
        population_2000;
    ifstream readFile;

    readFile.open("People.txt");

    readFile >> population_1900 >> population_1920 >> population_1940
             >> population_1960 >> population_1980 >> population_2000;

    cout << "PRARIEVILLE POPULATION GROWTH\n"
         << "(each * = 1000 people)\n"
         << "1900 ";
    for (int asterisk = 1; asterisk <= population_1900 / 1000; asterisk++)
        cout << "*";
    cout << "\n1920 "; 
    for (int asterisk = 1; asterisk <= population_1920 / 1000; asterisk++)
        cout << "*";
    cout << "\n1940 ";
    for (int asterisk = 1; asterisk <= population_1940 / 1000; asterisk++)
        cout << "*";
    cout << "\n1960 ";
    for (int asterisk = 1; asterisk <= population_1960 / 1000; asterisk++)
        cout << "*";
    cout << "\n1980 ";
    for (int asterisk = 1; asterisk <= population_1980 / 1000; asterisk++)
        cout << "*";
    cout << "\n2000 ";
    for (int asterisk = 1; asterisk <= population_2000 / 1000; asterisk++)
        cout << "*";
    cout << endl;

    readFile.close();

    return 0;
}
