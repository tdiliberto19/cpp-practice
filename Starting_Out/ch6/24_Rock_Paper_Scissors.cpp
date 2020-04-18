/**
    Plays a rock, paper, scissors game with the user

    @author Timothy Diliberto
    @version 1.0 4/13/2020
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randomNumberGenerator();
int getPlayerChoice();
void displayResults(int, int);

int main() {
    int computer_choice = randomNumberGenerator(),
        player_choice = getPlayerChoice();

    displayResults(player_choice, computer_choice);
    
    return 0;
}

/**
    Generates a random number between MIN_VALUE and MAX_VALUE (inclusive)

    @return number The random number generated
*/

int randomNumberGenerator() {
    const int MIN_VALUE = 1,
              MAX_VALUE = 3;
    int number;

    srand(time(0));

    number = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

    return number;
}

/**
    Obtains the player's choice

    @return choice The player's choice
*/

int getPlayerChoice() {
    int choice;

    cout << "Please enter your choice:\n"
         << "    1) Rock\n"
         << "    2) Paper\n"
         << "    3) Scissors\n"
         << "Choice: ";
    cin >> choice;

    while (choice < 1 || choice > 3) {
        cout << "Please enter either 1, 2, or 3 as your choice: ";
        cin >> choice;
    }

    return choice;
}

/**
    Displays the results of the rock, paper, scissors game

    @param player The player's choice
           opponenet The opponent's choice
*/

void displayResults(int player, int opponent) {
    
    cout << "--------------------------------\n"
         << "You: " << player << "        Opponent: " << opponent << endl
         << "--------------------------------\n";
    if (player == 1 && opponent == 3)
        cout << "Rock beats Scissors. You win!!!\n";
    else if (player == 3 && opponent == 1)
        cout << "Rock beats Scissors. You lose\n";
    else if (player == 3 && opponent == 2)
        cout << "Scissors beats Paper. You win!!!\n";
    else if (player == 2 && opponent == 3)
        cout << "Scissors beats Paper. You lose\n";
    else if (player == 2 && opponent == 1)
        cout << "Paper beats Rock. You win!!!\n";
    else if (player == 1 && opponent == 2)
        cout << "Paper beats Rock. You lose\n";
    else
        cout << "Tie!\n";
}
