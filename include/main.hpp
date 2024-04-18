#ifndef MAIN_H
#define MAIN_H

// TODO: Remove Win32 specific code
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "audio-library.hpp"
#include "validation.hpp"

/*
    main.hpp
    Created:
    Updated:
*/

/**
 * @brief Ask the user to press Enter two times to go back to menu
 */
void enter();

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