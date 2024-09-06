// Windy_Knickers_Boardgame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Windy_Knickers_Boardgame.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));  // Seed the random number generator

    greet();

    int player_clothes = 0;
    int computer_clothes = 0;

    while (true) {
        // Player's turn
        player_turn(player_clothes);
        if (check_winner(player_clothes)) {
            std::cout << "Congratulations! You've hung all your washing and won the game!\n";
            break;
        }

        // Computer's turn
        computer_turn(computer_clothes);
        if (check_winner(computer_clothes)) {
            std::cout << "The computer hung all its washing and won the game!\n";
            break;
        }

        // Display the current status
        display_status(player_clothes, computer_clothes);
    }

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
