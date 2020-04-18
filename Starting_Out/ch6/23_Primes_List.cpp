#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int);

int main() {
    const int MAX_NUMBER = 100;
    bool prime;
    ofstream writeFile;

    writeFile.open("Primes_List.txt");

    for (int number = 2; number <= MAX_NUMBER; number++) {
        prime = isPrime(number);

        if (prime)
            writeFile << number << endl;
    }

    writeFile.close();

    return 0;
}

bool isPrime(int number) {
    bool prime = true;

    for (int divisor = 2; divisor <= number / 2; divisor++) {
        if (number % divisor == 0) {
            prime = false;
            break;
        }
    }

    return prime;
}
