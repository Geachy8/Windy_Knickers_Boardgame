#include "Windy_Knickers_Boardgame.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//Define functions

void greet() {

    std::cout << "=============\n";
    std::cout << "Hang your washing! Based on the family game 'windy Knickers' \n";
    std::cout << "=============\n";
    std::cout << "Instructions: Hang all your washing on the line.\n";


    cout << "========================== \n\n";
    cout << "    /   /   !   '\'   '\'      \n";
    cout << " ===========!==========    \n";
    cout << "    ||   +  !  +    ||       \n";
    cout << "    ||    + ! +     ||       \n";
    cout << "    (@)    +!+     (@)       \n";
    cout << "            !              \n";
    cout << "            !              \n";

    std::cout << "Welcome to Windy Knickers! The aim is to hang all 6 of your washing on the line.\n";
    std::cout << "Roll a die to determine the weather and see if you can hang your washing!\n\n";
}

int roll_die() {
    return std::rand() % 6 + 1;  // Simulates rolling a die (1-6)
}

std::string weather_outcome(int roll) {
    switch (roll) {
    case 1: return "Cloud";        // Miss a turn
    case 2: return "Rain Cloud";   // Remove one item of clothing
    case 3: return "Storm";        // Lose all clothing on the line
    default: return "Sunny";       // Hang one piece of clothing
    }
}

void hang_clothes(int& clothes, const std::string& outcome) {
    if (outcome == "Sunny") {
        if (clothes < CLOTHES_COUNT) {
            clothes++;
            std::cout << "You hang one item of clothing. You now have " << clothes << " on the line.\n";
        }
    }
    else if (outcome == "Rain Cloud") {
        if (clothes > 0) {
            clothes--;
            std::cout << "You take one item of clothing off. You now have " << clothes << " on the line.\n";
        }
    }
    else if (outcome == "Storm") {
        clothes = 0;
        std::cout << "A storm hit! All your clothes have fallen off the line.\n";
    }
    else {
        std::cout << "It's cloudy, you miss a turn.\n";
    }
}

bool check_winner(int clothes) {
    return clothes == CLOTHES_COUNT;
}

void display_status(int player_clothes, int computer_clothes) {
    std::cout << "Player: " << player_clothes << " items on the line.\n";
    std::cout << "Computer: " << computer_clothes << " items on the line.\n\n";
}

void player_turn(int& player_clothes) {
    std::cout << "Your turn! Press Enter to roll the die.\n";
    std::cin.ignore();  // Wait for the player to press Enter
    int roll = roll_die();
    std::string outcome = weather_outcome(roll);
    std::cout << "You rolled a " << roll << ": " << outcome << "\n";
    hang_clothes(player_clothes, outcome);
}

void computer_turn(int& computer_clothes) {
    std::cout << "Computer's turn...\n";
    int roll = roll_die();
    std::string outcome = weather_outcome(roll);
    std::cout << "Computer rolled a " << roll << ": " << outcome << "\n";
    hang_clothes(computer_clothes, outcome);
}
