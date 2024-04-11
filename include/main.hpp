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