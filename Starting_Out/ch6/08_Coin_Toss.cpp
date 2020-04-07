/**
    Simulates a coin toss. Calls the COIN_TOSS function which generates a random number in the range of 1 to 2,
    where 1 corresponds to HEADS and 2 corresponds to TAILS. Then displays the result to the user

    @author Timothy Diliberto
    @version 1.0 3/30/2020
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int HEADS = 1,
          TAILS = 2;

void coinToss();

//Controls the flow of the program

int main() {
    coinToss();

    return 0;
}

/**
    Generates a random number between 1-2. If the result is 1, the coin simulation landed on heads. If the
    result is 2, the coin landed on tails. Then displays the result to the screen
*/

void coinToss() {
    int side;

    srand(time(0));

    side = (rand() % (TAILS - HEADS + 1)) + HEADS;

    if (side == HEADS)
        cout << side << " Heads\n";
    else
        cout << side << " Tails\n";
}
