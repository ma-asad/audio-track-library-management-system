#ifndef UTILS_H
#define UTILS_H

// TODO: Remove Win32 specific code
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
#include <limits>

#include "audio-library.hpp"

/**
 * @brief Exits the program.
 *
 * This function is responsible for exiting the program. It sets the value of
 * the stopProgram flag to true, indicating that the program should stop.
 *
 * @param stopProgram A pointer to a boolean flag indicating whether the program
 * should stop or not.
 */
void exitProgram(bool* stopProgram);

/**
 * Creates a new window with the specified title.
 *
 * @param windowTitle The title of the window.
 */
void newWindow(std::string windowTitle);

/**
 * @brief Function to get the search query from the user.
 *
 * @param searchType The type of search (e.g., title, artist, genre).
 * @return std::string The search query entered by the user.
 */
std::string getSearchQuery(std::string searchType);

/**
 * Displays the search menu and allows the user to select a search option.
 * Based on the selected option, it performs the corresponding search operation
 * on the given AudioLibrary object.
 *
 * @param library The AudioLibrary object on which the search operation will be
 * performed.
 */
void searchMenuSelector(AudioLibrary& library);

/**
 * Displays the main menu and handles user input to perform various actions
 * in the audio library.
 *
 * @param stopProgram A pointer to a boolean variable indicating whether the
 * program should stop.
 * @param library The AudioLibrary object representing the audio library.
 */
void mainMenuSelector(bool* stopProgram, AudioLibrary& library);

#endif
