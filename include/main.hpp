#ifndef MAIN_H
#define MAIN_H

#include <string>
#include "audiolibrary.hpp"


/*
    main.hpp
    Created: 
    Updated: 
*/


/**
 * @brief Clears the screen and displays a message.
 * @param message The message to be displayed.
 */
void clearScreen(const std::string& message);

/**
 * @brief Checks the number of command-line arguments and prompts the user for the filename.
 * @param argumentsCount Reference to the number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @param filename Reference to a string where the filename will be stored.
 * @return True if the number of arguments is valid or the user provided the filename, false otherwise.
 */
bool checkNumberOfArguments(int& argumentsCount, char* argv[], std::string& filename);

/**
 * @brief Displays the main menu with different options.
 */
void mainMenu();

/**
 * @brief Handles the user's choice from the main menu.
 * @param choice The user's choice.
 * @param library Reference to the AudioLibrary object.
 */
void userChoice(int choice, AudioLibrary& library);

#endif