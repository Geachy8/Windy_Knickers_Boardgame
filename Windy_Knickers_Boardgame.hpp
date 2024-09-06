#ifndef WINDY_KNICKERS_HPP
#define WINDY_KNICKERS_HPP

#include <string>

// Constants
const int CLOTHES_COUNT = 6; // Number of clothes each player needs to hang

// Function Declarations
void greet();  // Welcomes the player and explains the game rules
int roll_die();  // Simulates rolling a die
std::string weather_outcome(int roll);  // Returns weather based on the die roll
void hang_clothes(int& clothes, const std::string& outcome);  // Handles hanging and removing clothes
bool check_winner(int clothes);  // Checks if a player has won by hanging all their clothes
void display_status(int player_clothes, int computer_clothes);  // Displays the current game status
void player_turn(int& player_clothes);  // Handles the player's turn
void computer_turn(int& computer_clothes);  // Handles the computer's turn
void end_game(int& player_clothes, int& computer);
#endif
